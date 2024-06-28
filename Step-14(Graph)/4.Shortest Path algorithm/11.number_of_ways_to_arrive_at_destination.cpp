/*
QUESTION:
You are given a graph of `n` nodes and a list of roads where each road is represented by a triplet `[source, destination, time]`. You are also given that all the roads are bidirectional. You need to count the number of ways to reach the last node from the first node such that the total time is the shortest. The result should be returned modulo `10^9 + 7`.

APPROACH:
1. Create an adjacency list to represent the graph.
2. Use Dijkstra's algorithm to find the shortest path from the source node to all other nodes.
3. Use a priority queue to expand nodes in increasing order of their distances.
4. Maintain two arrays:
   - `dist[]` to store the shortest distance from the source to each node.
   - `ways[]` to store the number of ways to reach each node with the shortest distance.
5. For each node, update the distances and count the number of ways to reach its adjacent nodes.
6. Return the number of ways to reach the last node modulo `10^9 + 7`.

CODE:
*/

#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>> &roads) {
        // Creating an adjacency list for the given graph.
        vector<pair<int, int>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Defining a priority queue (min heap).
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initializing the dist array and the ways array
        // along with their first indices.
        vector<int> dist(n, INT_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // Define modulo value
        int mod = (int)(1e9 + 7);

        // Iterate through the graph with the help of priority queue
        // just as we do in Dijkstra's Algorithm.
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edW = it.second;

                // This ‘if’ condition signifies that this is the first
                // time we’re coming with this short distance, so we push
                // in PQ and keep the number of ways the same.
                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }
                // If we again encounter a node with the same short distance
                // as before, we simply increment the number of ways.
                else if (dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        // Finally, we return the number of ways to reach
        // the (n-1)th node modulo 10^9+7.
        return ways[n - 1] % mod;
    }
};

/*
EXAMPLE USAGE:
Solution sol;
vector<vector<int>> roads = {
    {0, 1, 4},
    {0, 2, 2},
    {1, 2, 1},
    {1, 3, 5},
    {2, 3, 3}
};
int result = sol.countPaths(4, roads);
// Output: 2 (There are 2 shortest paths from node 0 to node 3)

TIME COMPLEXITY:
- O((V + E) log V), where V is the number of vertices (nodes) and E is the number of edges.

SPACE COMPLEXITY:
- O(V + E) for the adjacency list, distance array, and ways array.
*/
