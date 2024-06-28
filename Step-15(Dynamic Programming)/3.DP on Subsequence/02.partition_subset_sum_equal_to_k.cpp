/*
EXAMPLE:
Input: arr = {1, 5, 11, 5}
Output: true
Explanation: The array can be partitioned as {1, 5, 5} and {11}, both having equal sum 11.

QUESTION:
Given an array 'arr' of size 'n', determine if it can be partitioned into two subsets such that the sum of elements in both subsets is equal.

APPROACH:
1. Calculate the total sum of the array.
2. If the total sum is odd, it cannot be partitioned into two equal subsets.
3. If the total sum is even, check if there exists a subset with sum equal to half of the total sum using dynamic programming.
4. Implement three approaches:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Recursive function to check if there is a subset of 'arr' with a sum equal to 'target'
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base case: If the target sum is 0, we found a valid partition
    if (target == 0)
        return true;

    // Base case: If we have considered all elements and the target is still not 0, return false
    if (ind == 0)
        return arr[0] == target;

    // If the result for this state is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Recursive cases
    // 1. Exclude the current element
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    // 2. Include the current element if it doesn't exceed the target
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the DP table and return
    return dp[ind][target] = notTaken || taken;
}

// Function to check if the array can be partitioned into two equal subsets using memoization
bool canPartitionMemoization(int n, vector<int>& arr) {
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if (totSum % 2 == 1)
        return false;
    else {
        int k = totSum / 2;

        // Create a DP table with dimensions n x k+1 and initialize with -1
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        // Call the subsetSumUtil function to check if it's possible to partition
        return subsetSumUtil(n - 1, k, arr, dp);
    }
}

// Function to check if the array can be partitioned into two equal subsets using tabulation
bool canPartitionTabulation(int n, vector<int>& arr) {
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if (totSum % 2 == 1)
        return false;
    else {
        int k = totSum / 2;

        // Create a DP table with dimensions n x k+1, initialized with false
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

        // Base case: If the target sum is 0, it can be achieved by not selecting any elements
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Initialize the first row based on the first element of the array
        if (arr[0] <= k)
            dp[0][arr[0]] = true;

        // Fill in the DP table using a bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                // Exclude the current element
                bool notTaken = dp[ind - 1][target];

                // Include the current element if it doesn't exceed the target
                bool taken = false;
                if (arr[ind] <= target)
                    taken = dp[ind - 1][target - arr[ind]];

                // Update the DP table
                dp[ind][target] = notTaken || taken;
            }
        }

        // The final result is in the last cell of the DP table
        return dp[n - 1][k];
    }
}

// Function to check if the array can be partitioned into two equal subsets using space-optimized approach
bool canPartitionOptimized(int n, vector<int>& arr) {
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if (totSum % 2 == 1)
        return false;
    else {
        int k = totSum / 2;

        // Create a vector to represent the previous row of the DP table
        vector<bool> prev(k + 1, false);

        // Base case: If the target sum is 0, it can be achieved by not selecting any elements
        prev[0] = true;

        // Initialize the first row based on the first element of the array
        if (arr[0] <= k)
            prev[arr[0]] = true;

        // Fill in the DP table using a bottom-up approach
        for (int ind = 1; ind < n; ind++) {
            // Create a vector to represent the current row of the DP table
            vector<bool> cur(k + 1, false);
            cur[0] = true;

            for (int target = 1; target <= k; target++) {
                // Exclude the current element
                bool notTaken = prev[target];

                // Include the current element if it doesn't exceed the target
                bool taken = false;
                if (arr[ind] <= target)
                    taken = prev[target - arr[ind]];

                // Update the current row of the DP table
                cur[target] = notTaken || taken;
            }

            // Set the current row as the previous row for the next iteration
            prev = cur;
        }

        // The final result is in the last cell of the previous row of the DP table
        return prev[k];
    }
}

/*
TIME COMPLEXITY:
- All approaches: O(n * k), where n is the size of the array and k is the target sum (totSum / 2).

SPACE COMPLEXITY:
- Recursive approach with memoization: O(n * k) for the dp array.
- Tabulation approach: O(n * k) for the dp array.
- Space-optimized approach: O(k) for the previous and current row arrays.

EXAMPLE USAGE:
vector<int> arr = {1, 5, 11, 5};
bool resultMemoization = canPartitionMemoization(arr.size(), arr); // Using memoization
bool resultTabulation = canPartitionTabulation(arr.size(), arr); // Using tabulation
bool resultOptimized = canPartitionOptimized(arr.size(), arr); // Using space-optimized approach
*/
