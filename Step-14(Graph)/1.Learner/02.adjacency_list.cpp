/*
QUESTION:
Given a number of vertices 'V' and a list of edges, return the adjacency list representation of the graph.

EXAMPLE:
Input: 
V = 4
edges = [(0, 1), (0, 2), (1, 2), (1, 3)]
Output: 
[
    [1, 2],    // Adjacency list for vertex 0
    [0, 2, 3], // Adjacency list for vertex 1
    [0, 1],    // Adjacency list for vertex 2
    [1]        // Adjacency list for vertex 3
]

APPROACH:
1. Initialize an empty adjacency list for each vertex.
2. Iterate through the list of edges.
3. For each edge, add the corresponding vertices to each other's adjacency list.
4. Return the complete adjacency list representation of the graph.

CODE:
*/

#include <vector>
#include <utility>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int,int>> edges) {
    // Initialize an empty adjacency list for each vertex
    vector<vector<int>> adj(V);
    
    // Iterate through the list of edges
    for(int i = 0; i < edges.size(); i++) {
        // Get the vertices connected by the edge
        int node1 = edges[i].first;
        int node2 = edges[i].second;
        
        // Add each vertex to the other's adjacency list
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    
    // Return the complete adjacency list
    return adj;
}

/*
EXAMPLE USAGE:
int V = 4;
vector<pair<int,int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};
vector<vector<int>> adjList = printGraph(V, edges); 
// Returns: 
// [
//    [1, 2],
//    [0, 2, 3],
//    [0, 1],
//    [1]
// ]

TIME COMPLEXITY:
- O(E), where E is the number of edges. Each edge is processed once to update the adjacency list.

SPACE COMPLEXITY:
- O(V + E), where V is the number of vertices and E is the number of edges. This is to store the adjacency list.
*/
