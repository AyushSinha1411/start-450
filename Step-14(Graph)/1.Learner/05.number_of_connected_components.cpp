/*
QUESTION:
Given a number of vertices 'n' and a list of edges, count the number of connected components in the graph.

EXAMPLE:
Input:
n = 5
edges = {{0, 1}, {1, 2}, {3, 4}}
Output:
2
Explanation:
There are two connected components in the graph:
- Component 1: {0, 1, 2}
- Component 2: {3, 4}

APPROACH:
1. Create an adjacency list representation of the graph.
2. Use Depth First Search (DFS) to explore each component of the graph.
3. Maintain a visited set to keep track of visited nodes.
4. For each unvisited node, perform a DFS and count the number of connected components.

CODE:
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Helper function to perform DFS traversal
void dfs(int node, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
    // Mark the current node as visited
    visited.insert(node);
    // Visit all unvisited neighbors
    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited);
        }
    }
}

// Function to count the number of connected components in the graph
int countComponents(int n, vector<vector<int>>& edges) {
    // Create an adjacency list representation of the graph
    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Initialize a set to keep track of visited nodes
    unordered_set<int> visited;
    // Variable to count the number of connected components
    int components = 0;

    // Iterate over all nodes
    for (int i = 0; i < n; ++i) {
        // If the node is not visited, it's a new component
        if (visited.find(i) == visited.end()) {
            // Perform DFS to visit all nodes in the component
            dfs(i, graph, visited);
            // Increment the component count
            components++;
        }
    }

    // Return the total number of connected components
    return components;
}

/*
EXAMPLE USAGE:
int n = 5;
vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
int result = countComponents(n, edges); // Returns 2

TIME COMPLEXITY:
- O(V + E), where V is the number of vertices and E is the number of edges. Each node and edge is visited once.

SPACE COMPLEXITY:
- O(V + E), to store the graph representation and the visited set.
*/
