/*
QUESTION:
Given a graph represented by an adjacency list, find the sum of the weights of the edges in its Minimum Spanning Tree (MST) using Kruskal's algorithm.

APPROACH:
1. Use Kruskal's algorithm to find the MST.
2. Convert the adjacency list to a list of edges.
3. Sort the edges based on their weights.
4. Use a Disjoint Set (Union-Find) data structure to keep track of the connected components.
5. Iterate through the sorted edges and add them to the MST if they do not form a cycle.
6. Return the sum of the weights of the edges in the MST.

CODE:
*/

#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;
public:
    // Constructor to initialize the rank and parent arrays
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Function to find the ultimate parent of a node with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Function to perform union of two sets by rank
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); // Find ultimate parent of u
        int ulp_v = findUPar(v); // Find ultimate parent of v
        if (ulp_u == ulp_v) return; // They are already in the same set
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[]) {
    // Convert adjacency list to a list of edges
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt, {node, adjNode}});
        }
    }

    // Sort edges based on their weights
    sort(edges.begin(), edges.end());

    // Initialize Disjoint Set
    DisjointSet ds(V);
    int mstWt = 0;

    // Iterate through the sorted edges
    for (auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        // Add edge to MST if it doesn't form a cycle
        if (ds.findUPar(u) != ds.findUPar(v)) {
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }

    // Return the total weight of the MST
    return mstWt;
}

/*
EXAMPLE USAGE:
vector<vector<int>> adj[] = {
    {{1, 5}, {2, 3}},
    {{0, 5}, {2, 1}},
    {{0, 3}, {1, 1}}
};
int V = 3;
int result = spanningTree(V, adj);
// Output: 4

TIME COMPLEXITY:
- O(E log E + E log V), where E is the number of edges and V is the number of vertices.
- Sorting the edges takes O(E log E) and each union/find operation takes O(log V).

SPACE COMPLEXITY:
- O(E + V) for storing the edges and the Disjoint Set data structures.
*/
