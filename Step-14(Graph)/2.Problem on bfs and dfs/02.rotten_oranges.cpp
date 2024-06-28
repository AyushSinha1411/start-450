/*
QUESTION:
Given a grid representing a field of oranges, where:
- `0` represents an empty cell,
- `1` represents a fresh orange,
- `2` represents a rotten orange,
return the minimum number of days required for all fresh oranges to become rotten. If it's impossible, return `-1`.

EXAMPLE:
Input:
grid = {
    {2, 1, 1},
    {1, 1, 0},
    {0, 1, 1}
}
Output:
4

APPROACH:
1. Initialize the total count of cells with oranges and a queue to store the initial positions of rotten oranges.
2. Perform a BFS to spread the rot from rotten oranges to adjacent fresh oranges.
3. Track the number of days required to rot all oranges.
4. After BFS, check if the total number of oranges processed matches the initial count of oranges to determine if it's possible to rot all oranges.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    // Check if the grid is empty
    if (grid.empty()) return 0;

    int m = grid.size();    // Number of rows
    int n = grid[0].size(); // Number of columns
    int days = 0;           // Counter for days
    int tot = 0;            // Total count of cells with oranges
    int cnt = 0;            // Count of processed oranges
    queue<pair<int, int>> rotten; // Queue for BFS

    // Initialize the grid by counting oranges and adding rotten ones to the queue
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != 0) tot++; // Count all cells with oranges
            if (grid[i][j] == 2) rotten.push({i, j}); // Add rotten oranges to the queue
        }
    }

    // Direction vectors for exploring adjacent cells
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    // Perform BFS to spread the rot
    while (!rotten.empty()) {
        int k = rotten.size();
        cnt += k; // Increase processed oranges count by the number of rotten oranges in the queue
        while (k--) {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue; // Skip invalid cells
                grid[nx][ny] = 2; // Rot the fresh orange
                rotten.push({nx, ny}); // Add newly rotten orange to the queue
            }
        }
        if (!rotten.empty()) days++; // Increment the day count if there are still oranges to process
    }

    // If the total number of processed oranges matches the initial count, return the days required, else return -1
    return tot == cnt ? days : -1;
}

/*
EXAMPLE USAGE:
vector<vector<int>> grid = {
    {2, 1, 1},
    {1, 1, 0},
    {0, 1, 1}
};
int result = orangesRotting(grid); // Returns 4

TIME COMPLEXITY:
- O(m * n), where m is the number of rows and n is the number of columns. Each cell is processed once.

SPACE COMPLEXITY:
- O(m * n) for the queue used in BFS and the auxiliary space to store grid state.
*/
