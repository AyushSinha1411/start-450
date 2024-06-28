/*
QUESTION:
Given a directed graph with V vertices, find the number of Strongly Connected Components (SCCs) using Kosaraju's algorithm. An SCC is a maximal subgraph where every pair of vertices is reachable from each other.

APPROACH:
1. Perform a DFS traversal of the graph and push nodes to a stack based on their finishing times.
2. Reverse the directions of all the edges in the graph.
3. Perform a DFS on the reversed graph, using the nodes in the order they appear in the stack.
4. Count the number of DFS trees formed in step 3, which corresponds to the number of SCCs.

CODE:
*/

#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    // Perform DFS and push nodes to stack based on finishing time
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    // Perform DFS on the transposed graph
    void dfs3(int node, vector<int> &vis, vector<int> adjT[]) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT);
            }
        }
    }

public:
    // Function to find the number of strongly connected components in the graph
    int kosaraju(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;

        // Step 1: Perform DFS and push nodes to stack based on finishing time
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        // Step 2: Create the transposed graph
        vector<int> adjT[V];
        for (int i = 0; i < V; i++) {
            vis[i] = 0; // Reset visited array for the second DFS
            for (auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        int scc = 0; // Counter for strongly connected components

        // Step 3: Perform DFS on the transposed graph
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};

/*
TIME COMPLEXITY:
- O(V + E), where V is the number of vertices and E is the number of edges. Each node and edge is processed twice (once in the original graph and once in the transposed graph).

SPACE COMPLEXITY:
- O(V + E), for storing the adjacency list and the transposed graph.

EXAMPLE USAGE:
Solution sol;
int V = 5;
vector<int> adj[V] = {
    {2, 3},
    {0},
    {1},
    {4},
    {}
};
int result = sol.kosaraju(V, adj);
// result will contain the number of strongly connected components in the graph.
*/
