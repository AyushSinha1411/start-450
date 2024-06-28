/*
QUESTION:
Given a number of cities (represented by n) and a list of flights between these cities where each flight is represented by [source, destination, cost], find the cheapest price to get from the source city to the destination city with at most K stops. If there is no such route, return -1.

APPROACH:
1. Represent the flights as an adjacency list where each city points to its destinations along with the cost.
2. Use a modified Dijkstra's algorithm to find the shortest path from the source to the destination with the constraint of at most K stops.
3. Use a priority queue to expand the nodes in increasing order of cost.
4. Maintain a distance array to keep track of the minimum cost to reach each city.
5. If a cheaper path to a neighboring city is found within the allowed number of stops, update the distance and push the new state onto the priority queue.
6. If the destination city is unreachable within K stops, return -1.

CODE:
*/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Create the adjacency list to depict airports and flights in the form of a graph.
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Create a queue which stores the node and their distances from the source
        // in the form of {stops, {node, dist}} with ‘stops’ indicating 
        // the number of nodes between src and the current node.
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        // Distance array to store the updated distances from the source.
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // Iterate through the graph using a queue like in Dijkstra with 
        // popping out the element with minimum stops first.
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // Stop the process as soon as the limit for the stops is reached.
            if (stops > K) continue;
            
            for (auto iter : adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;

                // Only update the queue if the new calculated distance is
                // less than the previous and the stops are also within limits.
                if (cost + edW < dist[adjNode] && stops <= K) {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }

        // If the destination node is unreachable, return -1,
        // else return the calculated distance from src to dst.
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

/*
EXAMPLE USAGE:
vector<vector<int>> flights = {
    {0, 1, 100},
    {1, 2, 100},
    {0, 2, 500}
};
Solution sol;
int result = sol.CheapestFLight(3, flights, 0, 2, 1);
// Output: 200

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices (cities) and E is the number of edges (flights).
- Each node is processed at most K times in the worst case.

SPACE COMPLEXITY:
- O(V + E) for the adjacency list and distance array.
*/
