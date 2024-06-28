/*
EXAMPLE:
Input: arr = {1, 2, 3, 4}, k = 5
Output: true
Explanation: There is a subset {2, 3} with a sum equal to 5.

QUESTION:
Given an array 'arr' of size 'n' and a target sum 'k', determine if there is a subset of 'arr' with a sum equal to 'k'.

APPROACH:
1. Use dynamic programming to solve the subset sum problem.
2. Implement three approaches:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Recursive function to check if there is a subset of 'arr' with a sum equal to 'target'
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // If the target sum is 0, we have found a subset
    if (target == 0)
        return true;

    // If we have reached the first element in 'arr'
    if (ind == 0)
        return arr[0] == target;

    // If the result for this subproblem has already been computed, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Try not taking the current element into the subset
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    // Try taking the current element into the subset if it doesn't exceed the target
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the dp array to avoid recomputation
    return dp[ind][target] = notTaken || taken;
}

// Function to check if there is a subset of 'arr' with a sum equal to 'k' using memoization
bool subsetSumToK(int n, int k, vector<int>& arr) {
    // Initialize a 2D DP array for memoization
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    // Call the recursive subsetSumUtil function
    return subsetSumUtil(n - 1, k, arr, dp);
}

// Function to check if there is a subset of 'arr' with a sum equal to 'k' using tabulation
bool subsetSumToKTabulation(int n, int k, vector<int>& arr) {
    // Initialize a 2D DP array with dimensions (n x k+1) to store subproblem results
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    // Fill the DP array iteratively
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = dp[ind - 1][target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = dp[ind - 1][target - arr[ind]];
            }

            // Store the result in the DP array for the current subproblem
            dp[ind][target] = notTaken || taken;
        }
    }

    // The final result is stored in dp[n-1][k]
    return dp[n - 1][k];
}

// Function to check if there is a subset of 'arr' with a sum equal to 'k' using space-optimized approach
bool subsetSumToKOptimized(int n, int k, vector<int>& arr) {
    // Initialize a vector 'prev' to store the previous row of the DP table
    vector<bool> prev(k + 1, false);

    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    prev[0] = true;

    // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    // Iterate through the elements of 'arr' and update the DP table
    for (int ind = 1; ind < n; ind++) {
        // Initialize a new row 'cur' to store the current state of the DP table
        vector<bool> cur(k + 1, false);

        // Base case: If the target sum is 0, we can achieve it by taking no elements
        cur[0] = true;

        for (int target = 1; target <= k; target++) {
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = prev[target];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }

            // Store the result in the current DP table row for the current subproblem
            cur[target] = notTaken || taken;
        }

        // Update 'prev' with the current row 'cur' for the next iteration
        prev = cur;
    }

    // The final result is stored in prev[k]
    return prev[k];
}

/*
TIME COMPLEXITY:
- All approaches: O(n * k), where n is the size of the array and k is the target sum.

SPACE COMPLEXITY:
- Recursive approach with memoization: O(n * k) for the dp array.
- Tabulation approach: O(n * k) for the dp array.
- Space-optimized approach: O(k) for the previous and current row arrays.

EXAMPLE USAGE:
vector<int> arr = {1, 2, 3, 4};
int k = 5;
bool resultMemoization = subsetSumToK(arr.size(), k, arr); // Using memoization
bool resultTabulation = subsetSumToKTabulation(arr.size(), k, arr); // Using tabulation
bool resultOptimized = subsetSumToKOptimized(arr.size(), k, arr); // Using space-optimized approach
*/
