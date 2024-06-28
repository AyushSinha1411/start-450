/*
QUESTION:
Implement a Disjoint Set (Union-Find) data structure with path compression and union by rank. This data structure supports the following operations:
1. Find the representative (parent) of a set containing a particular element.
2. Union of two sets based on rank.

APPROACH:
1. Initialize the parent and rank arrays. The parent array keeps track of the representative for each element, and the rank array helps to keep the tree flat by attaching smaller trees under the root of larger trees.
2. Implement the find function with path compression to speed up future queries.
3. Implement the union function using union by rank to attach smaller trees under the root of larger trees.

CODE:
*/

#include <vector>
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
    void unionByRank(int u, int v) {
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

/*
EXAMPLE USAGE:
DisjointSet ds(5); // Create a disjoint set with 5 elements

// Perform some union operations
ds.unionByRank(1, 2);
ds.unionByRank(2, 3);
ds.unionByRank(4, 5);

// Find the representative (parent) of the sets containing 1 and 5
int parent1 = ds.findUPar(1); // Output: 1
int parent5 = ds.findUPar(5); // Output: 4

// Perform union operation between sets containing 3 and 4
ds.unionByRank(3, 4);

// Find the representative (parent) of the sets containing 3 and 5
int parent3 = ds.findUPar(3); // Output: 1
int parent5_updated = ds.findUPar(5); // Output: 1
*/

