/*
QUESTION:
Given a directed graph with V vertices, determine if the graph contains a cycle using Kahn's Algorithm (BFS-based approach).

APPROACH:
1. Calculate the in-degree of each vertex.
2. Use a queue to store vertices with in-degree 0.
3. Perform BFS to process each vertex and update the in-degree of its adjacent vertices.
4. If the number of vertices processed is less than the total number of vertices, a cycle exists.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to detect cycle in a directed graph
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        queue<int> q;

        // Calculate in-degree for each vertex
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Add vertices with in-degree 0 to the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        // Perform BFS and check for cycles
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto it : adj[front]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If the number of vertices traversed during BFS is not equal to the total number of vertices,
        // then there is a cycle in the graph.
        return ans.size() != V; // Return true if cycle is present, false otherwise
    }
};

/*
EXAMPLE USAGE:
int V = 4;
vector<int> adj[V];
adj[0].push_back(1);
adj[1].push_back(2);
adj[2].push_back(3);
adj[3].push_back(1);

Solution sol;
bool hasCycle = sol.isCyclic(V, adj);
// Output: true (since there is a cycle)

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices and E is the number of edges. Each node and edge is visited once.

SPACE COMPLEXITY:
- O(V), for the in-degree array and the queue used for processing vertices.
*/
