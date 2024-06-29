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

// Function to solve the problem using dynamic programming
int solveUtil(int ind, vector<int>& arr, vector<int>& dp) {
    // If the result for this index is already computed, return it
    if (dp[ind] != -1)
        return dp[ind];

    // Base cases
    if (ind == 0) 
        return arr[ind];
    if (ind < 0)  
        return 0;

    // Choose the current element or skip it, and take the maximum
    int pick = arr[ind] + solveUtil(ind - 2, arr, dp); // Choosing the current element
    int nonPick = 0 + solveUtil(ind - 1, arr, dp);      // Skipping the current element

    // Store the result in the DP table and return it
    return dp[ind] = max(pick, nonPick);
}

// Function to initiate the solving process
int solve(int n, vector<int>& arr) {
    vector<int> dp(n, -1); // Initialize the DP table with -1
    return solveUtil(n - 1, arr, dp); // Start solving from the last element
}


// Tabulation approach
// Function to solve the problem using dynamic programming
int solveUtil(int n, vector<int>& arr, vector<int>& dp) {
    // Base case: If there are no elements in the array, return 0
    dp[0] = arr[0];
    
    // Iterate through the elements of the array
    for (int i = 1; i < n; i++) {
        // Calculate the maximum value by either picking the current element
        // or not picking it (i.e., taking the maximum of dp[i-2] + arr[i] and dp[i-1])
        int pick = arr[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = dp[i - 1];
        
        // Store the maximum value in the dp array
        dp[i] = max(pick, nonPick);
    }
    
    // The last element of the dp array will contain the maximum sum
    return dp[n - 1];
}

// Function to initiate the solving process
int solve(int n, vector<int>& arr) {
    vector<int> dp(n, 0); // Initialize dp array with 0
    return solveUtil(n, arr, dp);
}


// Space-optimized approach
// Function to solve the problem using dynamic programming
int solve(int n, vector<int>& arr) {
    int prev = arr[0];   // Initialize the maximum sum ending at the previous element
    int prev2 = 0;       // Initialize the maximum sum ending two elements ago
    
    for (int i = 1; i < n; i++) {
        int pick = arr[i];  // Maximum sum if we pick the current element
        if (i > 1)
            pick += prev2;  // Add the maximum sum two elements ago
        
        int nonPick = 0 + prev;  // Maximum sum if we don't pick the current element
        
        int cur_i = max(pick, nonPick);  // Maximum sum ending at the current element
        prev2 = prev;   // Update the maximum sum two elements ago
        prev = cur_i;   // Update the maximum sum ending at the previous element
    }
    
    return prev;  // Return the maximum sum
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
