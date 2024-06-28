/*
QUESTION:
Given a graph with V vertices and adjacency list adj where adj[i] contains pairs of (neighbor, weight), find the shortest distance from the source vertex S to all other vertices using Dijkstra's algorithm.

APPROACH:
1. Initialize a set to store nodes as pairs {distance, node} in ascending order of distances.
2. Initialize a distance vector with a large number to indicate unvisited nodes. Set the source node distance to 0.
3. Use the set to extract the node with the smallest distance and update distances for its neighbors.
4. Continue until the set is empty.
5. Return the distance vector containing the shortest distances from the source to all nodes.

CODE:
*/

#include <vector>
#include <set>
#include <utility>
using namespace std;

class Solution {
public:
    // Function to find the shortest distance of all the vertices from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Create a set for storing the nodes as a pair {distance, node}
        // where distance is the distance from the source to the node.
        set<pair<int, int>> st;

        // Initialize distance vector with a large number to indicate unvisited nodes.
        // This vector contains distances from the source to the nodes.
        vector<int> dist(V, 1e9);

        // Insert the source node with distance 0.
        st.insert({0, S});
        dist[S] = 0;

        // Process nodes in the set until it becomes empty.
        while (!st.empty()) {
            // Get the node with the smallest distance.
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            // Check for all adjacent nodes of the current node.
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgW = it[1];

                // If the current path offers a shorter distance to the adjacent node,
                // update the distance and insert the adjacent node into the set.
                if (dis + edgW < dist[adjNode]) {
                    // Erase the node if it was visited previously with a greater cost.
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    // Update the distance and insert the node into the set.
                    dist[adjNode] = dis + edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        // Return the distance vector containing the shortest distances
        // from the source to all the nodes.
        return dist;
    }
};

/*
EXAMPLE USAGE:
vector<vector<int>> adj[] = {{{1, 2}, {2, 1}}, {{2, 3}}, {{3, 6}}, {}};
int V = 4;
int S = 0;
Solution sol;
vector<int> result = sol.dijkstra(V, adj, S);
// Output: [0, 2, 1, 7]

TIME COMPLEXITY:
- O((V + E) * log(V)), where V is the number of vertices and E is the number of edges.
- The logarithmic factor comes from the set operations (insertion and deletion).

SPACE COMPLEXITY:
- O(V + E), for storing the adjacency list and other auxiliary structures.
*/
