/*
EXAMPLE:
Input: arr = {1, 2, 3}, T = 5
Output: 2
Explanation: The minimum number of elements to form the target sum 5 is {2, 3} or {1, 1, 1, 1, 1}.

QUESTION:
Given an array of integers 'arr' and a target sum 'T', find the minimum number of elements needed to form the target sum 'T'.

APPROACH:
1. Use three approaches to solve the problem:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Function to calculate the minimum number of elements to form the target sum using memoization
int minimumElementsUtil(vector<int>& arr, int ind, int T, vector<vector<int>>& dp) {
    // Base case: If we're at the first element
    if (ind == 0) {
        // Check if the target sum is divisible by the first element
        if (T % arr[0] == 0)
            return T / arr[0]; // If yes, return the quotient as the answer
        else
            return 1e9; // Otherwise, return a very large value to indicate it's not possible
    }
    
    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][T] != -1)
        return dp[ind][T];
        
    // Calculate the minimum elements needed without taking the current element
    int notTaken = 0 + minimumElementsUtil(arr, ind - 1, T, dp);
    
    // Calculate the minimum elements needed by taking the current element
    int taken = 1e9; // Initialize 'taken' to a very large value
    if (arr[ind] <= T)
        taken = 1 + minimumElementsUtil(arr, ind, T - arr[ind], dp);
        
    // Store the minimum of 'notTaken' and 'taken' in the DP array and return it
    return dp[ind][T] = min(notTaken, taken);
}

// Function to find the minimum number of elements needed to form the target sum using memoization
int minimumElements(vector<int>& arr, int T) {
    int n = arr.size();
    
    // Create a DP (Dynamic Programming) table with n rows and T+1 columns and initialize it with -1
    vector<vector<int>> dp(n, vector<int>(T + 1, -1));
    
    // Call the utility function to calculate the answer
    int ans = minimumElementsUtil(arr, n - 1, T, dp);
    
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    return ans; // Return the minimum number of elements needed
}

// Function to find the minimum number of elements needed to form the target sum using tabulation
int minimumElementsTabulation(vector<int>& arr, int T) {
    int n = arr.size();
    
    // Create a 2D DP (Dynamic Programming) table with n rows and T+1 columns
    vector<vector<int>> dp(n, vector<int>(T + 1, 0));
    
    // Initialize the first row of the DP table
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9; // Set it to a very large value if not possible
    }
    
    // Fill the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            // Calculate the minimum elements needed without taking the current element
            int notTake = dp[ind - 1][target];
            
            // Calculate the minimum elements needed by taking the current element
            int take = 1e9; // Initialize 'take' to a very large value
            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];
                
            // Store the minimum of 'notTake' and 'take' in the DP table
            dp[ind][target] = min(notTake, take);
        }
    }
    
    // The answer is in the bottom-right cell of the DP table
    int ans = dp[n - 1][T];
    
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    
    return ans; // Return the minimum number of elements needed
}

// Function to find the minimum number of elements needed to form the target sum using space optimization
int minimumElementsOptimized(vector<int>& arr, int T) {
    int n = arr.size();
    
    // Create two vectors to store the previous and current DP states
    vector<int> prev(T + 1, 0);
    vector<int> cur(T + 1, 0);
    
    // Initialize the first row of the DP table
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            prev[i] = i / arr[0];
        else
            prev[i] = 1e9; // Set it to a very large value if not possible
    }
    
    // Fill the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            // Calculate the minimum elements needed without taking the current element
            int notTake = prev[target];
            
            // Calculate the minimum elements needed by taking the current element
            int take = 1e9; // Initialize 'take' to a very large value
            if (arr[ind] <= target)
                take = 1 + cur[target - arr[ind]];
                
            // Store the minimum of 'notTake' and 'take' in the current DP state
            cur[target] = min(notTake, take);
        }
        // Update the previous DP state with the current state for the next iteration
        prev = cur;
    }
    
    // The answer is in the last row of the DP table
    int ans = prev[T];
    
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    
    return ans; // Return the minimum number of elements needed
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
int T = 5;
int resultMemoization = minimumElements(arr, T); // Using memoization
int resultTabulation = minimumElementsTabulation(arr, T); // Using tabulation
int resultOptimized = minimumElementsOptimized(arr, T); // Using space-optimized approach
*/
