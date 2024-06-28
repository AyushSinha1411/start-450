/*
EXAMPLE:
Input: matrix = [[10, 10, 2, 0, 20, 4], [1, 0, 0, 30, 2, 5], [0, 10, 4, 0, 2, 0], [1, 0, 2, 20, 0, 4]]
Output: 74
Explanation: The maximum path sum is 10 → 10 → 0 → 30 → 20 → 4, which equals 74.

QUESTION:
Given an n x m matrix, find the maximum path sum starting from any cell in the first row and ending at any cell in the last row. The path can only move to the cell directly below or diagonally left/right below.

APPROACH:
1. Use dynamic programming to calculate the maximum path sum for each cell.
2. Create a memoization table to store computed results.
3. Use a space-optimized approach to reduce space complexity by only storing the current and previous rows.

CODE:
*/

// Recursive approach with memoization
int getMaxUtil(int i, int j, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    if (j < 0 || j >= m) return -1e9; // Out of bounds
    if (i == 0) return matrix[0][j]; // Base case: top row

    if (dp[i][j] != -1) return dp[i][j]; // Return memoized result

    int up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix, dp);

    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal)); // Memoize and return the result
}

int getMaxPathSumMemo(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1)); // Memoization table

    int maxi = INT_MIN;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, getMaxUtil(n - 1, j, m, matrix, dp)); // Calculate max path sum for each cell in the last row
    }

    return maxi;
}

// Tabulation approach
int getMaxPathSumTabulation(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j]; // Initialize the first row
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + dp[i - 1][j];
            int leftDiagonal = (j > 0) ? matrix[i][j] + dp[i - 1][j - 1] : -1e9;
            int rightDiagonal = (j < m - 1) ? matrix[i][j] + dp[i - 1][j + 1] : -1e9;

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal)); // Calculate the max path sum for the current cell
        }
    }

    int maxi = INT_MIN;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, dp[n - 1][j]); // Find the maximum path sum in the last row
    }

    return maxi;
}

// Space-optimized approach
int getMaxPathSumOptimized(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, 0); // Previous row
    vector<int> cur(m, 0);  // Current row

    for (int j = 0; j < m; j++) {
        prev[j] = matrix[0][j]; // Initialize the first row
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + prev[j];
            int leftDiagonal = (j > 0) ? matrix[i][j] + prev[j - 1] : -1e9;
            int rightDiagonal = (j < m - 1) ? matrix[i][j] + prev[j + 1] : -1e9;

            cur[j] = max(up, max(leftDiagonal, rightDiagonal)); // Calculate the max path sum for the current cell
        }
        prev = cur; // Update previous row with current row
    }

    int maxi = INT_MIN;
    for (int j = 0; j < m; j++) {
        maxi = max(maxi, prev[j]); // Find the maximum path sum in the last row
    }

    return maxi;
}

/*
TIME COMPLEXITY:
- All approaches: O(n * m), where n is the number of rows and m is the number of columns. Each cell is processed once.

SPACE COMPLEXITY:
- Memoization: O(n * m) for the dp array.
- Tabulation: O(n * m) for the dp array.
- Space-optimized: O(m) for the current and previous row arrays.

EXAMPLE USAGE:
vector<vector<int>> matrix = {{10, 10, 2, 0, 20, 4}, {1, 0, 0, 30, 2, 5}, {0, 10, 4, 0, 2, 0}, {1, 0, 2, 20, 0, 4}};
int resultMemo = getMaxPathSumMemo(matrix); // Maximum path sum using memoization
int resultTabulation = getMaxPathSumTabulation(matrix); // Maximum path sum using tabulation
int resultOptimized = getMaxPathSumOptimized(matrix); // Maximum path sum using space-optimized approach
*/
