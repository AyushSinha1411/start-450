/*
QUESTION:
Given a graph with V vertices, find all the nodes that are eventually safe. A node is considered safe if and only if every possible path starting from that node leads to a terminal node (a node with no outgoing edges).

APPROACH:
1. Reverse the edges of the graph to form a new graph where each edge direction is reversed.
2. Compute the in-degrees of all nodes in the reversed graph.
3. Use a queue to perform a BFS starting from nodes with in-degree 0 in the reversed graph (these are terminal nodes in the original graph).
4. For each node processed, reduce the in-degree of its neighbors and add neighbors with in-degree 0 to the queue.
5. Collect all nodes processed during the BFS as they are safe nodes.
6. Sort the list of safe nodes before returning.

CODE:
*/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // Reverse the edges of the graph
        vector<int> adjRev[V];
        int indegree[V] = {0};

        // Create the reversed graph and compute in-degrees
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        // Queue for BFS
        queue<int> q;
        vector<int> safeNodes;

        // Initialize the queue with nodes having 0 in-degree
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Sort the safe nodes
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

/*
EXAMPLE USAGE:
int V = 7;
vector<int> adj[V] = {
    {1, 2}, // 0
    {2, 3}, // 1
    {5},    // 2
    {0},    // 3
    {5},    // 4
    {6},    // 5
    {}      // 6
};
Solution sol;
vector<int> safeNodes = sol.eventualSafeNodes(V, adj);
// Output: [2, 4, 5, 6] (or any valid order after sorting)

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices and E is the number of edges. Each vertex and edge is processed once.

SPACE COMPLEXITY:
- O(V + E), for storing the reversed graph and in-degrees.
*/
