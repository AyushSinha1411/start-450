/*
QUESTION:
Implement the Bellman-Ford algorithm to find the shortest paths from a given source vertex to all other vertices in a weighted graph. If a negative weight cycle exists, return a vector with a single element, -1.

APPROACH:
1. Initialize a distance array with a large number (representing infinity) for all vertices except the source vertex, which is initialized to 0.
2. Relax all edges V-1 times, where V is the number of vertices. In each iteration, for each edge (u, v, weight), update the distance to v if the distance to u plus the weight of the edge is less than the current distance to v.
3. Perform one more iteration over all edges to check for negative weight cycles. If any distance can still be updated, a negative weight cycle exists.
4. If a negative weight cycle is detected, return a vector containing only -1. Otherwise, return the distance array.

CODE:
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Initialize the distance array with a large value representing infinity.
        vector<int> dist(V, 1e8);
        dist[S] = 0;  // Distance to the source is 0.

        // Relax all edges V-1 times.
        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                // If the distance to u is not infinity and can be minimized, update the distance to v.
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycles by performing one more relaxation.
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            // If the distance can still be minimized, a negative weight cycle exists.
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};  // Negative weight cycle detected.
            }
        }

        return dist;  // Return the distance array.
    }
};

/*
EXAMPLE USAGE:
Solution sol;
vector<vector<int>> edges = {
    {0, 1, -1},
    {0, 2, 4},
    {1, 2, 3},
    {1, 3, 2},
    {1, 4, 2},
    {3, 2, 5},
    {3, 1, 1},
    {4, 3, -3}
};
int V = 5;
int S = 0;
vector<int> result = sol.bellman_ford(V, edges, S);
// Output: [0, -1, 2, -2, 1]

TIME COMPLEXITY:
- O(V * E), where V is the number of vertices and E is the number of edges.
- Each vertex is processed V-1 times, and each edge is checked in every iteration.

SPACE COMPLEXITY:
- O(V) for the distance array.

The Bellman-Ford algorithm is capable of handling graphs with negative weight edges and detecting negative weight cycles.
*/
