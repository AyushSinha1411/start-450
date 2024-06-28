/*
QUESTION:
Given an adjacency matrix representation of an undirected graph, find the number of provinces. A province is a group of directly or indirectly connected cities and no other cities outside of the group.

EXAMPLE:
Input:
V = 3
adj = {
    {1, 0, 1},
    {0, 1, 0},
    {1, 0, 1}
}
Output:
2

APPROACH:
1. Convert the adjacency matrix to an adjacency list.
2. Use a DFS approach to count the number of connected components (provinces).
3. Initialize a visited array to keep track of visited nodes.
4. Traverse all nodes, and for each unvisited node, perform a DFS to mark all reachable nodes.
5. Count the number of DFS calls, which gives the number of provinces.

CODE:
*/

#include <vector>
using namespace std;

private:
    // Helper function to perform DFS traversal
    void dfs(int node, vector<int> adjLs[], int vis[]) {
        // Mark the current node as visited
        vis[node] = 1; 
        // Traverse all its neighbors
        for (auto it : adjLs[node]) {
            // If the neighbor is not visited
            if (!vis[it]) {
                // Recursively perform DFS on the neighbor
                dfs(it, adjLs, vis); 
            }
        }
    }

public:
    // Function to find the number of provinces
    int numProvinces(vector<vector<int>> adj, int V) {
        // Create an adjacency list from the adjacency matrix
        vector<int> adjLs[V]; 
        
        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Consider only edges, excluding self-loops
                if (adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        
        // Array to keep track of visited nodes
        int vis[V] = {0}; 
        // Counter to count the number of provinces
        int cnt = 0; 
        
        // Traverse all nodes
        for (int i = 0; i < V; i++) {
            // If the node is not visited
            if (!vis[i]) {
                // Increment the province count
                cnt++;
                // Perform DFS to mark all reachable nodes
                dfs(i, adjLs, vis); 
            }
        }
        
        // Return the number of provinces
        return cnt; 
    }

/*
EXAMPLE USAGE:
vector<vector<int>> adj = {
    {1, 0, 1},
    {0, 1, 0},
    {1, 0, 1}
};
int V = 3;
int result = numProvinces(adj, V); // Returns 2

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices and E is the number of edges. Each vertex and edge is visited once.

SPACE COMPLEXITY:
- O(V + E), to store the adjacency list and the visited array.
*/
