/*
EXAMPLE:
Input: num = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: The best way to partition the array is [15,15,15,9,10,10,10]. The sum is 84.

QUESTION:
Given an integer array `num` and an integer `k`, partition the array into several subarrays such that the maximum sum of the subarrays is maximized. Return the maximum sum after partitioning.

APPROACH:
1. Use dynamic programming to solve the problem.
2. Define a recursive function `f` to find the maximum sum.
3. Use memoization to store results of subproblems in a DP array.
4. Iterate through possible partitions and update the maximum sum.
5. Implement an iterative solution with tabulation for better performance.

CODE:
*/
// Recursive function to find the maximum sum after partitioning.
int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();

    // Base case: If the current index is equal to the size of the array, return 0.
    if (ind == n) return 0;

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;

    // Loop through the array starting from the current index.
    for (int j = ind; j < min(ind + k, n); j++) {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + maxSumAfterPartitioning(j + 1, num, k);
        maxAns = max(maxAns, sum);
    }
    return maxAns;
}

//Time Complexity: Exponential

// Memoization to find the maximum sum after partitioning.
int f(int ind, vector<int> &num, int k, vector<int> &dp) {
    int n = num.size();

    // Base case: If the current index is equal to the size of the array, return 0.
    if (ind == n) return 0;

    // If the result for this index is already computed, return it from dp array.
    if (dp[ind] != -1) return dp[ind];

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;

    // Loop through the array starting from the current index.
    for (int j = ind; j < min(ind + k, n); j++) {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + f(j + 1, num, k, dp);
        maxAns = max(maxAns, sum);
    }

    // Store the computed result in the dp array and return it.
    return dp[ind] = maxAns;
}

// Function to find the maximum sum after partitioning the array.
int maxSumAfterPartitioning(vector<int>& num, int k) {
    int n = num.size();
    vector<int> dp(n, -1);
    return f(0, num, k, dp);
}

// Function to find the maximum sum after partitioning the array using tabulation.
int maxSumAfterPartitioningTabulation(vector<int>& num, int k) {
    int n = num.size();
    
    // Create a DP array to store the maximum sum.
    vector<int> dp(n + 1, 0);
    
    // Iterate through the array from right to left.
    for (int ind = n - 1; ind >= 0; ind--) {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        
        // Loop through the next k elements (or remaining elements if k is smaller).
        for (int j = ind; j < min(ind + k, n); j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        
        // Store the computed maximum sum in the DP array.
        dp[ind] = maxAns;
    }
    
    // The maximum sum after partitioning the entire array is stored in dp[0].
    return dp[0];
}

/*
TIME COMPLEXITY:
- Recursive approach with memoization: O(n * k), where n is the length of the array and k is the maximum number of elements in a partition.
- Tabulation approach: O(n * k), where n is the length of the array and k is the maximum number of elements in a partition.

SPACE COMPLEXITY:
- Recursive approach with memoization: O(n) for the dp array.
- Tabulation approach: O(n) for the dp array.

EXAMPLE USAGE:
vector<int> num = {1, 15, 7, 9, 2, 5, 10};
int k = 3;
int resultMemoization = maxSumAfterPartitioning(num, k); // Using memoization
int resultTabulation = maxSumAfterPartitioningTabulation(num, k); // Using tabulation
cout << resultMemoization << endl; // Output: 84
cout << resultTabulation << endl; // Output: 84
*/
