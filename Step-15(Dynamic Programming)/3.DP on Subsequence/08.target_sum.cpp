/*
EXAMPLE:
Input: arr = {1, 1, 2, 3}, target = 1
Output: 3
Explanation: There are three ways to partition the array to achieve the target sum: 
- {1, 3} - {1, 2}
- {1, 2} - {1, 3}
- {2, 3} - {1, 1}

QUESTION:
Given an array of integers 'arr' and a target sum 'target', count the number of ways to partition the array into subsets that differ by the target sum.

APPROACH:
1. Use three approaches to solve the problem:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Function to count partitions of the array into subsets with a given target sum
int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base cases
    if (ind == 0) {
        if (target == 0 && arr[0] == 0)
            return 2; // Two ways to partition: include or exclude the element
        if (target == 0 || target == arr[0])
            return 1; // One way to partition: include or exclude the element
        return 0; // No way to partition
    }
    
    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][target] != -1)
        return dp[ind][target];
        
    // Calculate the number of ways without taking the current element
    int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);
    
    // Calculate the number of ways by taking the current element
    int taken = 0;
    if (arr[ind] <= target)
        taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);
        
    // Store the sum of ways in the DP array and return it
    return dp[ind][target] = (notTaken + taken);
}

// Function to count the number of ways to achieve the target sum using memoization
int targetSum(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for (int i = 0; i < arr.size(); i++) {
        totSum += arr[i];
    }
    
    // Checking for edge cases
    if (totSum - target < 0)
        return 0; // Not possible to achieve the target sum
    if ((totSum - target) % 2 == 1)
        return 0; // The difference between the total sum and target sum must be even
    
    int s2 = (totSum - target) / 2; // Calculate the required sum for each subset
    
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1)); // Initialize DP table
    return countPartitionsUtil(n - 1, s2, arr, dp); // Call the helper function
}

const int mod = (int)1e9 + 7;

// Function to count the number of ways to achieve the target sum using tabulation
int findWays(vector<int> &num, int tar) {
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (num[0] == 0)
        dp[0][0] = 2;  // 2 cases - pick and not pick
    else
        dp[0][0] = 1;  // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;  // 1 case - pick

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= tar; target++) {
            int notTaken = dp[ind - 1][target];
            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];

            dp[ind][target] = (notTaken + taken) % mod;
        }
    }
    return dp[n - 1][tar];
}

// Function to calculate the number of ways to achieve the target sum
int targetSum(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;  // Not possible to achieve the target sum

    return findWays(arr, (totSum - target) / 2);
}

// Function to count the number of ways to achieve the target sum using space optimization
int findWaysOptimized(vector<int> &num, int tar) {
    int n = num.size();
    vector<int> prev(tar + 1, 0);

    if (num[0] == 0)
        prev[0] = 2;  // 2 cases - pick and not pick
    else
        prev[0] = 1;  // 1 case - not pick

    if (num[0] != 0 && num[0] <= tar)
        prev[num[0]] = 1;  // 1 case - pick

    for (int ind = 1; ind < n; ind++) {
        vector<int> cur(tar + 1, 0);
        for (int target = 0; target <= tar; target++) {
            int notTaken = prev[target];
            int taken = 0;
            if (num[ind] <= target)
                taken = prev[target - num[ind]];

            cur[target] = (notTaken + taken) % mod;
        }
        prev = cur;
    }
    return prev[tar];
}

// Function to calculate the number of ways to achieve the target sum
int targetSumOptimized(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for (int i = 0; i < n; i++) {
        totSum += arr[i];
    }

    // Checking for edge cases
    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;  // Not possible to achieve the target sum

    return findWaysOptimized(arr, (totSum - target) / 2);
}

/*
TIME COMPLEXITY:
- All approaches: O(n * T), where n is the number of elements and T is the target sum.

SPACE COMPLEXITY:
- Recursive approach with memoization: O(n * T) for the dp array.
- Tabulation approach: O(n * T) for the dp array.
- Space-optimized approach: O(T) for the previous and current row arrays.

EXAMPLE USAGE:
vector<int> arr = {1, 1, 2, 3};
int target = 1;
int resultMemoization = targetSum(arr.size(), target, arr); // Using memoization
int resultTabulation = targetSum(arr.size(), target, arr); // Using tabulation
int resultOptimized = targetSumOptimized(arr.size(), target, arr); // Using space-optimized approach
*/
