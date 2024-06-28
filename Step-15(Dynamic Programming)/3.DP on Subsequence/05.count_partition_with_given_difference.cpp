/*
EXAMPLE:
Input: arr = {1, 2, 3, 3}, d = 3
Output: 3
Explanation: The subsets with the difference of 3 are: {1, 3}, {2, 3}, and {1, 2, 3}.

QUESTION:
Given an array 'arr' of size 'n' and an integer 'd', find the number of ways to partition the array into two subsets such that the absolute difference of their sums is equal to 'd'.

APPROACH:
1. Use three approaches to solve the problem:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Function to solve the subset sum problem with memoization
int mod = (int)1e9 + 7;

int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base case: If we have reached the first element in 'arr'
    if (ind == 0) {
        if (target == 0 && arr[0] == 0)
            return 2; // Two ways: pick and not pick
        if (target == 0 || target == arr[0])
            return 1; // One way: either pick or not pick
        return 0;
    }

    // If the result for this state is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Recursive cases
    // 1. Exclude the current element
    int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);

    // 2. Include the current element if it doesn't exceed the target
    int taken = 0;
    if (arr[ind] <= target)
        taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);

    // Store the result in the DP table and return
    return dp[ind][target] = (notTaken + taken) % mod;
}

// Function to check if it's possible to partition the array into two subsets with equal sum
int countPartitions(int d, vector<int>& arr) {
    int n = arr.size();
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - d < 0 || (totSum - d) % 2 == 1) return 0;

    int s2 = (totSum - d) / 2;

    // Initialize a DP table for memoization
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));

    // Call the recursive function to check if it's possible to partition
    return countPartitionsUtil(n - 1, s2, arr, dp);
}

// Function to find the number of subsets with a given sum using tabulation
int findWaysTabulation(vector<int>& num, int tar) {
    int n = num.size();

    // Create a 2D DP table with dimensions n x tar+1, initialized with zeros
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    // Base case: If the target sum is 0, there is one valid subset (the empty subset)
    if (num[0] == 0) dp[0][0] = 2; // Two ways: pick and not pick
    else dp[0][0] = 1; // One way: not pick

    // Base case: If the first element is less than or equal to the target, set dp[0][num[0]] to 1
    if (num[0] != 0 && num[0] <= tar) dp[0][num[0]] = 1;

    // Fill the DP array iteratively
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= tar; target++) {
            // Exclude the current element
            int notTaken = dp[ind - 1][target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            // Store the result in the DP array for the current subproblem
            dp[ind][target] = (notTaken + taken) % mod;
        }
    }

    // The final result is in the last cell of the DP table
    return dp[n - 1][tar];
}

// Function to count the number of partitions
int countPartitionsTabulation(int n, int d, vector<int>& arr) {
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - d < 0 || (totSum - d) % 2 == 1) return 0;

    return findWaysTabulation(arr, (totSum - d) / 2);
}

// Function to find the number of subsets with a given sum using space-optimized approach
int findWaysOptimized(vector<int>& num, int tar) {
    int n = num.size();

    // Initialize a vector 'prev' to represent the previous row of the DP table
    vector<int> prev(tar + 1, 0);

    // Base case: If the target sum is 0, there is one valid subset (the empty subset)
    if (num[0] == 0) prev[0] = 2; // Two ways: pick and not pick
    else prev[0] = 1; // One way: not pick

    // Base case: If the first element is less than or equal to the target, set prev[num[0]] to 1
    if (num[0] != 0 && num[0] <= tar) prev[num[0]] = 1;

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        // Create a vector 'cur' to represent the current row of the DP table
        vector<int> cur(tar + 1, 0);

        for (int target = 0; target <= tar; target++) {
            // Exclude the current element
            int notTaken = prev[target];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (num[ind] <= target)
                taken = prev[target - num[ind]];

            // Update the current row of the DP table
            cur[target] = (notTaken + taken) % mod;
        }

        // Set 'cur' as 'prev' for the next iteration
        prev = cur;
    }

    // The final result is in the last cell of the 'prev' vector
    return prev[tar];
}

// Function to count the number of partitions using space-optimized approach
int countPartitionsOptimized(int n, int d, vector<int>& arr) {
    int totSum = 0;

    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - d < 0 || (totSum - d) % 2 == 1) return 0;

    return findWaysOptimized(arr, (totSum - d) / 2);
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
int d = 3;
int resultMemoization = countPartitions(d, arr); // Using memoization
int resultTabulation = countPartitionsTabulation(arr.size(), d, arr); // Using tabulation
int resultOptimized = countPartitionsOptimized(arr.size(), d, arr); // Using space-optimized approach
*/
