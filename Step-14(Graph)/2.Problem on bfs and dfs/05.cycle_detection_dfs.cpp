/*
QUESTION:
Given an undirected graph, determine if there is a cycle in it. A cycle is a path of edges and vertices wherein a vertex is reachable from itself.

EXAMPLE:
Input: 
V = 4, E = 3
Edges = [(0, 1), (1, 2), (2, 3)]
Output: false

Input:
V = 4, E = 4
Edges = [(0, 1), (1, 2), (2, 3), (3, 1)]
Output: true

APPROACH:
1. Use Depth First Search (DFS) to traverse the graph.
2. Track the visited nodes and their parents.
3. If an adjacent node is visited and is not the parent of the current node, a cycle is detected.

CODE:
*/

#include <vector>
using namespace std;

// Helper function to detect cycle in a graph using DFS
bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
    vis[node] = 1; 
    // Visit adjacent nodes
    for(auto adjacentNode: adj[node]) {
        // Unvisited adjacent node
        if(!vis[adjacentNode]) {
            if(dfs(adjacentNode, node, vis, adj) == true) 
                return true; 
        }
        // Visited node but not a parent node
        else if(adjacentNode != parent) 
            return true; 
    }
    return false; 
}

// Function to detect cycle in an undirected graph
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0}; 
    // For graph with connected components
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(dfs(i, -1, vis, adj) == true) 
                return true; 
        }
    }
    return false; 
}

/*
EXAMPLE USAGE:
int V = 4;
vector<int> adj[] = {{1}, {0, 2}, {1, 3}, {2}};
bool result = isCycle(V, adj);
// Output: false

int V = 4;
vector<int> adj[] = {{1}, {0, 2, 3}, {1, 3}, {1, 2}};
bool result = isCycle(V, adj);
// Output: true

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices and E is the number of edges in the graph.

SPACE COMPLEXITY:
- O(V + E) for the adjacency list representation of the graph.
- O(V) for the visited array.
- O(V) for the recursion stack in the worst case.
*/
