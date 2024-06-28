/*
QUESTION:
Given a graph with V vertices and E edges represented as an adjacency list where each edge is represented as [source, destination, weight], find the sum of weights of edges in the Minimum Spanning Tree (MST).

APPROACH:
1. Use Prim's algorithm to find the MST.
2. Initialize a priority queue (min-heap) to always extract the edge with the minimum weight.
3. Use a visited array to keep track of vertices included in the MST.
4. Start from the first vertex, push its edges into the priority queue.
5. Continuously extract the minimum weight edge from the priority queue and add it to the MST if it leads to an unvisited vertex.
6. Continue this process until all vertices are included in the MST.
7. Calculate the total weight of the MST by summing up the weights of the included edges.

CODE:
*/

#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Priority queue to select the edge with the minimum weight
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Visited array to keep track of vertices included in the MST
        vector<int> vis(V, 0);
        
        // Start with the first vertex
        // Push {weight, vertex} into the priority queue
        pq.push({0, 0});
        
        // Variable to store the sum of weights of edges in the MST
        int sum = 0;
        
        // Continue until the priority queue is empty
        while (!pq.empty()) {
            // Extract the minimum weight edge from the priority queue
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int wt = it.first;
            
            // If the vertex is already visited, continue to the next iteration
            if (vis[node] == 1) continue;
            
            // Add the weight of the edge to the sum
            sum += wt;
            
            // Mark the vertex as visited
            vis[node] = 1;
            
            // Traverse all adjacent vertices
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edW = it[1];
                
                // If the adjacent vertex is not visited, push it into the priority queue
                if (!vis[adjNode]) {
                    pq.push({edW, adjNode});
                }
            }
        }
        
        // Return the sum of weights of edges in the MST
        return sum;
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
- O(E log V), where V is the number of vertices and E is the number of edges. This complexity is due to the priority queue operations.

SPACE COMPLEXITY:
- O(V + E) for the priority queue and adjacency list.
*/
