/*
QUESTION:
Given a 2D grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are surrounded by water.

EXAMPLE:
Input:
grid = [
  ['1', '1', '1', '0', '0'],
  ['1', '1', '0', '0', '0'],
  ['1', '1', '0', '1', '1'],
  ['0', '0', '0', '1', '1']
]

Output: 2

APPROACH:
1. Use BFS to traverse each connected component of '1's (islands).
2. Mark each visited cell to avoid revisiting.
3. Count the number of BFS executions as the number of islands.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    // Helper function to perform BFS traversal
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid) {
        // Mark the initial cell as visited
        vis[row][col] = 1;
        
        // Queue to facilitate BFS
        queue<pair<int, int>> q;
        q.push({row, col});
        
        int n = grid.size();
        int m = grid[0].size();
        
        // Directions array for 8 possible movements (left, right, up, down, and diagonals)
        int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        // BFS traversal
        while (!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();
            
            // Explore all 8 possible directions
            for (int i = 0; i < 8; i++) {
                int newRow = curRow + directions[i][0];
                int newCol = curCol + directions[i][1];
                
                // Check if the new cell is valid and is an unvisited land
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
                    && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
public:
    // Function to find the number of islands
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Create a visited array initialized to 0
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int count = 0;
        
        // Traverse each cell in the grid
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // If the cell is unvisited and is a land
                if (!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        
        // Return the number of islands
        return count;
    }
};

/*
EXAMPLE USAGE:
vector<vector<char>> grid = {
  {'1', '1', '1', '0', '0'},
  {'1', '1', '0', '0', '0'},
  {'1', '1', '0', '1', '1'},
  {'0', '0', '0', '1', '1'}
};
Solution sol;
int result = sol.numIslands(grid);
// Output: 2

TIME COMPLEXITY:
- O(N * M), where N is the number of rows and M is the number of columns in the grid. Each cell is visited once.

SPACE COMPLEXITY:
- O(N * M), for the visited array and the BFS queue.
*/
