/*
EXAMPLE:
Input: n = 3, m = 3, matrix = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}
Output: 7
Explanation: The minimum path sum from (0, 0) to (2, 2) is 7.
The path is: 1 -> 3 -> 1 -> 1 -> 1.

QUESTION:
Given a grid (matrix) of size n x m, find the minimum path sum from the top-left cell (0, 0) to the bottom-right cell (n-1, m-1). You can only move right or down.

APPROACH:
1. Use dynamic programming to calculate the minimum path sum for each cell.
2. Initialize the base cases for the starting cell (0, 0).
3. Use a memoization table for the recursive approach and fill the DP table iteratively for the tabulation approach.
4. Use a space-optimized approach to reduce space complexity by only storing the current and previous row's results.

CODE:
*/

// Recursive approach with memoization
int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    // Base cases
    if (i == 0 && j == 0)
        return matrix[0][0]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
    if (i < 0 || j < 0)
        return INT_MAX; // If we go out of bounds, return a large value to avoid considering this path
    if (dp[i][j] != -1)
        return dp[i][j]; // If the result is already computed, return it

    // Calculate the minimum sum path by considering moving up and moving left
    int up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
    int left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);

    // Store the result in the DP table and return it
    return dp[i][j] = min(up, left);
}

// Main function to find the minimum sum path in the matrix
int minSumPathRecursive(int n, int m, vector<vector<int>> &matrix) {
    vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
    return minSumPathUtil(n - 1, m - 1, matrix, dp); // Start from the bottom-right corner
}

// Tabulation approach
int minSumPathTabulation(int n, int m, vector<vector<int>> &matrix) {
    vector<vector<int>> dp(n, vector<int>(m, 0)); // Initialize a DP table to store minimum path sums

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else {
                // Calculate the minimum path sum considering moving up and moving left
                int up = matrix[i][j];
                if (i > 0)
                    up += dp[i - 1][j]; // Include the minimum path sum from above
                else
                    up += INT_MAX; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0)
                    left += dp[i][j - 1]; // Include the minimum path sum from the left
                else
                    left += INT_MAX; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in dp[i][j]
                dp[i][j] = min(up, left);
            }
        }
    }

    // The final result is stored in dp[n-1][m-1], which represents the destination
    return dp[n - 1][m - 1];
}

// Space-optimized approach
int minSumPathOptimized(int n, int m, vector<vector<int>> &matrix) {
    vector<int> prev(m, 0); // Initialize a vector to store the previous row's minimum path sums

    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0); // Initialize a temporary vector for the current row
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                temp[j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
            else {
                // Calculate the minimum path sum considering moving up and moving left
                int up = matrix[i][j];
                if (i > 0)
                    up += prev[j]; // Include the minimum path sum from above (previous row)
                else
                    up += INT_MAX; // A large value if moving up is not possible (out of bounds)

                int left = matrix[i][j];
                if (j > 0)
                    left += temp[j - 1]; // Include the minimum path sum from the left (current row)
                else
                    left += INT_MAX; // A large value if moving left is not possible (out of bounds)

                // Store the minimum path sum in temp[j]
                temp[j] = min(up, left);
            }
        }
        prev = temp; // Update the previous row with the current row
    }

    // The final result is stored in prev[m-1], which represents the destination in the last column
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
vector<vector<int>> matrix = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
int resultRecursive = minSumPathRecursive(n, m, matrix); // Minimum path sum using recursive approach
int resultTabulation = minSumPathTabulation(n, m, matrix); // Minimum path sum using tabulation approach
int resultOptimized = minSumPathOptimized(n, m, matrix); // Minimum path sum using space-optimized approach
*/
