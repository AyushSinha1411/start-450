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
1. Use Breadth First Search (BFS) to traverse the graph.
2. Track the visited nodes and their parents.
3. If an adjacent node is visited and is not the parent of the current node, a cycle is detected.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

// Helper function to detect cycle in a graph using BFS
bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1; 
    // Store <source node, parent node>
    queue<pair<int, int>> q; 
    q.push({src, -1}); 
    // Traverse until queue is not empty
    while(!q.empty()) {
        int node = q.front().first; 
        int parent = q.front().second; 
        q.pop(); 
        
        // Go to all adjacent nodes
        for(auto adjacentNode: adj[node]) {
            // If adjacent node is unvisited
            if(!vis[adjacentNode]) {
                vis[adjacentNode] = 1; 
                q.push({adjacentNode, node}); 
            }
            // If adjacent node is visited and is not its own parent node
            else if(parent != adjacentNode) {
                // Yes, it is a cycle
                return true; 
            }
        }
    }
    // There's no cycle
    return false; 
}

// Function to detect cycle in an undirected graph
bool isCycle(int V, vector<int> adj[]) {
    // Initialize all nodes as unvisited
    int vis[V] = {0};
    for(int i = 0; i < V; i++) {
        // If node is unvisited, check for cycle
        if(!vis[i]) {
            if(detect(i, adj, vis)) return true; 
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
- O(V) for the queue used in BFS.
*/
