/*
QUESTION:
Given an array of integers and a target sum, determine if there exists a subsequence of the array that adds up to the target sum.

Example:
Input: arr = [1, 2, 3, 4], k = 5
Output: true
Explanation: There exists a subsequence [1, 4] or [2, 3] that adds up to 5.

APPROACH:
1. Use a recursive function to check if there exists a subsequence that adds up to the target sum.
2. At each step, decide whether to include the current element in the sum or not.
3. Return true if any combination matches the target sum, otherwise return false.

CODE:
*/

// Recursive function to check if there exists a subsequence that adds up to the target sum
bool solve(vector<int> &arr, int index, int sum, int s, vector<vector<int>> &dp) {
    // Base case: if index is less than 0
    if (index < 0) {
        return (sum == s); // Check if the current sum equals the target sum
    }

    // Check if the current sum exceeds the target sum
    if (sum > s) {
        return false;
    }

    // Check if the subproblem is already solved
    if (dp[index][sum] != -1) {
        return dp[index][sum];
    }

    // Include the current element in the sum and recurse
    if (solve(arr, index - 1, sum + arr[index], s, dp)) {
        return dp[index][sum] = true;
    }

    // Exclude the current element from the sum and recurse
    if (solve(arr, index - 1, sum, s, dp)) {
        return dp[index][sum] = true;
    }

    // Store the result in the memoization table
    return dp[index][sum] = false;
}

// Function to determine if there exists a subsequence that adds up to the target sum
bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
    // Initialize the memoization table with -1
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    // Call the recursive function with initial parameters
    return solve(arr, n - 1, 0, k, dp);
}

/*
 * Time Complexity:
 * The time complexity is O(n * k) because each subproblem is solved only once.
 *
 * Space Complexity:
 * The space complexity is O(n * k) for the memoization table.
 */
