/*
EXAMPLE:
Input: prices = {1, 2, 3, 0, 2}
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell], total profit = 3.

QUESTION:
Given an array prices where prices[i] is the price of a given stock on the ith day, find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
- After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

APPROACH:
1. Use dynamic programming to keep track of the maximum profit achievable at each day.
2. Maintain three states:
   a. `cur` for the current day.
   b. `front1` for the next day.
   c. `front2` for the day after the next day.
3. Iterate through the prices array in reverse to calculate the maximum profit for each state.

CODE:
*/

// Recursive function to calculate the maximum profit with memoization
int getAns(vector<int>& Arr, int ind, int buy, int n, vector<vector<int>>& dp) {
    // Base case: If we've reached the end of the array, return 0 profit.
    if (ind >= n) return 0;
    
    // Check if the result is already computed
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
        
    int profit;
    
    if (buy == 0) { // We can buy the stock
        profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
    }
    
    if (buy == 1) { // We can sell the stock
        profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 2, 0, n, dp));
    }
    
    // Store the result in the DP array and return
    return dp[ind][buy] = profit;
}

// Function to calculate the maximum profit using memoization
int stockProfitMemoization(vector<int>& Arr) {
    int n = Arr.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    
    int ans = getAns(Arr, 0, 0, n, dp);
    return ans;
}

// Function to calculate the maximum profit using tabulation
int stockProfitTabulation(vector<int>& Arr) {
    int n = Arr.size();
    // Create a 2D DP array with dimensions (n+2) x 2, initialized to 0
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    
    // Loop through the stock prices from the end to the beginning
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 2][0]);
            }

            // Store the computed profit in the DP array
            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}

// Function to calculate the maximum profit using space optimization
int stockProfit(vector<int>& Arr) {
    int n = Arr.size();
    
    // Initialize three arrays to track the maximum profit for buying and selling
    vector<int> cur(2, 0);       // Current maximum profit
    vector<int> front1(2, 0);    // Maximum profit one step ahead
    vector<int> front2(2, 0);    // Maximum profit two steps ahead
    
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit;

            if (buy == 0) { // We can buy the stock
                profit = max(0 + front1[0], -Arr[ind] + front1[1]);
            }

            if (buy == 1) { // We can sell the stock
                profit = max(0 + front1[1], Arr[ind] + front2[0]);
            }
            
            cur[buy] = profit;
        }
        
        // Update the 'front1' and 'front2' arrays with current values
        front2 = front1;
        front1 = cur;
    }
    
    return cur[0]; // Return the maximum profit for buying.
}

/*
TIME COMPLEXITY:
- All approaches: O(n), where n is the number of elements in the array.

SPACE COMPLEXITY:
- Memoization approach: O(n) for the dp array.
- Tabulation approach: O(n) for the dp array.
- Space-optimized approach: O(1) for the cur, front1, and front2 arrays.

EXAMPLE USAGE:
vector<int> prices = {1, 2, 3, 0, 2};
int resultMemoization = stockProfitMemoization(prices); // Using memoization
int resultTabulation = stockProfitTabulation(prices); // Using tabulation
int resultOptimized = stockProfit(prices); // Using space optimization
cout << "Maximum Profit (Memoization): " << resultMemoization << endl; // Output: 3
cout << "Maximum Profit (Tabulation): " << resultTabulation << endl; // Output: 3
cout << "Maximum Profit (Optimized): " << resultOptimized << endl; // Output: 3
*/
