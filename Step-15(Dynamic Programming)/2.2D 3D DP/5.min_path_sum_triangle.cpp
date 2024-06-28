/*
EXAMPLE:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]], n = 4
Output: 11
Explanation: The minimum path sum from top to bottom is 11.
The path is: 2 -> 3 -> 5 -> 1.

QUESTION:
Given a triangle array of n rows, find the minimum path sum from top to bottom. At each step, you may move to adjacent numbers on the row below.

APPROACH:
1. Use dynamic programming to calculate the minimum path sum for each cell.
2. Initialize the base cases for the bottom row.
3. Use a memoization table for the recursive approach and fill the DP table iteratively for the tabulation approach.
4. Use a space-optimized approach to reduce space complexity by only storing the current and previous row's results.

CODE:
*/

// Recursive approach with memoization
int minimumPathSumUtil(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp) {
    // If the result for this cell is already calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If we're at the bottom row, return the value of the current cell
    if (i == n - 1)
        return triangle[i][j];

    // Calculate the sum of two possible paths: going down and going diagonally
    int down = triangle[i][j] + minimumPathSumUtil(i + 1, j, triangle, n, dp);
    int diagonal = triangle[i][j] + minimumPathSumUtil(i + 1, j + 1, triangle, n, dp);

    // Store the minimum of the two paths in the dp table and return it
    return dp[i][j] = min(down, diagonal);
}

// Function to find the minimum path sum in the given triangle
int minimumPathSumRecursive(vector<vector<int>> &triangle, int n) {
    // Create a memoization table to store computed results
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // Call the recursive function to find the minimum path sum
    return minimumPathSumUtil(0, 0, triangle, n, dp);
}

// Tabulation approach
int minimumPathSumTabulation(vector<vector<int>> &triangle, int n) {
    // Create a 2D DP (dynamic programming) array to store minimum path sums
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize the bottom row of dp with the values from the triangle
    for (int j = 0; j < n; j++) {
        dp[n - 1][j] = triangle[n - 1][j];
    }

    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            // Store the minimum of the two possible paths in dp
            dp[i][j] = min(down, diagonal);
        }
    }

    // The top-left cell of dp now contains the minimum path sum
    return dp[0][0];
}

// Space-optimized approach
int minimumPathSumOptimized(vector<vector<int>> &triangle, int n) {
    // Create two arrays to store the current and previous row values
    vector<int> front(n, 0); // Represents the previous row
    vector<int> cur(n, 0);   // Represents the current row
    
    // Initialize the front array with values from the last row of the triangle
    for (int j = 0; j < n; j++) {
        front[j] = triangle[n - 1][j];
    }
    
    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];
            
            // Store the minimum of the two possible paths in the current row
            cur[j] = min(down, diagonal);
        }
        // Update the front array with the values from the current row
        front = cur;
    }
    
    // The front array now contains the minimum path sum from the top to the bottom of the triangle
    return front[0];
}

/*
TIME COMPLEXITY:
- All approaches: O(n^2), where n is the number of rows in the triangle. Each cell is processed once.

SPACE COMPLEXITY:
- Recursive approach with memoization: O(n^2) for the dp array.
- Tabulation approach: O(n^2) for the dp array.
- Space-optimized approach: O(n) for the current and previous row arrays.

EXAMPLE USAGE:
vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
int n = 4;
int resultRecursive = minimumPathSumRecursive(triangle, n); // Minimum path sum using recursive approach
int resultTabulation = minimumPathSumTabulation(triangle, n); // Minimum path sum using tabulation approach
int resultOptimized = minimumPathSumOptimized(triangle, n); // Minimum path sum using space-optimized approach
*/
