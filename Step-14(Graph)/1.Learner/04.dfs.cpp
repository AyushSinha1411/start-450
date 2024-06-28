/*
QUESTION:
Given a number of vertices 'V' and an adjacency list representation of the graph, return the Depth First Traversal (DFS) starting from node 0.

EXAMPLE:
Input:
V = 5
adj = {
    {1, 2},      // adjacency list for node 0
    {0, 3, 4},   // adjacency list for node 1
    {0},         // adjacency list for node 2
    {1},         // adjacency list for node 3
    {1}          // adjacency list for node 4
}
Output:
{0, 1, 3, 4, 2}

APPROACH:
1. Initialize a visited array to keep track of visited nodes.
2. Define a recursive DFS function that marks the current node as visited and explores its unvisited neighbors.
3. Create a list to store the DFS traversal result.
4. Call the DFS function starting from node 0.
5. Return the DFS traversal result.

CODE:
*/

#include <vector>
using namespace std;

// Helper function to perform DFS traversal
void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
    // Mark the current node as visited
    vis[node] = 1; 
    // Add the current node to the DFS result
    ls.push_back(node); 
    // Traverse all its neighbors
    for(auto it : adj[node]) {
        // If the neighbor is not visited
        if(!vis[it]) {
            // Recursively perform DFS on the neighbor
            dfs(it, adj, vis, ls); 
        }
    }
}

public:
// Function to return a list containing the DFS traversal of the graph
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    // Array to keep track of visited nodes
    int vis[V] = {0}; 
    // Starting node for DFS
    int start = 0;
    // Create a list to store the DFS result
    vector<int> ls; 
    // Call DFS for the starting node
    dfs(start, adj, vis, ls); 
    // Return the DFS traversal result
    return ls; 
}

/*
EXAMPLE USAGE:
int V = 5;
vector<int> adj[5] = {
    {1, 2},
    {0, 3, 4},
    {0},
    {1},
    {1}
};
vector<int> result = dfsOfGraph(V, adj); // Returns {0, 1, 3, 4, 2}

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices and E is the number of edges. Each vertex and edge is visited once.

SPACE COMPLEXITY:
- O(V), to store the visited array and the DFS result.
*/
