/*
EXAMPLE:
Input: price[] = {1, 5, 8, 9, 10, 17, 17, 20}, n = 8
Output: 22
Explanation: The maximum obtainable value by cutting the rod into pieces of length 2 and 6 is 22 (5 + 17).

QUESTION:
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

APPROACH:
1. Use three approaches to solve the problem:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Function to find the maximum obtainable value by cutting up the rod using memoization
int cutRodUtil(int price[], int n, vector<int>& dp) {
    // Base case: If the length of the rod is 0, the maximum value is 0
    if (n <= 0)
        return 0;

    // If the result for this length is already calculated, return it
    if (dp[n] != -1)
        return dp[n];

    int max_val = INT_MIN;

    // Recursively cut the rod in different pieces and compare different configurations
    for (int i = 0; i < n; i++)
        max_val = max(max_val, price[i] + cutRodUtil(price, n - i - 1, dp));

    // Store the maximum value in the DP table and return it
    return dp[n] = max_val;
}

// Function to find the maximum obtainable value by cutting up the rod using memoization
int cutRodMemoization(int price[], int n) {
    vector<int> dp(n + 1, -1); // Create a DP table
    return cutRodUtil(price, n, dp); // Call the utility function to calculate the maximum value
}

// Function to find the maximum obtainable value by cutting up the rod using tabulation
int cutRodTabulation(int price[], int n) {
    vector<int> dp(n + 1, 0); // Create a DP table

    // Build the table dp[] in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++)
            max_val = max(max_val, price[j] + dp[i - j - 1]);
        dp[i] = max_val;
    }

    return dp[n]; // Return the maximum value obtained for length n
}

// Function to find the maximum obtainable value by cutting up the rod using space optimization
int cutRodOptimized(int price[], int n) {
    vector<int> dp(n + 1, 0); // Create a DP table

    // Build the table dp[] in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++)
            max_val = max(max_val, price[j] + dp[i - j - 1]);
        dp[i] = max_val;
    }

    return dp[n]; // Return the maximum value obtained for length n
}

/*
TIME COMPLEXITY:
- All approaches: O(n^2), where n is the length of the rod.

SPACE COMPLEXITY:
- Memoization approach: O(n) for the dp array.
- Tabulation approach: O(n) for the dp array.
- Space-optimized approach: O(n) for the dp array.

EXAMPLE USAGE:
int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
int length = 8;
int resultMemoization = cutRodMemoization(prices, length); // Using memoization
int resultTabulation = cutRodTabulation(prices, length); // Using tabulation
int resultOptimized = cutRodOptimized(prices, length); // Using space-optimized approach
*/
