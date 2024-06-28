/*
QUESTION:
Given a directed graph, determine whether it contains a cycle. 

EXAMPLE:
Input:
V = 4
Edges: [[0, 1], [1, 2], [2, 3], [3, 1]]

Output: true

APPROACH:
1. Use DFS to traverse the graph.
2. Track nodes in the current path to detect back edges.
3. If a back edge is found, the graph contains a cycle.

CODE:
*/

#include <vector>
using namespace std;

class Solution {
private:
    // DFS function to check for cycles
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
        // Mark the current node as visited and part of the current path
        vis[node] = 1;
        pathVis[node] = 1;

        // Traverse adjacent nodes
        for (auto it : adj[node]) {
            // If the adjacent node is not visited
            if (!vis[it]) {
                // Recursively call DFS
                if (dfsCheck(it, adj, vis, pathVis) == true)
                    return true;
            }
            // If the adjacent node is part of the current path, a cycle is found
            else if (pathVis[it]) {
                return true;
            }
        }

        // Mark the current node as not part of the current path
        pathVis[node] = 0;
        return false;
    }
public:
    // Function to detect cycle in a directed graph
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};

        // Check all components of the graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                // Start DFS from unvisited node
                if (dfsCheck(i, adj, vis, pathVis) == true) 
                    return true;
            }
        }
        // If no cycle is found, return false
        return false;
    }
};

/*
EXAMPLE USAGE:
int V = 4;
vector<int> adj[V];
adj[0].push_back(1);
adj[1].push_back(2);
adj[2].push_back(3);
adj[3].push_back(1);

Solution sol;
bool result = sol.isCyclic(V, adj);
// Output: true

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices and E is the number of edges. Each node and edge is visited once.

SPACE COMPLEXITY:
- O(V), for the vis and pathVis arrays and recursion stack in DFS.
*/
