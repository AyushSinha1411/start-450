/*
EXAMPLE:
Input: n = 3, m = 3, maze = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}}
Output: 2
Explanation: The number of paths from (0, 0) to (2, 2) while avoiding obstacles is 2.
The possible paths are: 
1. (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2)
2. (0,0) -> (1,0) -> (2,0) -> (2,1) -> (2,2)

QUESTION:
Given a grid of size n x m with some obstacles (represented by -1), find the number of ways to reach the bottom-right cell (n-1, m-1) from the top-left cell (0, 0). You can move only right or down.

APPROACH:
1. Use dynamic programming to count the number of ways to reach each cell, taking obstacles into account.
2. Initialize the base cases for the first cell (0, 0).
3. Use a memoization table for the recursive approach and fill the DP table iteratively for the tabulation approach.
4. Use a space-optimized approach to reduce space complexity by only storing the current and previous row's results.

CODE:
*/

// Recursive approach with memoization
int mazeObstaclesUtil(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp) {
    // Base cases
    if (i > 0 && j > 0 && maze[i][j] == -1) return 0; // If there's an obstacle at (i, j), return 0
    if (i == 0 && j == 0) return 1; // If we reach the starting point (0, 0), return 1
    if (i < 0 || j < 0) return 0; // If we go out of bounds, return 0
    if (dp[i][j] != -1) return dp[i][j]; // If the result is already computed, return it

    // Recursive calls to explore paths from (i, j) to (0, 0)
    int up = mazeObstaclesUtil(i - 1, j, maze, dp);
    int left = mazeObstaclesUtil(i, j - 1, maze, dp);

    // Store the result in the DP table and return it
    return dp[i][j] = up + left;
}

// Main function to count paths with obstacles in a maze
int mazeObstaclesRecursive(int n, int m, vector<vector<int>> &maze) {
    vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
    return mazeObstaclesUtil(n - 1, m - 1, maze, dp); // Start from the bottom-right corner
}

// Tabulation approach
int mazeObstaclesTabulation(int n, int m, vector<vector<int>> &maze) {
    vector<vector<int>> dp(n, vector<int>(m, 0)); // DP table to store results

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Base conditions
            if (maze[i][j] == -1) {
                dp[i][j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
            } else if (i == 0 && j == 0) {
                dp[i][j] = 1; // If we are at the starting point, there is one path to it
            } else {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = up + left; // Total number of paths to reach (i, j)
            }
        }
    }

    // The final result is stored in dp[n-1][m-1], which represents the destination
    return dp[n - 1][m - 1];
}

// Space-optimized approach
int mazeObstaclesOptimized(int n, int m, vector<vector<int>> &maze) {
    vector<int> prev(m, 0); // Initialize a vector to store the previous row's path counts

    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0); // Initialize a temporary vector for the current row
        for (int j = 0; j < m; j++) {
            // Base conditions
            if (maze[i][j] == -1) {
                temp[j] = 0; // If there's an obstacle at (i, j), no paths can pass through it
            } else if (i == 0 && j == 0) {
                temp[j] = 1; // If we are at the starting point, there is one path to it
            } else {
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? temp[j - 1] : 0;
                temp[j] = up + left; // Total number of paths to reach (i, j)
            }
        }
        prev = temp; // Update the previous row with the current row
    }

    // The final result is stored in prev[m-1], which represents the destination in the last row
    return prev[m - 1];
}

/*
TIME COMPLEXITY:
- All approaches: O(n * m), where n is the number of rows and m is the number of columns. Each cell is processed once.

SPACE COMPLEXITY:
- Recursive approach with memoization: O(n * m) for the dp array.
- Tabulation approach: O(n * m) for the dp array.
- Space-optimized approach: O(m) for the current and previous row arrays.

EXAMPLE USAGE:
int n = 3, m = 3;
vector<vector<int>> maze = {{0, 0, 0}, {0, -1, 0}, {0, 0, 0}};
int resultRecursive = mazeObstaclesRecursive(n, m, maze); // Number of ways using recursive approach
int resultTabulation = mazeObstaclesTabulation(n, m, maze); // Number of ways using tabulation approach
int resultOptimized = mazeObstaclesOptimized(n, m, maze); // Number of ways using space-optimized approach
*/
