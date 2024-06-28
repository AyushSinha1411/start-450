/*
QUESTION:
Given a dictionary of words from an alien language, where the words are sorted lexicographically by the rules of this alien language, find the order of characters in the alien language.

APPROACH:
1. Build a graph where each character is a node and there is a directed edge from character u to character v if character u appears before v in some word in the dictionary.
2. Perform a topological sort on the graph to get the order of characters.
3. Use Kahn's algorithm (BFS) for topological sorting to get the lexicographical order.

CODE:
*/

#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    // Function to perform topological sort using Kahn's Algorithm (BFS)
    vector<int> topoSort(int V, vector<int> adj[]) {
        int indegree[V] = {0};
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }

public:
    // Function to find the order of characters in the alien language
    string findOrder(string dict[], int N, int K) {
        // Create adjacency list
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        // Perform topological sort
        vector<int> topo = topoSort(K, adj);
        string ans = "";
        for (auto it : topo) {
            ans += char(it + 'a');
        }
        return ans;
    }
};

/*
EXAMPLE USAGE:
int N = 5, K = 4;
string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
Solution sol;
string order = sol.findOrder(dict, N, K);
// Output: "bdac" (or any other valid order)

TIME COMPLEXITY:
- O(V + E), where V is the number of characters (K) and E is the number of edges (derived from the dictionary). Each vertex and edge is processed once.

SPACE COMPLEXITY:
- O(V + E), for storing the adjacency list and other auxiliary structures.
*/
