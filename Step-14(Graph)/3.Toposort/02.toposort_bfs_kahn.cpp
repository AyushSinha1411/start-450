/*
QUESTION:
Given a directed acyclic graph (DAG) with V vertices and E edges, return a list of vertices in topological order using Kahn's Algorithm (BFS-based approach).

EXAMPLE:
Input:
V = 6
Edges: [[5, 2], [5, 0], [4, 0], [4, 1], [2, 3], [3, 1]]

Output: [5, 4, 2, 3, 1, 0]

APPROACH:
1. Calculate the in-degree of each vertex.
2. Use a queue to store vertices with in-degree 0.
3. Perform BFS to process each vertex and update the in-degree of its adjacent vertices.
4. Add the processed vertex to the topological order and push vertices with in-degree 0 to the queue.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to return list containing vertices in topological order
    vector<int> topoSort(int V, vector<int> adj[]) {
        int indegree[V] = {0};

        // Calculate in-degree of each vertex
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Queue to store vertices with in-degree 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform BFS
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            // Process each adjacent vertex
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }
};

/*
EXAMPLE USAGE:
int V = 6;
vector<int> adj[V];
adj[5].push_back(2);
adj[5].push_back(0);
adj[4].push_back(0);
adj[4].push_back(1);
adj[2].push_back(3);
adj[3].push_back(1);

Solution sol;
vector<int> result = sol.topoSort(V, adj);
// Output: [5, 4, 2, 3, 1, 0]

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices and E is the number of edges. Each node and edge is visited once.

SPACE COMPLEXITY:
- O(V), for the in-degree array and the queue used for processing vertices.
*/
