/*
QUESTION:
Given an undirected graph represented by an adjacency list and a starting node (source), find the shortest path from the source node to all other nodes in the graph.

APPROACH:
1. Build an adjacency list from the given edges.
2. Use Breadth-First Search (BFS) to find the shortest path from the source to all other nodes.
3. Initialize a distance array with a large number to indicate that initially, all nodes are untraversed.
4. Start BFS from the source node and update the distances of its neighbors.
5. If a node is unreachable from the source, mark its distance as -1.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        // Create an adjacency list of size N for storing the undirected graph
        vector<int> adj[N];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Initialize a distance array with a large number to indicate untraversed nodes
        int dist[N];
        for (int i = 0; i < N; i++) dist[i] = 1e9;

        // BFS Implementation
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }

        // Updated shortest distances are stored in the resultant array ‘ans’
        // Unreachable nodes are marked as -1
        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++) {
            if (dist[i] != 1e9) {
                ans[i] = dist[i];
            }
        }
        return ans;
    }
};

/*
EXAMPLE USAGE:
vector<vector<int>> edges = {{0,1},{0,2},{1,2},{1,3}};
int N = 4, M = 4, src = 0;
Solution sol;
vector<int> result = sol.shortestPath(edges, N, M, src);
// Output: [0, 1, 1, 2]

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices (nodes) and E is the number of edges.
- Each vertex and edge is processed once in the BFS traversal.

SPACE COMPLEXITY:
- O(V + E), for storing the adjacency list and other auxiliary structures.
*/
