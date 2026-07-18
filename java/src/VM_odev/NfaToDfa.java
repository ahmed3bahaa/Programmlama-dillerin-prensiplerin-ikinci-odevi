package VM_odev; 
// Bu sınıfın "VM_odev" isimli bir pakete ait olduğunu belirtir.

import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.TreeSet;

public class NfaToDfa {
    
  
    public static Set<Integer> epsilonClosure(
            int state, 
            Map<Integer, List<AbstractMap.SimpleEntry<Character, Integer>>> transitions
    ) {
        
        Set<Integer> closure = new TreeSet<>();
        // closure: Bulunan tüm durumları tutan küme.
        
        Queue<Integer> queue = new LinkedList<>();
        // queue: Eklenecek ve kontrol edilecek durumları tutan kuyruk yapısı.
        
        closure.add(state);
        // İlk olarak parametre olarak gelen durumu küme ve kuyruğa ekliyoruz.
        
        queue.add(state);
        // Kuyruğa ekledik, böylece while döngüsü içerisinde işlenecek.
        
        while (!queue.isEmpty()) {
            // Kuyruk boş olmadığı sürece devam et.
            int current = queue.poll();
            // Kuyruğun başındaki elemanı (durumu) çekip current değişkenine atıyoruz.
            
            // current durumu için herhangi bir geçiş tanımlanmış mı diye kontrol ediyoruz.
            if (transitions.containsKey(current)) {
                // transitions.get(current): current durumuna ait tüm (sembol, sonrakiDurum) çiftlerini döndürür.
                for (AbstractMap.SimpleEntry<Character, Integer> edge : transitions.get(current)) {
                    // edge: (sembol, sonrakiDurum) çiftini tutan yapı
                    char symbol = edge.getKey();
                    int nextState = edge.getValue();
                    
                    // Eğer sembol 'e' (epsilon) ve nextState daha önce closure'a eklenmemişse...
                    if (symbol == 'e' && !closure.contains(nextState)) {
                        closure.add(nextState);
                        queue.add(nextState);
                        // Böylece o duruma da epsilon geçişiyle ulaşılabileceğini gösterip,
                        // işlem kuyruğumuza ekliyoruz.
                    }
                }
            }
        }
        
        return closure;
        // closure kümesi, girilen durumdan yalnızca epsilon geçişleriyle erişilebilen tüm durumları içerir.
    }
    
   
    public static void nfaToDfa(
            Map<Integer, List<AbstractMap.SimpleEntry<Character, Integer>>> nfaTransitions,
            int startState,
            Set<Integer> finalStates,
            Set<Character> symbols
    ) {
        // dfaTransitions: Her bir (NFA durum kümesi) için,
        //   hangi sembolde hangi yeni (NFA durum kümesine) gidileceğini tutar.
        Map<Set<Integer>, Map<Character, Set<Integer>>> dfaTransitions = new LinkedHashMap<>();
        
        // dfaStates: Bulduğumuz tüm DFA durumlarını (yani NFA durum kümelerini) tutar.
        Set<Set<Integer>> dfaStates = new LinkedHashSet<>();
        
        // dfaFinalStates: DFA'nın son durumlarını tutan küme.
        Set<Set<Integer>> dfaFinalStates = new LinkedHashSet<>();
        
        // 1. Başlangıç durumunun epsilon-kapanışını alarak ilk DFA durumunu elde ederiz.
        Set<Integer> startClosure = epsilonClosure(startState, nfaTransitions);
        
        // 2. BFS yaklaşımıyla tüm olası DFA durumlarını keşfetmek için bir kuyruk kullanıyoruz.
        Queue<Set<Integer>> queue = new LinkedList<>();
        queue.add(startClosure);
        dfaStates.add(startClosure);
        
        // Kuyruk boşalıncaya kadar tüm durum kümelerini işleme alıyoruz.
        while (!queue.isEmpty()) {
            // currentStateSet: Şu anda işlenecek olan NFA durumlarının kümesi (DFA'da tek bir durum olarak düşünülüyor).
            Set<Integer> currentStateSet = queue.poll();
            
            // Her sembol için (epsilon dışı) yeni durum kümesini hesapla
            for (char symbol : symbols) {
                Set<Integer> nextStateSet = new TreeSet<>();
                
                // currentStateSet içindeki her bir NFA durumunu dolaş.
                for (int state : currentStateSet) {
                    
                    // Eğer bu durumun tanımlı geçişleri varsa...
                    if (nfaTransitions.containsKey(state)) {
                        // Tüm (sembol, sonrakiDurum) çiftlerini incele
                        for (AbstractMap.SimpleEntry<Character, Integer> edge : nfaTransitions.get(state)) {
                            char transSymbol = edge.getKey();
                            int nextState = edge.getValue();
                            
                            // Eğer transSymbol, üzerinde döndüğümüz sembole (symbol) eşitse,
                            // o sonraki duruma ait epsilon-kapanışını hesaplayıp nextStateSet'e ekle.
                            if (transSymbol == symbol) {
                                Set<Integer> closure = epsilonClosure(nextState, nfaTransitions);
                                nextStateSet.addAll(closure);
                            }
                        }
                    }
                }
                
                // Eğer oluşan nextStateSet (yani yeni DFA durumu) boş değilse ve daha önce görmediğimiz bir kümeyse,
                // onu yeni bir DFA durumu olarak ekle.
                if (!nextStateSet.isEmpty() && !dfaStates.contains(nextStateSet)) {
                    dfaStates.add(nextStateSet);
                    queue.add(nextStateSet);
                }
                
                // dfaTransitions yapısına, currentStateSet durumundan symbol sembolüyle nextStateSet kümesine geçişi kaydet.
                dfaTransitions
                    .computeIfAbsent(currentStateSet, k -> new LinkedHashMap<>())
                    .put(symbol, nextStateSet);
            }
        }
        
        // 3. DFA'nın son durumları: 
        // Eğer herhangi bir NFA son durumunu içeren bir durum kümesi varsa, o küme DFA'da son durum olarak işaretlenir.
        for (Set<Integer> stateSet : dfaStates) {
            for (int s : stateSet) {
                // stateSet içindeki bir NFA durumu, NFA'nın finalStates kümesindeyse, bu küme DFA'da final olur.
                if (finalStates.contains(s)) {
                    dfaFinalStates.add(stateSet);
                    break;
                }
            }
        }
        
        // 4. Son olarak, oluşan DFA'yı ekrana yazdırıyoruz.
        printDfa(dfaStates, dfaTransitions, dfaFinalStates);
    }
    
    /**
     * Dönüşen DFA'yı (durumlar, geçişler ve son durumlar) yazdıran yardımcı metod.
     */
    private static void printDfa(
            Set<Set<Integer>> dfaStates,
            Map<Set<Integer>, Map<Character, Set<Integer>>> dfaTransitions,
            Set<Set<Integer>> dfaFinalStates
    ) {
        // 1. Tüm DFA durumlarını yazdır.
        System.out.println("DFA States:");
        for (Set<Integer> stateSet : dfaStates) {
            System.out.print(setToString(stateSet) + " ");
        }
        System.out.println("\n");
        
        // 2. DFA geçişlerini yazdır.
        System.out.println("DFA Transitions:");
        for (Set<Integer> fromState : dfaTransitions.keySet()) {
            // fromState: Kaynak durum (bir NFA durum kümesi).
            System.out.print(setToString(fromState) + " -> ");
            
            // fromState durumunun sembollere göre gideceği durum kümeleri:
            Map<Character, Set<Integer>> edges = dfaTransitions.get(fromState);
            for (Map.Entry<Character, Set<Integer>> edge : edges.entrySet()) {
                char symbol = edge.getKey();
                Set<Integer> toStateSet = edge.getValue();
                System.out.print(symbol + " -> " + setToString(toStateSet) + "  ");
            }
            System.out.println();
        }
        System.out.println();
        
        // 3. DFA final (son) durumlarını yazdır.
        System.out.println("DFA Final States:");
        for (Set<Integer> finalSet : dfaFinalStates) {
            System.out.print(setToString(finalSet) + " ");
        }
        System.out.println();
    }
    
    /**
     * Bir kümenin "{ 1 2 3 }" formatında yazılabilmesi için yardımcı metod.
     */
    private static String setToString(Set<Integer> set) {
        StringBuilder sb = new StringBuilder();
        sb.append("{ ");
        for (int s : set) {
            sb.append(s).append(" ");
        }
        sb.append("}");
        return sb.toString();
    }
    
    /**
     * Uygulamayı başlatan main metodu.
     */
    public static void main(String[] args) {
        
        // NFA geçişlerini tutacak bir map oluşturuyoruz.
        // Burada 'e' karakterini epsilon olarak kullanacağız.
        Map<Integer, List<AbstractMap.SimpleEntry<Character, Integer>>> nfaTransitions = new LinkedHashMap<>();
        
        // Aşağıdaki yardımcı metodla nfaTransitions map'ine geçişleri ekliyoruz.
        insertTransition(nfaTransitions, 0, 'e', 1);
        insertTransition(nfaTransitions, 0, 'e', 7);
        insertTransition(nfaTransitions, 1, 'a', 2);
        insertTransition(nfaTransitions, 2, 'e', 3);
        insertTransition(nfaTransitions, 3, 'b', 4);
        insertTransition(nfaTransitions, 4, 'e', 1);
        insertTransition(nfaTransitions, 4, 'e', 5);
        insertTransition(nfaTransitions, 5, 'c', 6);
        insertTransition(nfaTransitions, 6, 'e', 7);
        insertTransition(nfaTransitions, 7, 'd', 8);
        
        // NFA başlangıç durumu
        int startState = 0;
        
        // NFA son durumlarının kümesi
        Set<Integer> finalStates = new TreeSet<>();
        finalStates.add(8);
        
        // Epsilon dışındaki giriş sembolleri (a, b, c, d)
        Set<Character> symbols = new LinkedHashSet<>(Arrays.asList('a', 'b', 'c', 'd'));
        
        // nfaToDfa metodu çağrılarak, NFA -> DFA dönüşümünü gerçekleştiriyoruz.
        nfaToDfa(nfaTransitions, startState, finalStates, symbols);
    }
    
    /**
     * Bir kaynaktan bir hedef duruma (symbol -> toState) geçişi eklemek için kullanılan yardımcı metod.
     */
    private static void insertTransition(
            Map<Integer, List<AbstractMap.SimpleEntry<Character, Integer>>> transitions,
            int fromState,
            char symbol,
            int toState
    ) {
        // Eğer fromState daha önce eklenmemişse, boş bir liste oluşturuyoruz.
        transitions.putIfAbsent(fromState, new ArrayList<>());
        
        // (symbol, toState) çiftini listeye ekliyoruz.
        transitions.get(fromState).add(new AbstractMap.SimpleEntry<>(symbol, toState));
    }
}
