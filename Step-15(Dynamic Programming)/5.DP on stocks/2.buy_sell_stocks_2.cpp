/*
EXAMPLE:
Input: Arr = {7, 1, 5, 3, 6, 4}, n = 6
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

QUESTION:
Given an array Arr of integers where each element represents the price of a stock on a given day, write a function to calculate the maximum profit you can achieve from buying and selling one share of the stock multiple times. You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

APPROACH:
1. Use dynamic programming to keep track of the maximum profit achievable at each day.
2. Maintain two states: whether we are holding a stock or not.
3. Iterate through the array in reverse order to calculate the maximum profit for each state.
4. Use space optimization to reduce the memory usage by keeping track of only the current and previous states.

CODE:
*/

// Function to calculate the maximum profit from stock trading
long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp) {
    // Base case: When we reach the end of the array, there are no more decisions to make.
    if (ind == n) {
        return 0;
    }

    // If the result for this state has already been calculated, return it
    if (dp[ind][buy] != -1) {
        return dp[ind][buy];
    }

    long profit = 0;

    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }

    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));
    }

    // Store the calculated profit in the DP table and return it
    return dp[ind][buy] = profit;
}

// Function to calculate the maximum profit using memoization
long getMaximumProfit(long *Arr, int n) {
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return getAns(Arr, 0, 0, n, dp);
}

// Function to calculate the maximum profit using tabulation
long getMaximumProfit(long *Arr, int n) {
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            long profit;
            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            } else { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }

    // The maximum profit is stored in dp[0][0] after all calculations
    return dp[0][0];
}

// Function to calculate the maximum profit using space optimization
long getMaximumProfit(long *Arr, int n) {
    vector<long> ahead(2, 0), cur(2, 0);

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            long profit;
            if (buy == 0) { // We can buy the stock
                profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
            } else { // We can sell the stock
                profit = max(0 + ahead[1], Arr[ind] + ahead[0]);
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }

    // The maximum profit is stored in cur[0] after all calculations
    return cur[0];
}

/*
TIME COMPLEXITY:
- All approaches: O(n), where n is the number of elements in the array. This is because we iterate through the array once.

SPACE COMPLEXITY:
- Memoization approach: O(n) for the dp array.
- Tabulation approach: O(n) for the dp array.
- Space-optimized approach: O(1) for the cur and ahead arrays.

EXAMPLE USAGE:
long Arr[] = {7, 1, 5, 3, 6, 4};
int n = 6;
long result = getMaximumProfit(Arr, n); // Using space optimization approach
cout << "Maximum Profit: " << result << endl; // Output: 5
*/
