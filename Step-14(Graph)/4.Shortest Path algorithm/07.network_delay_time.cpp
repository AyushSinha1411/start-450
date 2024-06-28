/*
QUESTION:
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target. We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

APPROACH:
1. Represent the network as an adjacency list where each node points to its neighbors along with the travel time.
2. Use Dijkstra's algorithm to find the shortest path from the source node to all other nodes.
3. Use a priority queue to expand the nodes in increasing order of travel time.
4. Maintain a distance array to keep track of the minimum time to reach each node.
5. If a shorter path to a neighboring node is found, update the distance and push the new state onto the priority queue.
6. After processing all nodes, check the maximum time in the distance array to determine the network delay time.
7. If any node remains unreachable (distance remains infinity), return -1.

CODE:
*/

#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
private:
    // Adjacency list to store the graph
    vector<pair<int, int>> adj[101];
    
    // Helper function to perform Dijkstra's algorithm
    void dijkstra(vector<int>& signalReceivedAt, int source, int n) {
        // Priority queue to store {time, node} pairs in increasing order of time
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        
        // Initialize the source node with signal received time 0
        signalReceivedAt[source] = 0;
        
        while (!pq.empty()) {
            // Get the node with the smallest signal received time
            int currNodeTime = pq.top().first;
            int currNode = pq.top().second; 
            pq.pop();
            
            // If the current node's time is greater than the recorded time, skip it
            if (currNodeTime > signalReceivedAt[currNode]) {
                continue;
            }
            
            // Traverse all adjacent nodes
            for (pair<int, int> edge : adj[currNode]) {
                int time = edge.first;
                int neighborNode = edge.second;
                
                // If a shorter path to the neighbor node is found
                if (signalReceivedAt[neighborNode] > currNodeTime + time) {
                    signalReceivedAt[neighborNode] = currNodeTime + time;
                    pq.push({signalReceivedAt[neighborNode], neighborNode});
                }
            }
        }
    }
    
public:
    // Function to calculate the network delay time
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build the adjacency list from the given times array
        for (vector<int> time : times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            
            adj[source].push_back({travelTime, dest});
        }
        
        // Distance array to store the minimum time to reach each node
        vector<int> signalReceivedAt(n + 1, INT_MAX);
        
        // Perform Dijkstra's algorithm starting from node k
        dijkstra(signalReceivedAt, k, n);
        
        // Find the maximum time taken to reach any node
        int answer = INT_MIN;
        for (int i = 1; i <= n; i++) {
            answer = max(answer, signalReceivedAt[i]);
        }
        
        // If any node is unreachable, return -1
        return answer == INT_MAX ? -1 : answer;
    }
};

/*
EXAMPLE USAGE:
Solution sol;
vector<vector<int>> times = {
    {2, 1, 1},
    {2, 3, 1},
    {3, 4, 1}
};
int result = sol.networkDelayTime(times, 4, 2);
// Output: 2

TIME COMPLEXITY:
- O((V + E) log V), where V is the number of vertices (nodes) and E is the number of edges.

SPACE COMPLEXITY:
- O(V + E) for the adjacency list and the priority queue.
*/
