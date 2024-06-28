/*
QUESTION:
Given a 2D grid where '0' represents water and '1' represents land, find the number of enclaves. An enclave is a land cell that cannot walk off the boundary of the grid in any number of steps.

EXAMPLE:
Input:
grid = [
    {0, 0, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 1, 0},
    {1, 0, 0, 0}
]
Output:
3

APPROACH:
1. Perform BFS/DFS from the boundary land cells to mark all the reachable land cells as visited.
2. Traverse through the grid to count the number of unvisited land cells, which are the enclaves.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

int numberOfEnclaves(vector<vector<int>> &grid) {
    // Get the grid dimensions
    int n = grid.size(); 
    int m = grid[0].size(); 
    
    // Initialize a visited matrix
    vector<vector<int>> vis(n, vector<int>(m, 0)); 
    queue<pair<int, int>> q; 
    
    // Traverse boundary elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Check for boundary land cells
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if (grid[i][j] == 1) {
                    q.push({i, j}); 
                    vis[i][j] = 1; 
                }
            }
        }
    }
    
    // Direction vectors for moving up, right, down, left
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1}; 
    
    // BFS to mark all reachable land cells
    while (!q.empty()) {
        int row = q.front().first; 
        int col = q.front().second; 
        q.pop(); 
        
        // Traverse all 4 directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 
            
            // Check for valid coordinates and land cell
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1; 
            }
        }
    }
    
    // Count unvisited land cells
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && vis[i][j] == 0) 
                cnt++; 
        }
    }
    
    // Return the number of enclaves
    return cnt; 
}

/*
EXAMPLE USAGE:
vector<vector<int>> grid = {
    {0, 0, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 1, 0},
    {1, 0, 0, 0}
};
int result = numberOfEnclaves(grid);
// Output: 3

TIME COMPLEXITY:
- O(n * m), where n is the number of rows and m is the number of columns. Each cell is processed once.

SPACE COMPLEXITY:
- O(n * m) for the visited matrix and the queue.
*/
