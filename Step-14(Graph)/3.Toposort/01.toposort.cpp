/*
QUESTION:
Given a directed acyclic graph (DAG) with V vertices and E edges, return a list of vertices in topological order.

EXAMPLE:
Input:
V = 6
Edges: [[5, 2], [5, 0], [4, 0], [4, 1], [2, 3], [3, 1]]

Output: [5, 4, 2, 3, 1, 0]

APPROACH:
1. Use DFS to traverse the graph and keep track of the visited nodes.
2. Use a stack to store the nodes in the order of their completion.
3. Pop elements from the stack to get the topological order.

CODE:
*/

#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    // DFS function to traverse the graph
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
        // Mark the current node as visited
        vis[node] = 1;
        
        // Traverse adjacent nodes
        for (auto it : adj[node]) {
            if (!vis[it]) dfs(it, vis, st, adj);
        }
        
        // Push the current node to the stack after visiting its adjacent nodes
        st.push(node);
    }
public:
    // Function to return list containing vertices in topological order
    vector<int> topoSort(int V, vector<int> adj[]) {
        int vis[V] = {0};
        stack<int> st;
        
        // Perform DFS for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        // Retrieve the nodes from the stack to form the topological order
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
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
- O(V), for the vis array and the stack used for storing nodes in topological order.
*/
