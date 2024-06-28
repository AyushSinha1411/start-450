/*
EXAMPLE:
Input: wt = {1, 2, 3}, val = {10, 15, 40}, W = 6
Output: 65
Explanation: The maximum value that can be obtained is by selecting items with weights 2 and 3 (15 + 40 = 55).

QUESTION:
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

APPROACH:
1. Use three approaches to solve the 0/1 Knapsack problem:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Function to solve the 0/1 Knapsack problem using memoization
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    // Base case: If there are no items left or the knapsack has no capacity, return 0
    if (ind == 0) {
        if (wt[0] <= W) return val[0];
        else return 0;
    }

    // If the result for this state is already calculated, return it
    if (dp[ind][W] != -1) {
        return dp[ind][W];
    }

    // Calculate the maximum value by either excluding the current item or including it
    int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);
    int taken = 0;

    // Check if the current item can be included without exceeding the knapsack's capacity
    if (wt[ind] <= W) {
        taken = val[ind] + knapsackUtil(wt, val, ind - 1, W - wt[ind], dp);
    }

    // Store the result in the DP table and return
    return dp[ind][W] = max(notTaken, taken);
}

// Function to solve the 0/1 Knapsack problem
int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return knapsackUtil(wt, val, n - 1, W, dp);
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsackTabulation(vector<int>& wt, vector<int>& val, int n, int W) {
    // Create a 2D DP table with dimensions n x W+1 and initialize it with zeros
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base condition: Fill in the first row for the weight of the first item
    for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = val[0];
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            // Calculate the maximum value by either excluding the current item or including it
            int notTaken = dp[ind - 1][cap];
            int taken = INT_MIN;

            // Check if the current item can be included without exceeding the knapsack's capacity
            if (wt[ind] <= cap) {
                taken = val[ind] + dp[ind - 1][cap - wt[ind]];
            }

            // Update the DP table
            dp[ind][cap] = max(notTaken, taken);
        }
    }

    // The final result is in the last cell of the DP table
    return dp[n - 1][W];
}

// Function to solve the 0/1 Knapsack problem using space optimization
int knapsackOptimized(vector<int>& wt, vector<int>& val, int n, int W) {
    // Initialize a vector 'prev' to represent the previous row of the DP table
    vector<int> prev(W + 1, 0);

    // Base condition: Fill in 'prev' for the weight of the first item
    for (int i = wt[0]; i <= W; i++) {
        prev[i] = val[0];
    }

    // Fill in the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int cap = W; cap >= 0; cap--) {
            // Calculate the maximum value by either excluding the current item or including it
            int notTaken = prev[cap];
            int taken = INT_MIN;

            // Check if the current item can be included without exceeding the knapsack's capacity
            if (wt[ind] <= cap) {
                taken = val[ind] + prev[cap - wt[ind]];
            }

            // Update 'prev' for the current capacity
            prev[cap] = max(notTaken, taken);
        }
    }

    // The final result is in the last cell of the 'prev' vector
    return prev[W];
}

/*
TIME COMPLEXITY:
- All approaches: O(n * W), where n is the number of items and W is the capacity of the knapsack.

SPACE COMPLEXITY:
- Recursive approach with memoization: O(n * W) for the dp array.
- Tabulation approach: O(n * W) for the dp array.
- Space-optimized approach: O(W) for the previous and current row arrays.

EXAMPLE USAGE:
vector<int> wt = {1, 2, 3};
vector<int> val = {10, 15, 40};
int W = 6;
int resultMemoization = knapsack(wt, val, wt.size(), W); // Using memoization
int resultTabulation = knapsackTabulation(wt, val, wt.size(), W); // Using tabulation
int resultOptimized = knapsackOptimized(wt, val, wt.size(), W); // Using space-optimized approach
*/
