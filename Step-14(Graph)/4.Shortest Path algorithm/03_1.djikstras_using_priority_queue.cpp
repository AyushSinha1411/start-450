/*
QUESTION:
Given a graph with V vertices and adjacency list adj where adj[i] contains pairs of (neighbor, weight), find the shortest distance from the source vertex S to all other vertices using Dijkstra's algorithm with a priority queue.

APPROACH:
1. Initialize a priority queue (min-heap) to store nodes as pairs {distance, node}.
2. Initialize a distance vector with a large number to indicate unvisited nodes. Set the source node distance to 0.
3. Use the priority queue to extract the node with the smallest distance and update distances for its neighbors.
4. Continue until the priority queue is empty.
5. Return the distance vector containing the shortest distances from the source to all nodes.

CODE:
*/

#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find the shortest distance of all the vertices from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Create a priority queue for storing the nodes as a pair {distance, node}
        // where distance is the distance from source to the node.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialize distance vector with a large number to indicate unvisited nodes.
        // This vector contains distances from the source to the nodes.
        vector<int> distTo(V, INT_MAX);

        // Source initialized with distance 0.
        distTo[S] = 0;
        pq.push({0, S});

        // Process nodes in the priority queue until it becomes empty.
        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            // Check for all adjacent nodes of the current node.
            for (auto it : adj[node]) {
                int v = it[0];
                int w = it[1];

                // If the current path offers a shorter distance to the adjacent node,
                // update the distance and insert the adjacent node into the priority queue.
                if (dis + w < distTo[v]) {
                    distTo[v] = dis + w;
                    pq.push({dis + w, v});
                }
            }
        }

        // Return the distance vector containing the shortest distances
        // from the source to all the nodes.
        return distTo;
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
- The logarithmic factor comes from the priority queue operations (insertion and deletion).

SPACE COMPLEXITY:
- O(V + E), for storing the adjacency list and other auxiliary structures.
*/
