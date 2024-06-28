/*
EXAMPLE:
Input: m = 3, n = 3
Output: 6
Explanation: The number of ways to reach the bottom-right cell (2, 2) from the top-left cell (0, 0) is 6.
The possible paths are: 
1. (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2)
2. (0,0) -> (0,1) -> (1,1) -> (1,2) -> (2,2)
3. (0,0) -> (0,1) -> (1,1) -> (2,1) -> (2,2)
4. (0,0) -> (1,0) -> (1,1) -> (1,2) -> (2,2)
5. (0,0) -> (1,0) -> (1,1) -> (2,1) -> (2,2)
6. (0,0) -> (1,0) -> (2,0) -> (2,1) -> (2,2)

QUESTION:
Given a grid of size m x n, find the number of ways to reach the bottom-right cell (m-1, n-1) from the top-left cell (0, 0) by moving only right or down.

APPROACH:
1. Use dynamic programming to count the number of ways to reach each cell.
2. Initialize the base cases for the first cell (0, 0).
3. Use a memoization table for the recursive approach and fill the DP table iteratively for the tabulation approach.
4. Use a space-optimized approach to reduce space complexity by only storing the current and previous row's results.

CODE:
*/

// Recursive approach with memoization
int countWaysUtil(int i, int j, vector<vector<int>>& dp) {
    // Base case: If we reach the top-left corner (0, 0), there is one way.
    if (i == 0 && j == 0)
        return 1;

    // If we go out of bounds, there are no ways.
    if (i < 0 || j < 0)
        return 0;

    // If we have already computed the number of ways for this cell, return it.
    if (dp[i][j] != -1)
        return dp[i][j];

    // Calculate the number of ways by moving up and left recursively.
    int up = countWaysUtil(i - 1, j, dp);
    int left = countWaysUtil(i, j - 1, dp);

    // Store the result in the dp table and return it.
    return dp[i][j] = up + left;
}

// Function to count the number of ways to reach the bottom-right cell (m-1, n-1) from the top-left cell (0, 0) in a grid of size m x n
int countWaysRecursive(int m, int n) {
    // Create a memoization table (dp) to store the results of subproblems.
    vector<vector<int>> dp(m, vector<int>(n, -1));

    // Call the utility function with the bottom-right cell as the starting point.
    return countWaysUtil(m - 1, n - 1, dp);
}

// Tabulation approach
int countWaysTabulation(int m, int n) {
    // Create a DP table to store the number of ways to reach each cell.
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Loop through the grid using two nested loops
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Base case: If we are at the top-left cell (0, 0), there is one way.
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else {
                // Calculate the number of ways by moving up and left.
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;

                // Store the result in the dp table.
                dp[i][j] = up + left;
            }
        }
    }

    // The result is stored in the bottom-right cell (m-1, n-1).
    return dp[m - 1][n - 1];
}

// Space-optimized approach
int countWaysOptimized(int m, int n) {
    // Create a vector to represent the previous row of the grid.
    vector<int> prev(n, 0);

    // Iterate through the rows of the grid.
    for (int i = 0; i < m; i++) {
        // Create a temporary vector to represent the current row.
        vector<int> temp(n, 0);

        // Iterate through the columns of the grid.
        for (int j = 0; j < n; j++) {
            // Base case: If we are at the top-left cell (0, 0), there is one way.
            if (i == 0 && j == 0) {
                temp[j] = 1;
            } else {
                // Calculate the number of ways by moving up and left.
                int up = (i > 0) ? prev[j] : 0;
                int left = (j > 0) ? temp[j - 1] : 0;

                // Store the result in the temp vector.
                temp[j] = up + left;
            }
        }

        // Update the previous row with the values calculated for the current row.
        prev = temp;
    }

    // The result is stored in the last cell of the previous row (n-1).
    return prev[n - 1];
}

/*
TIME COMPLEXITY:
- All approaches: O(m * n), where m is the number of rows and n is the number of columns. Each cell is processed once.

SPACE COMPLEXITY:
- Recursive approach with memoization: O(m * n) for the dp array.
- Tabulation approach: O(m * n) for the dp array.
- Space-optimized approach: O(n) for the current and previous row arrays.

EXAMPLE USAGE:
int m = 3, n = 3;
int resultRecursive = countWaysRecursive(m, n); // Number of ways using recursive approach
int resultTabulation = countWaysTabulation(m, n); // Number of ways using tabulation approach
int resultOptimized = countWaysOptimized(m, n); // Number of ways using space-optimized approach
*/
