/*
QUESTION:
Given a list of stones represented by their coordinates (x, y), where x represents the row and y represents the column, and an integer n representing the total number of stones, find the maximum number of stones that can be removed such that no two stones are in the same row or column after removal.

APPROACH:
1. Create a Disjoint Set data structure to represent connected components.
2. Iterate through each stone and create a mapping of row nodes and column nodes in the disjoint set.
3. Union each stone's row node with its column node to indicate that they are connected.
4. After processing all stones, count the number of connected components.
5. The maximum number of stones that can be removed is n - cnt, where cnt is the number of connected components.

CODE:
*/

#include <vector>
#include <unordered_map>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    // Constructor to initialize Disjoint Set
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        // Initialize each node as a separate set
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Find the parent of a node with path compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Union by rank to merge two sets
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        // If they belong to the same set, no need to merge
        if (ulp_u == ulp_v) return;
        // Union by rank to maintain balance
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

    // Union by size to merge two sets
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        // If they belong to the same set, no need to merge
        if (ulp_u == ulp_v) return;
        // Union by size to merge smaller set into larger set
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;
        // Find the maximum row and column
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        // Create a Disjoint Set with enough capacity to hold rows and columns
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        // Process each stone
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1; // Offset column nodes by maxRow + 1
            // Union the row and column nodes of each stone
            ds.unionBySize(nodeRow, nodeCol);
            // Keep track of nodes representing stones
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        // Count the number of connected components
        for (auto it : stoneNodes) {
            if (ds.findUPar(it.first) == it.first) {
                cnt++;
            }
        }
        // The maximum number of stones that can be removed
        return n - cnt;
    }
};

/*
TIME COMPLEXITY:
- O(N) for iterating through the stones, where N is the number of stones.

SPACE COMPLEXITY:
- O(N) for the Disjoint Set data structure and the unordered map, where N is the number of stones.

EXAMPLE USAGE:
Solution sol;
vector<vector<int>> stones = {{0, 0}, {1, 1}, {1, 2}, {2, 2}};
int n = 4;
int result = sol.maxRemove(stones, n);
// result will be 2
*/
