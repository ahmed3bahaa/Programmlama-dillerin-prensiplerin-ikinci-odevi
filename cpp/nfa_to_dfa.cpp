#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

// Epsilon closure computation
set<int> epsilonClosure(int state, const map<int, vector<pair<char, int>>> &transitions)
{
    set<int> closure;
    queue<int> q;

    q.push(state);
    closure.insert(state);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (transitions.find(curr) != transitions.end())
        {
            for (const auto &transition : transitions.at(curr))
            {
                char symbol = transition.first;
                int nextState = transition.second;

                if (symbol == 'e' && closure.find(nextState) == closure.end())
                {
                    closure.insert(nextState);
                    q.push(nextState);
                }
            }
        }
    }
    return closure;
}

// NFA to DFA conversion
void nfaToDfa(const map<int, vector<pair<char, int>>> &nfaTransitions, int startState, const set<int> &finalStates, set<char> symbols)
{
    map<set<int>, map<char, set<int>>> dfaTransitions;
    set<set<int>> dfaStates;
    set<set<int>> dfaFinalStates;

    set<int> startClosure = epsilonClosure(startState, nfaTransitions);
    queue<set<int>> q;
    q.push(startClosure);
    dfaStates.insert(startClosure);

    while (!q.empty())
    {
        set<int> currentStateSet = q.front();
        q.pop();

        for (char symbol : symbols)
        {
            set<int> nextStateSet;

            for (int state : currentStateSet)
            {
                if (nfaTransitions.find(state) != nfaTransitions.end())
                {
                    for (const auto &transition : nfaTransitions.at(state))
                    {
                        char transSymbol = transition.first;
                        int nextState = transition.second;

                        if (transSymbol == symbol)
                        {
                            set<int> nextClosure = epsilonClosure(nextState, nfaTransitions);
                            nextStateSet.insert(nextClosure.begin(), nextClosure.end());
                        }
                    }
                }
            }

            if (!nextStateSet.empty() && dfaStates.find(nextStateSet) == dfaStates.end())
            {
                dfaStates.insert(nextStateSet);
                q.push(nextStateSet);
            }

            dfaTransitions[currentStateSet][symbol] = nextStateSet;
        }
    }

    // Determine final states
    for (const auto &stateSet : dfaStates)
    {
        for (int state : stateSet)
        {
            if (finalStates.find(state) != finalStates.end())
            {
                dfaFinalStates.insert(stateSet);
                break;
            }
        }
    }

    // Print DFA states
    cout << "DFA States:\n";
    for (const auto &stateSet : dfaStates)
    {
        cout << "{ ";
        for (int state : stateSet)
        {
            cout << state << " ";
        }
        cout << "} ";
    }
    cout << "\n\nDFA Transitions:\n";
    for (const auto &transition : dfaTransitions)
    {
        const auto &stateSet = transition.first;
        const auto &trans = transition.second;

        cout << "{ ";
        for (int state : stateSet)
        {
            cout << state << " ";
        }
        cout << "} -> ";
        for (const auto &transPair : trans)
        {
            char symbol = transPair.first;
            const auto &nextStateSet = transPair.second;

            cout << symbol << " -> { ";
            for (int state : nextStateSet)
            {
                cout << state << " ";
            }
            cout << "}  ";
        }
        cout << "\n";
    }

    // Print DFA final states
    cout << "\nDFA Final States:\n";
    for (const auto &stateSet : dfaFinalStates)
    {
        cout << "{ ";
        for (int state : stateSet)
        {
            cout << state << " ";
        }
        cout << "} ";
    }
    cout << endl;
}

int main()
{
    map<int, vector<pair<char, int>>> nfaTransitions = {
        {0, {{'e', 1}, {'e', 7}}},
        {1, {{'a', 2}}},
        {2, {{'e', 3}}},
        {3, {{'b', 4}}},
        {4, {{'e', 1}, {'e', 5}}},
        {5, {{'c', 6}}},
        {6, {{'e', 7}}},
        {7, {{'d', 8}}}};

    int startState = 0;
    set<int> finalStates = {8};
    set<char> symbols = {'a', 'b', 'c', 'd'};

    nfaToDfa(nfaTransitions, startState, finalStates, symbols);

    return 0;
}
