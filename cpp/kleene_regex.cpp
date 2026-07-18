#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct NFA
{
    int states;
    int startState;
    set<int> finalStates;
    map<int, map<int, string>> transitions;
};

string unionRegex(const string &left, const string &right)
{
    if (left.empty())
    {
        return right;
    }
    if (right.empty() || left == right)
    {
        return left;
    }
    return "(" + left + "|" + right + ")";
}

bool needsParentheses(const string &expr)
{
    return expr.find('|') != string::npos;
}

string wrapIfNeeded(const string &expr)
{
    if (expr == "eps" || expr.size() == 1 || (expr.front() == '(' && expr.back() == ')'))
    {
        return expr;
    }
    return needsParentheses(expr) ? "(" + expr + ")" : expr;
}

string starRegex(const string &expr)
{
    if (expr.empty() || expr == "eps")
    {
        return "eps";
    }
    return wrapIfNeeded(expr) + "*";
}

string concatRegex(const vector<string> &parts)
{
    string result;
    for (const string &part : parts)
    {
        if (part.empty())
        {
            return "";
        }
        if (part == "eps")
        {
            continue;
        }
        result += wrapIfNeeded(part);
    }
    return result.empty() ? "eps" : result;
}

string nfaToRegex(const NFA &nfa)
{
    const int newStart = nfa.states;
    const int newFinal = nfa.states + 1;
    const int totalStates = nfa.states + 2;

    vector<vector<string>> regex(totalStates, vector<string>(totalStates, ""));

    for (map<int, map<int, string>>::const_iterator stateEntry = nfa.transitions.begin();
         stateEntry != nfa.transitions.end();
         ++stateEntry)
    {
        int from = stateEntry->first;
        const map<int, string> &edges = stateEntry->second;

        for (map<int, string>::const_iterator edge = edges.begin(); edge != edges.end(); ++edge)
        {
            int to = edge->first;
            const string &symbol = edge->second;
            regex[from][to] = unionRegex(regex[from][to], symbol);
        }
    }

    regex[newStart][nfa.startState] = "eps";
    for (int finalState : nfa.finalStates)
    {
        regex[finalState][newFinal] = unionRegex(regex[finalState][newFinal], "eps");
    }

    for (int k = 0; k < totalStates; k++)
    {
        if (k == newStart || k == newFinal)
        {
            continue;
        }

        for (int i = 0; i < totalStates; i++)
        {
            if (i == k || regex[i][k].empty())
            {
                continue;
            }

            for (int j = 0; j < totalStates; j++)
            {
                if (j == k || regex[k][j].empty())
                {
                    continue;
                }

                string viaK = concatRegex({regex[i][k], starRegex(regex[k][k]), regex[k][j]});
                regex[i][j] = unionRegex(regex[i][j], viaK);
            }
        }

        for (int i = 0; i < totalStates; i++)
        {
            regex[i][k].clear();
            regex[k][i].clear();
        }
    }

    return regex[newStart][newFinal].empty() ? "empty language" : regex[newStart][newFinal];
}

int main()
{
    NFA nfa;
    nfa.states = 9;
    nfa.startState = 0;
    nfa.finalStates = {8};
    nfa.transitions = {
        {0, {{1, "eps"}, {7, "eps"}}},
        {1, {{2, "a"}}},
        {2, {{3, "eps"}}},
        {3, {{4, "b"}}},
        {4, {{1, "eps"}, {5, "eps"}}},
        {5, {{6, "c"}}},
        {6, {{7, "eps"}}},
        {7, {{8, "d"}}}};

    cout << "Regular expression: " << nfaToRegex(nfa) << "\n";

    return 0;
}
