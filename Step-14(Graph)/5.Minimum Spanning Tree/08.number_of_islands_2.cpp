/*
QUESTION:
Given a grid of size n x m representing a map where 1 represents land and 0 represents water, perform a series of operations. Each operation is represented by a pair of coordinates (x, y). If the cell at the given coordinates is land and has not been visited before, mark it as visited and count it as an island. Then, check its adjacent cells and merge islands if they are adjacent.

APPROACH:
1. Implement Disjoint Set to represent islands.
2. Initialize a 2D array to keep track of visited cells.
3. Iterate through each operation.
4. If the cell is already visited, skip the operation and add the current count of islands to the result.
5. Otherwise, mark the cell as visited, increment the island count, and check its adjacent cells.
6. If adjacent cells are also visited, union their corresponding islands.
7. Add the updated island count to the result after each operation.

CODE:
*/

#include <vector>
#include <cstring> // for memset
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
private:
    // Function to check if the given coordinates are within the grid
    bool isValid(int adjr, int adjc, int n, int m) {
        return adjr >= 0 && adjr < n && adjc >= 0 && adjc < m;
    }
public:
    // Function to count the number of islands after each operation
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
        DisjointSet ds(n * m);
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        int cnt = 0;
        vector<int> ans;
        // Iterate through each operation
        for (auto it : operators) {
            int row = it[0];
            int col = it[1];
            // If the cell is already visited, skip the operation
            if (vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            // Mark the cell as visited and increment the island count
            vis[row][col] = 1;
            cnt++;
            // Define directions for adjacent cells
            int dr[] = { -1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            // Check adjacent cells
            for (int ind = 0; ind < 4; ind++) {
                int adjr = row + dr[ind];
                int adjc = col + dc[ind];
                // If the adjacent cell is within the grid
                if (isValid(adjr, adjc, n, m)) {
                    // If the adjacent cell is also visited
                    if (vis[adjr][adjc] == 1) {
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;
                        // If the islands represented by the current cell and adjacent cell are not already connected
                        if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) {
                            // Decrement the island count and union the islands
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            // Add the current island count to the result after each operation
            ans.push_back(cnt);
        }
        return ans;
    }
};

/*
TIME COMPLEXITY:
- O(N * M * K), where N is the number of rows, M is the number of columns, and K is the number of operations. Each operation may trigger a union operation, which takes nearly constant time.

SPACE COMPLEXITY:
- O(N * M), where N is the number of rows and M is the number of columns. Additional space is required for the Disjoint Set and the visited array.

EXAMPLE USAGE:
Solution sol;
int n = 3, m = 3;
vector<vector<int>> operators = {{0, 0}, {0, 1}, {1, 2}, {2, 1}};
vector<int> result = sol.numOfIslands(n, m, operators);
// result will contain the island count after each operation.
*/
