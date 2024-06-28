/*
QUESTION:
Given an undirected graph represented by `n` nodes and a list of edges `edge`, find the minimum number of edges to remove in order to make the graph a tree. If it's not possible to make the graph a tree, return -1.

APPROACH:
1. Implement a Disjoint Set data structure to keep track of connected components and detect cycles.
2. Iterate through each edge in the input list.
3. For each edge, check if its endpoints belong to the same connected component. If they do, it forms a cycle, and we increment the `cntExtras` counter.
4. If the endpoints belong to different connected components, we merge the components and continue.
5. After processing all edges, count the number of connected components in the disjoint set. The number of edges to remove to form a tree is `cntC - 1`, where `cntC` is the number of connected components.
6. If the number of extra edges (`cntExtras`) is greater than or equal to the required number of edges to form a tree, return the required number of edges. Otherwise, return -1 indicating it's not possible to form a tree.

CODE:
*/

#include <vector>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
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

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
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
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cntExtras = 0;
        for (auto it : edge) {
            int u = it[0];
            int v = it[1];
            if (ds.findUPar(u) == ds.findUPar(v)) {
                cntExtras++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) cntC++;
        }
        int ans = cntC - 1;
        if (cntExtras >= ans) return ans;
        return -1;
    }
};

/*
TIME COMPLEXITY:
- O(N + E), where N is the number of nodes and E is the number of edges. The time complexity is dominated by the loop that processes each edge.

SPACE COMPLEXITY:
- O(N), where N is the number of nodes. We use additional space for the disjoint set data structure.

EXAMPLE USAGE:
Solution sol;
vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
int result = sol.Solve(5, edges);
// result will be 0 since the graph is already a tree.
*/
