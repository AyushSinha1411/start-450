/*
EXAMPLE:
Input: arr = {1, 2, 3, 3}, target = 6
Output: 3
Explanation: The subsets that sum up to 6 are {1, 2, 3}, {1, 2, 3}, and {3, 3}.

QUESTION:
Given an array 'num' of size 'n' and a target sum 'k', find the number of subsets that sum up to 'k'.

APPROACH:
1. Use three approaches to solve the problem:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Function to count the number of subsets with a given sum using memoization
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base case for edge case: If we reach the first element
    if (ind == 0) {
        // Edge case: If target is 0 and arr[0] is also 0
        if (target == 0 && arr[0] == 0)
            return 2;
        // If target is 0 or equals to arr[0], return 1
        if (target == 0 || target == arr[0])
            return 1;
        // Otherwise, return 0
        return 0;
    }

    // If the result for this state is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Recursive cases
    int notTaken = findWaysUtil(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the DP table and return
    return dp[ind][target] = notTaken + taken;
}

// Function to count the number of subsets with a given sum
int findWays(vector<int>& num, int k) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findWaysUtil(n - 1, k, num, dp);
}

// Function to count the number of subsets with a given sum using tabulation
int findWaysTabulation(vector<int>& num, int k) {
    int n = num.size();

    // Create a 2D DP table with dimensions n x k+1, initialized with zeros
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // Base case: If the target sum is 0, there is one valid subset (the empty subset)
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    // Initialize the first row based on the first element of the array
    if (num[0] <= k) {
        dp[0][num[0]] = 1;
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            // Exclude the current element
            int notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target) {
                taken = dp[ind - 1][target - num[ind]];
            }

            // Update the DP table
            dp[ind][target] = notTaken + taken;
        }
    }

    // The final result is in the last cell of the DP table
    return dp[n - 1][k];
}

// Function to count the number of subsets with a given sum using space-optimized approach
int findWaysOptimized(vector<int>& num, int k) {
    int n = num.size();

    // Initialize a vector 'prev' to represent the previous row of the DP table
    vector<int> prev(k + 1, 0);

    // Base case: If the target sum is 0, there is one valid subset (the empty subset)
    prev[0] = 1;

    // Initialize the first row based on the first element of the array
    if (num[0] <= k) {
        prev[num[0]] = 1;
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        // Create a vector 'cur' to represent the current row of the DP table
        vector<int> cur(k + 1, 0);

        cur[0] = 1;

        for (int target = 1; target <= k; target++) {
            // Exclude the current element
            int notTaken = prev[target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target) {
                taken = prev[target - num[ind]];
            }

            // Update the current row of the DP table
            cur[target] = notTaken + taken;
        }

        // Set 'cur' as 'prev' for the next iteration
        prev = cur;
    }

    // The final result is in the last cell of the 'prev' vector
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
vector<int> arr = {1, 2, 3, 3};
int target = 6;
int resultMemoization = findWaysMemoization(arr, target); // Using memoization
int resultTabulation = findWaysTabulation(arr, target); // Using tabulation
int resultOptimized = findWaysOptimized(arr, target); // Using space-optimized approach
*/
