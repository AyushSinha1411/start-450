/*
EXAMPLE:
Input: prices = {3, 3, 5, 0, 0, 3, 1, 4}
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
             Total profit = 3 + 3 = 6.

QUESTION:
Given an array `prices` where prices[i] is the price of a given stock on the ith day, design an algorithm to find the maximum profit. You may complete at most two transactions. You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

APPROACH:
1. Use dynamic programming to keep track of the maximum profit achievable at each day with at most two transactions.
2. Maintain a 3D DP array where `dp[ind][buy][cap]` represents the maximum profit on day `ind` with `buy` (0 if we can buy, 1 if we can sell) and `cap` (number of remaining transactions).
3. Use space optimization to reduce the memory usage by keeping track of only the current and previous states.

CODE:
*/

// Recursive function to calculate the maximum profit with memoization
int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp) {
    if (ind == n || cap == 0) // Base case: If we reach the end of the array or run out of allowed transactions, return 0.
        return 0;

    if (dp[ind][buy][cap] != -1) // If the result is already calculated, return it.
        return dp[ind][buy][cap];

    int profit;

    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(Arr, n, ind + 1, 0, cap, dp), -Arr[ind] + getAns(Arr, n, ind + 1, 1, cap, dp));
    } else { // We can sell the stock
        profit = max(0 + getAns(Arr, n, ind + 1, 1, cap, dp), Arr[ind] + getAns(Arr, n, ind + 1, 0, cap - 1, dp));
    }

    return dp[ind][buy][cap] = profit; // Store and return the calculated profit.
}

// Function to calculate the maximum profit using memoization
int maxProfit(vector<int>& prices, int n) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return getAns(prices, n, 0, 0, 2, dp);
}

// Function to calculate the maximum profit using tabulation
int maxProfitTabulation(vector<int>& Arr, int n) {
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 0) { // We can buy the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap], -Arr[ind] + dp[ind + 1][1][cap]);
                } else { // We can sell the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap], Arr[ind] + dp[ind + 1][0][cap - 1]);
                }
            }
        }
    }

    return dp[0][0][2]; // The result is stored in dp[0][0][2] which represents maximum profit after the final transaction.
}

// Function to calculate the maximum profit using space optimization
int maxProfitOptimized(vector<int>& Arr, int n) {
    vector<vector<int>> ahead(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 0) { // We can buy the stock
                    cur[buy][cap] = max(0 + ahead[0][cap], -Arr[ind] + ahead[1][cap]);
                } else { // We can sell the stock
                    cur[buy][cap] = max(0 + ahead[1][cap], Arr[ind] + ahead[0][cap - 1]);
                }
            }
        }
        ahead = cur; // Update the ahead state with the current state for the next iteration.
    }

    return ahead[0][2];
}

/*
TIME COMPLEXITY:
- All approaches: O(n), where n is the number of elements in the array. This is because we iterate through the array once.

SPACE COMPLEXITY:
- Memoization approach: O(n) for the dp array.
- Tabulation approach: O(n) for the dp array.
- Space-optimized approach: O(1) for the cur and ahead arrays.

EXAMPLE USAGE:
vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
int n = prices.size();
int result = maxProfitOptimized(prices, n); // Using space optimization approach
cout << "Maximum Profit: " << result << endl; // Output: 6
*/
