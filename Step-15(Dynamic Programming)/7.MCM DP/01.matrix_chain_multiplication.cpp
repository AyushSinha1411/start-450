/*
EXAMPLE:
Input: arr = [1, 2, 3, 4]
Output: 18
Explanation: Optimal order is (1*(2*3))*4 with minimum cost 18.

QUESTION:
Given an array `arr` of dimensions, find the minimum number of multiplications needed to multiply the given chain of matrices.

APPROACH:
1. Use a recursive function with memoization to find the minimum cost.
2. Base case: When the chain length is one matrix, the cost is zero.
3. Use a partitioning loop to divide the chain into two parts and recursively calculate the cost for each part.
4. Use a DP table to store the results of subproblems and avoid redundant calculations.
5. Return the minimum cost for multiplying the entire chain of matrices.

CODE:
*/

// Function to find the minimum cost of matrix multiplication
int f(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
    // Base condition: Only one matrix, so no cost
    if (i == j)
        return 0;

    // Check if the result is already computed
    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    // Partitioning loop
    for (int k = i; k <= j - 1; k++) {
        int ans = f(arr, i, k, dp) + f(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        mini = min(mini, ans);
    }

    // Store and return the minimum cost
    return dp[i][j] = mini;
}

// Function to initiate the recursive function with memoization
int matrixMultiplication(vector<int>& arr, int N) {
    // Create a DP table initialized to -1
    vector<vector<int>> dp(N, vector<int>(N, -1));

    // Call the recursive function starting from the first to the last matrix
    return f(arr, 1, N - 1, dp);
}

// Function to find the minimum number of operations for matrix multiplication using tabulation
int matrixMultiplicationTabulation(vector<int>& arr, int N) {
    // Create a DP table to store the minimum number of operations
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // Loop for the length of the chain
    for (int len = 2; len < N; len++) {
        for (int i = 1; i < N - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try different partition points to find the minimum
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // The result is stored in dp[1][N-1]
    return dp[1][N - 1];
}

/*
TIME COMPLEXITY:
- O(N^3), where N is the size of the array. This is due to the nested loops used for partitioning and calculating the cost.

SPACE COMPLEXITY:
- O(N^2), for the DP table.

EXAMPLE USAGE:
vector<int> arr = {1, 2, 3, 4};
int resultMemoization = matrixMultiplication(arr, arr.size());
int resultTabulation = matrixMultiplicationTabulation(arr, arr.size());
cout << resultMemoization << endl; // Output: 18
cout << resultTabulation << endl; // Output: 18
*/
