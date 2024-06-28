/*
QUESTION:
Problem Statement: There are n servers numbered from 0 to n - 1 connected by undirected server-to-server 
connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi.
Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other servers.
Return all critical connections in the network in any order.

APPROACH:
1. Use Depth-First Search (DFS) to traverse the graph.
2. Maintain two arrays: tin[] to store the time of the first visit of a node and low[] to store the lowest time reachable from the node.
3. During DFS traversal, for each node, update the low[] value based on the adjacent nodes.
4. If the low value of an adjacent node is greater than the tin value of the current node, it indicates a bridge.
5. Store all such bridges found during traversal.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int timer = 1; // Timer to keep track of discovery times

    // DFS function to find bridges
    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges) {
        vis[node] = 1; // Mark the current node as visited
        tin[node] = low[node] = timer++; // Initialize discovery and low times

        for (auto it : adj[node]) {
            if (it == parent) continue; // Ignore the edge to the parent node
            if (vis[it] == 0) {
                // If the adjacent node is not visited, perform DFS on it
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[node], low[it]); // Update the low value of the current node

                // Check if the edge is a bridge
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            } else {
                // If the adjacent node is already visited, update the low value of the current node
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    // Function to find all critical connections in the network
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n]; // Adjacency list

        // Build the adjacency list
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0); // Visited array
        int tin[n]; // Discovery times array
        int low[n]; // Low values array
        vector<vector<int>> bridges; // Store the bridges

        // Perform DFS to find bridges
        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
};

/*
TIME COMPLEXITY:
- O(N + E), where N is the number of nodes and E is the number of edges. Each node and edge is processed once.

SPACE COMPLEXITY:
- O(N + E), for storing the adjacency list and additional arrays for DFS traversal.

EXAMPLE USAGE:
Solution sol;
int n = 4;
vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
vector<vector<int>> result = sol.criticalConnections(n, connections);
// result will contain the critical connections (bridges) in the network.
*/
