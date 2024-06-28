/*
QUESTION:
Given an undirected graph, find all articulation points. An articulation point (or cut vertex) is a vertex which, when removed along with its edges, makes the graph disconnected or increases the number of connected components.

APPROACH:
1. Use Depth-First Search (DFS) to traverse the graph.
2. Maintain two arrays: tin[] to store the time of the first visit of a node and low[] to store the lowest time reachable from the node.
3. Use a mark[] array to indicate articulation points.
4. During DFS traversal, update the low[] values based on adjacent nodes.
5. If for any adjacent node, the low value is greater than or equal to the discovery time of the current node and the current node is not the root, it is an articulation point.
6. If the current node is the root and has more than one child, it is an articulation point.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int timer = 1;

    // DFS function to find articulation points
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
             vector<int> &mark, vector<int> adj[]) {
        vis[node] = 1; // Mark the current node as visited
        tin[node] = low[node] = timer++; // Initialize discovery and low times

        int child = 0; // Count of child nodes
        for (auto it : adj[node]) {
            if (it == parent) continue; // Ignore the edge to the parent node
            if (!vis[it]) {
                // If the adjacent node is not visited, perform DFS on it
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]); // Update the low value of the current node

                // Check if the current node is an articulation point
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            } else {
                // If the adjacent node is already visited, update the low value of the current node
                low[node] = min(low[node], tin[it]);
            }
        }
        // If the current node is the root and has more than one child, it is an articulation point
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

public:
    // Function to find all articulation points in the graph
    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<int> vis(n, 0); // Visited array
        int tin[n]; // Discovery times array
        int low[n]; // Low values array
        vector<int> mark(n, 0); // Array to mark articulation points

        // Perform DFS to find articulation points
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }

        vector<int> ans; // Vector to store articulation points
        for (int i = 0; i < n; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }

        // If no articulation points are found, return {-1}
        if (ans.empty()) return {-1};
        return ans;
    }
};

/*
TIME COMPLEXITY:
- O(N + E), where N is the number of nodes and E is the number of edges. Each node and edge is processed once.

SPACE COMPLEXITY:
- O(N + E), for storing the adjacency list and additional arrays for DFS traversal.

EXAMPLE USAGE:
Solution sol;
int n = 5;
vector<int> adj[n] = {
    {1, 2},
    {0, 2},
    {0, 1, 3, 4},
    {2, 4},
    {2, 3}
};
vector<int> result = sol.articulationPoints(n, adj);
// result will contain the articulation points in the network.
*/
