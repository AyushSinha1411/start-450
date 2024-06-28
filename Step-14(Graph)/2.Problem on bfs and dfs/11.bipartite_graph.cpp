/*
QUESTION:
Given an undirected graph, determine whether it is bipartite. A bipartite graph is a graph whose vertices can be divided into two disjoint and independent sets U and V such that every edge connects a vertex in U to one in V.

EXAMPLE:
Input:
V = 4
Edges: [[0, 1], [1, 2], [2, 3], [3, 0]]

Output: false

APPROACH:
1. Use DFS to traverse the graph.
2. Assign colors to nodes to check if the graph can be divided into two sets.
3. If two adjacent nodes have the same color, the graph is not bipartite.

CODE:
*/

#include <vector>
using namespace std;

class Solution {
private:
    // DFS function to check for bipartiteness
    bool dfs(int node, int col, int color[], vector<int> adj[]) {
        // Color the current node
        color[node] = col; 
        
        // Traverse adjacent nodes
        for (auto it : adj[node]) {
            // If the adjacent node is uncolored
            if (color[it] == -1) {
                // Recursively call DFS with alternate color
                if (dfs(it, !col, color, adj) == false) return false;
            }
            // If the adjacent node has the same color, return false
            else if (color[it] == col) {
                return false;
            }
        }
        
        // If no conflicts, return true
        return true;
    }
public:
    // Function to check if the graph is bipartite
    bool isBipartite(int V, vector<int> adj[]) {
        int color[V];
        // Initialize all nodes as uncolored
        for (int i = 0; i < V; i++) color[i] = -1; 
        
        // Check all components of the graph
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                // Start DFS from uncolored node
                if (dfs(i, 0, color, adj) == false) 
                    return false; 
            }
        }
        // If no conflicts, the graph is bipartite
        return true; 
    }
};

/*
EXAMPLE USAGE:
int V = 4;
vector<int> adj[V];
adj[0] = {1, 3};
adj[1] = {0, 2};
adj[2] = {1, 3};
adj[3] = {0, 2};

Solution sol;
bool result = sol.isBipartite(V, adj);
// Output: true

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices and E is the number of edges. Each node and edge is visited once.

SPACE COMPLEXITY:
- O(V), for the color array and recursion stack in DFS.
*/
