/*
EXAMPLE:
Input: weights = {2, 4, 6}, values = {6, 10, 12}, capacity = 10
Output: 30
Explanation: The optimal way is to take the first item 5 times to get a total value of 30.

QUESTION:
Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible. This is an unbounded knapsack problem where you can take an item multiple times.

APPROACH:
1. Use three approaches to solve the problem:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Function to solve the unbounded knapsack problem using memoization
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    // Base case: if we're at the first item
    if (ind == 0) {
        // Calculate and return the maximum value for the given weight limit
        return (W / wt[0]) * val[0];
    }
    
    // If the result for this index and weight limit is already calculated, return it
    if (dp[ind][W] != -1)
        return dp[ind][W];
        
    // Calculate the maximum value without taking the current item
    int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);
    
    // Calculate the maximum value by taking the current item
    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind, W - wt[ind], dp);
        
    // Store the maximum value in the DP table and return it
    return dp[ind][W] = max(notTaken, taken);
}

// Function to solve the unbounded knapsack problem using memoization
int unboundedKnapsackMemoization(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1)); // Create a DP table
    
    // Call the utility function to calculate the maximum value
    return knapsackUtil(wt, val, n - 1, W, dp);
}

// Function to solve the unbounded knapsack problem using tabulation
int unboundedKnapsackTabulation(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(W + 1, 0)); // Create a DP table

    // Base Condition
    for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = (i / wt[0]) * val[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = dp[ind - 1][cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + dp[ind][cap - wt[ind]]; // Maximum value by taking the current item

            dp[ind][cap] = max(notTaken, taken); // Store the maximum value in the DP table
        }
    }

    return dp[n - 1][W]; // Return the maximum value considering all items and the knapsack capacity
}

// Function to solve the unbounded knapsack problem using space optimization
int unboundedKnapsackOptimized(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<int> cur(W + 1, 0); // Create a vector to store the current DP state

    // Base Condition
    for (int i = wt[0]; i <= W; i++) {
        cur[i] = (i / wt[0]) * val[0]; // Calculate the maximum value for the first item
    }

    for (int ind = 1; ind < n; ind++) {
        for (int cap = 0; cap <= W; cap++) {
            int notTaken = cur[cap]; // Maximum value without taking the current item

            int taken = INT_MIN;
            if (wt[ind] <= cap)
                taken = val[ind] + cur[cap - wt[ind]]; // Maximum value by taking the current item

            cur[cap] = max(notTaken, taken); // Store the maximum value in the current DP state
        }
    }

    return cur[W]; // Return the maximum value considering all items and the knapsack capacity
}

/*
TIME COMPLEXITY:
- All approaches: O(n * W), where n is the number of items and W is the knapsack capacity.

SPACE COMPLEXITY:
- Memoization approach: O(n * W) for the dp array.
- Tabulation approach: O(n * W) for the dp array.
- Space-optimized approach: O(W) for the cur array.

EXAMPLE USAGE:
vector<int> weights = {2, 4, 6};
vector<int> values = {6, 10, 12};
int capacity = 10;
int resultMemoization = unboundedKnapsackMemoization(weights.size(), capacity, values, weights); // Using memoization
int resultTabulation = unboundedKnapsackTabulation(weights.size(), capacity, values, weights); // Using tabulation
int resultOptimized = unboundedKnapsackOptimized(weights.size(), capacity, values, weights); // Using space-optimized approach
*/
