/*
EXAMPLE:
Input: prices = {1, 3, 2, 8, 4, 9}, fee = 2
Output: 8
Explanation: The maximum profit can be achieved with the transactions [buy, sell, cooldown, buy, sell], total profit = 8.

QUESTION:
Given an array prices where prices[i] is the price of a given stock on the ith day, find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
- After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
- You also need to pay a transaction fee for each transaction.

APPROACH:
1. Use dynamic programming to keep track of the maximum profit achievable at each day.
2. Maintain two states: 
   a. Whether we are allowed to buy the stock.
   b. Whether we are allowed to sell the stock.
3. Iterate through the prices array in reverse to calculate the maximum profit for each state.

CODE:
*/

// Recursive function to calculate the maximum profit with memoization
int getAns(vector<int>& Arr, int ind, int buy, int n, int fee, vector<vector<int>>& dp) {
    // Base case: If we've reached the end of the array, return 0 profit.
    if (ind == n) return 0;
    
    // Check if the result is already computed
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
        
    int profit;
    
    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, fee, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, fee, dp));
    }
    
    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, fee, dp), Arr[ind] - fee + getAns(Arr, ind + 1, 0, n, fee, dp));
    }
    
    // Store the computed profit in the DP array
    return dp[ind][buy] = profit;
}

// Function to calculate the maximum profit using memoization
int maximumProfitMemoization(int n, int fee, vector<int>& Arr) {
    vector<vector<int>> dp(n, vector<int>(2, -1));
    
    if (n == 0) return 0; // Edge case: No stocks to trade.
    
    int ans = getAns(Arr, 0, 0, n, fee, dp);
    return ans;
}

// Function to calculate the maximum profit using tabulation
int maximumProfitTabulation(int n, int fee, vector<int>& Arr) {
    if (n == 0) return 0; // Edge case: No stocks to trade.

    // Create a 2D DP array with dimensions (n+1) x 2, initialized to 0
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // Loop through the stock prices from the end to the beginning
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] - fee + dp[ind + 1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    return dp[0][0]; // Return the maximum profit for buying.
}

// Function to calculate the maximum profit using space optimization
int maximumProfit(int n, int fee, vector<int>& Arr) {
    if (n == 0) return 0; // Edge case: No stocks to trade.

    vector<long> ahead(2, 0); // To track maximum profit one step ahead
    vector<long> cur(2, 0);   // To track current maximum profit

    // Initialize both ahead[0] and ahead[1] to 0 as the base condition
    ahead[0] = ahead[1] = 0;

    long profit;

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) { // We can buy the stock
                profit = max(0 + ahead[0], -Arr[ind] + ahead[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + ahead[1], Arr[ind] - fee + ahead[0]);
            }
            cur[buy] = profit;
        }

        ahead = cur;
    }
    return cur[0]; // Return the maximum profit for buying.
}

/*
TIME COMPLEXITY:
- All approaches: O(n), where n is the number of elements in the array.

SPACE COMPLEXITY:
- Memoization approach: O(n) for the dp array.
- Tabulation approach: O(n) for the dp array.
- Space-optimized approach: O(1) for the cur and ahead arrays.

EXAMPLE USAGE:
vector<int> prices = {1, 3, 2, 8, 4, 9};
int fee = 2;
int resultMemoization = maximumProfitMemoization(prices.size(), fee, prices); // Using memoization
int resultTabulation = maximumProfitTabulation(prices.size(), fee, prices); // Using tabulation
int resultOptimized = maximumProfit(prices.size(), fee, prices); // Using space optimization
cout << "Maximum Profit (Memoization): " << resultMemoization << endl; // Output: 8
cout << "Maximum Profit (Tabulation): " << resultTabulation << endl; // Output: 8
cout << "Maximum Profit (Optimized): " << resultOptimized << endl; // Output: 8
*/
