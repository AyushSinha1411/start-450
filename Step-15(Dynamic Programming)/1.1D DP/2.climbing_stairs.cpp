/*
QUESTION:
Given a staircase with n steps, you can climb either 1 step or 2 steps at a time. Calculate the number of distinct ways you can climb to the top.

APPROACH:
1. Use dynamic programming to store the number of ways to reach each step.
2. Use a space-optimized approach to reduce space complexity by only storing the last two values.

CODE:
*/

// Dynamic programming approach with an array
int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    // Fill the dp array with the number of ways to reach each step
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n]; // Return the number of ways to reach the nth step
}

// Space-optimized approach
int climbStairsOptimized(int n) {
    if (n == 1) {
        return 1;
    }
    int first = 1;
    int second = 2;
    // Use only two variables to keep track of the last two values
    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second; // Return the number of ways to reach the nth step
}



/*
TIME COMPLEXITY:
- Both approaches: O(n), as they iterate from 1 to n.

SPACE COMPLEXITY:
- Dynamic programming approach with an array: O(n), for the dp array.
- Space-optimized approach: O(1), as it uses only a constant amount of space.

EXAMPLE USAGE:
int n = 5;
int ways_dp = climbStairs(n); // Number of ways to climb 5 steps using DP
int ways_optimized = climbStairsOptimized(n); // Number of ways to climb 5 steps using space optimization
*/
