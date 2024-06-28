/*
QUESTION:
Given a number of vertices 'V' and an adjacency list representation of the graph, return the Breadth First Traversal (BFS) starting from node 0.

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
{0, 1, 2, 3, 4}

APPROACH:
1. Initialize a visited array to keep track of visited nodes.
2. Initialize a queue and push the starting node (0).
3. Perform BFS by processing nodes in the queue:
   - Dequeue a node, add it to the BFS result.
   - Enqueue all its unvisited neighbors and mark them as visited.
4. Continue until the queue is empty.
5. Return the BFS traversal result.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS traversal of the graph
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    // Array to keep track of visited nodes
    int vis[V] = {0}; 
    // Mark the starting node (0) as visited
    vis[0] = 1; 
    // Queue to store nodes for BFS
    queue<int> q;
    // Push the initial starting node (0)
    q.push(0); 
    // Vector to store the BFS traversal result
    vector<int> bfs; 

    // Iterate until the queue is empty
    while(!q.empty()) {
        // Get the front node from the queue
        int node = q.front(); 
        q.pop(); 
        // Add the node to the BFS result
        bfs.push_back(node); 
        // Traverse all its neighbors
        for(auto it : adj[node]) {
            // If the neighbor has not been visited
            if(!vis[it]) {
                // Mark the neighbor as visited
                vis[it] = 1; 
                // Push the neighbor to the queue
                q.push(it); 
            }
        }
    }

    // Return the BFS traversal result
    return bfs; 
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
vector<int> result = bfsOfGraph(V, adj); // Returns {0, 1, 2, 3, 4}

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices and E is the number of edges. Each vertex and edge is visited once.

SPACE COMPLEXITY:
- O(V), to store the visited array and the BFS result.
*/
