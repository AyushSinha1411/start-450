/*
EXAMPLE:
Input: arr = {10, 9, 2, 5, 3, 7, 101, 18}
Output: 4
Explanation: The LIS is {2, 3, 7, 101}, so the length is 4.

QUESTION:
Given an integer array `arr`, find the length of the longest increasing subsequence (LIS).

APPROACH:
1. Use dynamic programming with memoization to keep track of the LIS length at each position.
2. Maintain a 2D DP array where `dp[ind][prev_index + 1]` stores the LIS length considering elements from index `ind` with the previous element at `prev_index`.
3. Use recursion to explore both taking and not taking the current element into the LIS.
4. Base case is when we reach the end of the array.

CODE:
*/

// Recursive function to find the length of the longest increasing subsequence with memoization
int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>>& dp) {
    // Base condition: If we've reached the end of the array, return 0.
    if (ind == n)
        return 0;

    // Check if the result is already computed
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];

    // Option 1: Do not take the current element
    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);

    // Option 2: Take the current element if it's larger than the previous one
    int take = 0;
    if (prev_index == -1 || arr[ind] > arr[prev_index]) {
        take = 1 + getAns(arr, n, ind + 1, ind, dp);
    }

    // Store and return the maximum of both options
    return dp[ind][prev_index + 1] = max(notTake, take);
}

// Function to find the length of the longest increasing subsequence using memoization
int longestIncreasingSubsequence(int arr[], int n) {
    // Create a 2D DP array initialized to -1
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    // Call the recursive function starting from index 0 and previous index -1
    return getAns(arr, n, 0, -1, dp);
}

// Function to find the length of the longest increasing subsequence using tabulation
int longestIncreasingSubsequenceTabulation(int arr[], int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int ind = n-1; ind>=0; ind--){
        for (int prev_index = ind-1; prev_index >=-1; prev_index--){
            int notTake = 0 + dp[ind+1][prev_index +1];
            int take = 0;
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                take = 1 + dp[ind+1][ind+1];
            }
            dp[ind][prev_index+1] = max(notTake,take);
        }
    }
    return dp[0][0];
}

// Function to find the length of the longest increasing subsequence using space optimization
int longestIncreasingSubsequenceSpaceOptimized(int arr[], int n){
    vector<int> next(n+1,0);
    vector<int> cur(n+1,0);
    
    for(int ind = n-1; ind>=0; ind--){
        for (int prev_index = ind-1; prev_index >=-1; prev_index--){
            int notTake = 0 + next[prev_index +1];
            int take = 0;
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                take = 1 + next[ind+1];
            }
            cur[prev_index+1] = max(notTake,take);
        }
        next = cur;
    }
    return cur[0];
}

/*
TIME COMPLEXITY:
- O(n^2), where n is the number of elements in the array. Each state in the DP array is computed at most once.

SPACE COMPLEXITY:
- Memoization approach: O(n^2) for the dp array.
- Tabulation approach: O(n^2) for the dp array.
- Space-optimized approach: O(n) for the cur and next arrays.

EXAMPLE USAGE:
int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
int n = sizeof(arr) / sizeof(arr[0]);
int resultMemoization = longestIncreasingSubsequence(arr, n);
int resultTabulation = longestIncreasingSubsequenceTabulation(arr, n);
int resultOptimized = longestIncreasingSubsequenceSpaceOptimized(arr, n);
cout << "LIS using memoization: " << resultMemoization << endl; // Output: 4
cout << "LIS using tabulation: " << resultTabulation << endl; // Output: 4
cout << "LIS using space optimization: " << resultOptimized << endl; // Output: 4
*/
