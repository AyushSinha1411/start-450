#include <vector>
using namespace std;

/*
EXAMPLE:
Input: arr = {1, 2, 3}, target = 4
Output: 4
Explanation: There are four ways to make change for the target sum: 
- {1, 1, 1, 1}
- {1, 1, 2}
- {1, 3}
- {2, 2}

QUESTION:
Given an array of integers 'arr' representing coin denominations and a target sum 'target', count the number of ways to make change for the target sum.
coin can be used as many number of times

APPROACH:
1. Use three approaches to solve the problem:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Function to count the number of ways to make change for a given target sum using memoization
long countWaysToMakeChangeUtil(vector<int>& arr, int ind, int T, vector<vector<long>>& dp) {
    // Base case: if we're at the first element
    if (ind == 0) {
        // Check if the target sum is divisible by the first element
        return (T % arr[0] == 0);
    }
    
    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][T] != -1)
        return dp[ind][T];
        
    // Calculate the number of ways without taking the current element
    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T, dp);
    
    // Calculate the number of ways by taking the current element
    long taken = 0;
    if (arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr, ind, T - arr[ind], dp);
        
    // Store the sum of ways in the DP table and return it
    return dp[ind][T] = notTaken + taken;
}

// Function to count the number of ways to make change for the target sum using memoization
long countWaysToMakeChange(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T + 1, -1)); // Create a DP table
    
    // Call the utility function to calculate the answer
    return countWaysToMakeChangeUtil(arr, n - 1, T, dp);
}

// Function to count the number of ways to make change for a given target sum using tabulation
long countWaysToMakeChangeTabulation(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T + 1, 0)); // Create a DP table

    // Initializing base condition
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = 1;
        // Else condition is automatically fulfilled, as dp array is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            long notTaken = dp[ind - 1][target];

            long taken = 0;
            if (arr[ind] <= target)
                taken = dp[ind][target - arr[ind]];

            dp[ind][target] = notTaken + taken;
        }
    }

    return dp[n - 1][T];
}

// Function to count the number of ways to make change for a given target sum using space optimization
long countWaysToMakeChangeOptimized(vector<int>& arr, int n, int T) {
    vector<long> prev(T + 1, 0);  // Create a vector to store the previous DP state

    // Initialize base condition
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            prev[i] = 1;  // There is one way to make change for multiples of the first coin
        // Else condition is automatically fulfilled, as the prev vector is initialized to zero
    }

    for (int ind = 1; ind < n; ind++) {
        vector<long> cur(T + 1, 0);  // Create a vector to store the current DP state
        for (int target = 0; target <= T; target++) {
            long notTaken = prev[target];  // Number of ways without taking the current coin

            long taken = 0;
            if (arr[ind] <= target)
                taken = cur[target - arr[ind]];  // Number of ways by taking the current coin
                
            cur[target] = notTaken + taken;  // Total number of ways for the current target
        }
        prev = cur;  // Update the previous DP state with the current state for the next coin
    }

    return prev[T];  // Return the total number of ways to make change for the target
}

/*
TIME COMPLEXITY:
- All approaches: O(n * T), where n is the number of elements and T is the target sum.

SPACE COMPLEXITY:
- Recursive approach with memoization: O(n * T) for the dp array.
- Tabulation approach: O(n * T) for the dp array.
- Space-optimized approach: O(T) for the previous and current row arrays.

EXAMPLE USAGE:
vector<int> arr = {1, 2, 3};
int target = 4;
int resultMemoization = countWaysToMakeChange(arr, arr.size(), target); // Using memoization
int resultTabulation = countWaysToMakeChangeTabulation(arr, arr.size(), target); // Using tabulation
int resultOptimized = countWaysToMakeChangeOptimized(arr, arr.size(), target); // Using space-optimized approach
*/
