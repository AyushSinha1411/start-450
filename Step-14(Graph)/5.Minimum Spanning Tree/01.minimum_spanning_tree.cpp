/*
QUESTION:
Given a graph with V vertices and E edges represented as an adjacency list where each edge is represented as [source, destination, weight], find the total weight of the minimum spanning tree (MST).

APPROACH:
1. Use Prim's algorithm to find the MST.
2. Initialize a key array to keep track of the minimum weight edge for each vertex.
3. Use a boolean array to mark vertices included in the MST.
4. Use a parent array to store the MST structure.
5. Start from the first vertex, update the key values of adjacent vertices.
6. Pick the vertex with the minimum key value that is not yet included in the MST.
7. Continue this process until all vertices are included in the MST.
8. Calculate the total weight of the MST by summing up the key values.

CODE:
*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // To store parent of each vertex in MST
        vector<int> parent(V, -1);
        
        // To store key value of each vertex
        vector<int> key(V, INT_MAX);
        
        // To keep track of vertices included in MST
        vector<bool> mstSet(V, false);

        // Start with the first vertex
        key[0] = 0;
        parent[0] = -1;

        // MST will have V vertices
        for (int count = 0; count < V - 1; ++count) {
            // Find the vertex with the minimum key value that is not yet included in MST
            int u = -1;
            for (int v = 0; v < V; ++v) {
                if (!mstSet[v] && (u == -1 || key[v] < key[u])) {
                    u = v;
                }
            }

            // Add the selected vertex to the MST
            mstSet[u] = true;

            // Update key values of adjacent vertices of the selected vertex
            for (auto& edge : adj[u]) {
                int v = edge[0]; // adjacent vertex
                int weight = edge[1]; // weight of the edge

                // If v is not in MST and weight of (u,v) is smaller than current key of v
                if (!mstSet[v] && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }

        // Calculate the total weight of MST
        int totalWeight = 0;
        for (int i = 1; i < V; ++i) {
            totalWeight += key[i];
        }

        return totalWeight;
    }
};

/*
EXAMPLE USAGE:
Solution sol;
vector<vector<int>> adj[] = {
    {{1, 2}, {3, 6}}, // edges from vertex 0
    {{0, 2}, {2, 3}, {3, 8}}, // edges from vertex 1
    {{1, 3}, {3, 7}}, // edges from vertex 2
    {{0, 6}, {1, 8}, {2, 7}}  // edges from vertex 3
};
int result = sol.spanningTree(4, adj);
// Output: 12

TIME COMPLEXITY:
- O(V^2), where V is the number of vertices. This complexity is due to the nested loops for finding the minimum key value and updating key values of adjacent vertices.

SPACE COMPLEXITY:
- O(V) for the key, parent, and mstSet arrays.
*/
