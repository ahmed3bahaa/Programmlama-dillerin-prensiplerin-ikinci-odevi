#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct DFA
{
    int states;
    int startState;
    set<int> finalStates;
    map<int, map<char, int>> transitions;
};

set<int> findReachableStates(const DFA &dfa)
{
    set<int> reachable;
    queue<int> statesToVisit;

    reachable.insert(dfa.startState);
    statesToVisit.push(dfa.startState);

    while (!statesToVisit.empty())
    {
        int state = statesToVisit.front();
        statesToVisit.pop();

        auto transitionsForState = dfa.transitions.find(state);
        if (transitionsForState == dfa.transitions.end())
        {
            continue;
        }

        for (map<char, int>::const_iterator transition = transitionsForState->second.begin();
             transition != transitionsForState->second.end();
             ++transition)
        {
            int nextState = transition->second;
            if (!reachable.count(nextState))
            {
                reachable.insert(nextState);
                statesToVisit.push(nextState);
            }
        }
    }

    return reachable;
}

set<char> collectAlphabet(const DFA &dfa)
{
    set<char> alphabet;
    for (map<int, map<char, int>>::const_iterator stateEntry = dfa.transitions.begin();
         stateEntry != dfa.transitions.end();
         ++stateEntry)
    {
        const map<char, int> &transitionsForState = stateEntry->second;
        for (map<char, int>::const_iterator transition = transitionsForState.begin();
             transition != transitionsForState.end();
             ++transition)
        {
            alphabet.insert(transition->first);
        }
    }
    return alphabet;
}

int partitionIndexForState(const vector<set<int>> &partitions, int state)
{
    for (int i = 0; i < static_cast<int>(partitions.size()); i++)
    {
        if (partitions[i].count(state))
        {
            return i;
        }
    }
    return -1;
}

DFA minimizeDFA(const DFA &dfa)
{
    set<int> reachableStates = findReachableStates(dfa);
    set<char> alphabet = collectAlphabet(dfa);

    set<int> reachableFinalStates;
    set<int> reachableNonFinalStates;

    for (int state : reachableStates)
    {
        if (dfa.finalStates.count(state))
        {
            reachableFinalStates.insert(state);
        }
        else
        {
            reachableNonFinalStates.insert(state);
        }
    }

    vector<set<int>> partitions;
    if (!reachableFinalStates.empty())
    {
        partitions.push_back(reachableFinalStates);
    }
    if (!reachableNonFinalStates.empty())
    {
        partitions.push_back(reachableNonFinalStates);
    }

    bool changed = true;
    while (changed)
    {
        changed = false;
        vector<set<int>> refinedPartitions;

        for (const set<int> &partition : partitions)
        {
            map<vector<int>, set<int>> groups;

            for (int state : partition)
            {
                vector<int> signature;
                auto transitionsForState = dfa.transitions.find(state);

                for (char symbol : alphabet)
                {
                    int targetPartition = -1;
                    if (transitionsForState != dfa.transitions.end())
                    {
                        auto transition = transitionsForState->second.find(symbol);
                        if (transition != transitionsForState->second.end())
                        {
                            targetPartition = partitionIndexForState(partitions, transition->second);
                        }
                    }
                    signature.push_back(targetPartition);
                }

                groups[signature].insert(state);
            }

            if (groups.size() > 1)
            {
                changed = true;
            }

            for (map<vector<int>, set<int>>::const_iterator groupEntry = groups.begin();
                 groupEntry != groups.end();
                 ++groupEntry)
            {
                refinedPartitions.push_back(groupEntry->second);
            }
        }

        partitions = refinedPartitions;
    }

    map<int, int> stateMapping;
    for (int i = 0; i < static_cast<int>(partitions.size()); i++)
    {
        for (int state : partitions[i])
        {
            stateMapping[state] = i;
        }
    }

    DFA minimizedDFA;
    minimizedDFA.states = static_cast<int>(partitions.size());
    minimizedDFA.startState = stateMapping[dfa.startState];

    for (int finalState : dfa.finalStates)
    {
        if (reachableStates.count(finalState))
        {
            minimizedDFA.finalStates.insert(stateMapping[finalState]);
        }
    }

    for (int i = 0; i < static_cast<int>(partitions.size()); i++)
    {
        int representative = *partitions[i].begin();
        auto transitionsForState = dfa.transitions.find(representative);
        if (transitionsForState == dfa.transitions.end())
        {
            continue;
        }

        for (map<char, int>::const_iterator transition = transitionsForState->second.begin();
             transition != transitionsForState->second.end();
             ++transition)
        {
            char symbol = transition->first;
            int nextState = transition->second;
            if (reachableStates.count(nextState))
            {
                minimizedDFA.transitions[i][symbol] = stateMapping[nextState];
            }
        }
    }

    return minimizedDFA;
}

void printDFA(const DFA &dfa)
{
    cout << "Minimized DFA has " << dfa.states << " states.\n";
    cout << "Start State: " << dfa.startState << "\n";

    cout << "Final States: ";
    for (int state : dfa.finalStates)
    {
        cout << state << " ";
    }
    cout << "\n";

    cout << "Transitions:\n";
    for (map<int, map<char, int>>::const_iterator stateEntry = dfa.transitions.begin();
         stateEntry != dfa.transitions.end();
         ++stateEntry)
    {
        int state = stateEntry->first;
        const map<char, int> &transitionsForState = stateEntry->second;

        for (map<char, int>::const_iterator transition = transitionsForState.begin();
             transition != transitionsForState.end();
             ++transition)
        {
            char symbol = transition->first;
            int nextState = transition->second;
            cout << state << " --" << symbol << "--> " << nextState << "\n";
        }
    }
}

int main()
{
    DFA dfa;
    dfa.states = 5;
    dfa.startState = 0;
    dfa.finalStates = {1, 3};
    dfa.transitions = {
        {0, {{'a', 1}, {'b', 2}}},
        {1, {{'a', 1}, {'b', 3}}},
        {2, {{'a', 4}, {'b', 2}}},
        {3, {{'a', 1}, {'b', 3}}},
        {4, {{'a', 4}, {'b', 2}}}};

    DFA minimizedDFA = minimizeDFA(dfa);
    printDFA(minimizedDFA);

    return 0;
}
