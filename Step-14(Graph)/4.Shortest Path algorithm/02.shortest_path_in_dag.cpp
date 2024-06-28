/*
QUESTION:
Given a Directed Acyclic Graph (DAG) with N vertices and M edges, where each edge has a weight, find the shortest path from the source vertex (vertex 0) to all other vertices.

APPROACH:
1. Build an adjacency list from the given edges.
2. Perform topological sort using Depth-First Search (DFS).
3. Use the topological order to find the shortest path from the source vertex to all other vertices by relaxing the edges.

CODE:
*/

#include <vector>
#include <stack>
#include <utility>
using namespace std;

class Solution {
private:
    // Function to perform Topological Sort
    void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    // Function to find the shortest path in a DAG
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        // Create the adjacency list representation of the graph
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // Initialize visited array
        int vis[N] = {0};

        // Perform topological sort using DFS
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // Initialize distance vector with a large number to indicate untraversed nodes
        vector<int> dist(N, 1e9);
        dist[0] = 0;

        // Process nodes in topological order to find shortest paths
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;

                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Replace distances that are still 1e9 with -1 to indicate unreachable nodes
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};

/*
EXAMPLE USAGE:
vector<vector<int>> edges = {{0,1,2},{0,2,1},{1,2,3},{2,3,6}};
int N = 4, M = 4;
Solution sol;
vector<int> result = sol.shortestPath(N, M, edges);
// Output: [0, 2, 1, 7]

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices (nodes) and E is the number of edges.
- Each vertex and edge is processed once during the topological sort and the shortest path calculation.

SPACE COMPLEXITY:
- O(V + E), for storing the adjacency list and other auxiliary structures.
*/
