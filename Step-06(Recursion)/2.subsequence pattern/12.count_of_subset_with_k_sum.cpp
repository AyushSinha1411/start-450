/*
QUESTION:
Given an array of integers and a sum, count the number of subsets that add up to the given sum. The result should be returned modulo 10^9 + 7.

Example:
Input: arr = [1, 2, 3, 4], sum = 5
Output: 3
Explanation: The subsets that add up to 5 are [1, 4], [2, 3], and [1, 2, 2].

APPROACH:
1. Use a recursive function to count the number of subsets that add up to the given sum.
2. At each step, decide whether to include the current element in the subset or not.
3. Use modulo operation to prevent overflow.
4. Return the total count of such subsets.

CODE:
*/

/* Approach:
 * 1. Use a recursive function to explore all subsets.
 * 2. Use a memoization table to store the results of subproblems.
 * 3. The base case is when the position reaches the end of the array.
 * 4. The recursive cases include including the current element and excluding the current element.
 * 5. Store and return the result for each subproblem to avoid redundant calculations.
 */
const int MOD = 1e9 + 7;
int N; // Size of the array
 // Memoization table
// Recursive function to count the number of subsets that add up to the given sum
int fun(int pos, int sum, int arr[]) {
    if (pos >= N)
        return sum == 0; // Check if sum is zero when array position reaches end

    // Check if the subproblem is already solved
    if (dp[pos][sum] != -1)
        return dp[pos][sum];

    int ans = 0; // Initialize answer with zero

    // Recursively call function for next position with sum unchanged
    ans += fun(pos + 1, sum, arr);
    ans %= MOD; // Take modulo of the answer to avoid overflow

    // Recursively call function for next position with reduced sum
    if (arr[pos] <= sum) {
        ans += fun(pos + 1, sum - arr[pos], arr);
        ans %= MOD;
    }

    // Store the result in the memoization table
    return dp[pos][sum] = ans;
}

// Function to count the number of subsets that add up to the given sum
int perfectSum(int arr[], int n, int sum) {
    N = n; // Assign n to N variable
    vector<vector<int>> dp;
    // Initialize the memoization table with -1
    dp = vector<vector<int>>(N + 1, vector<int>(sum + 1, -1));

    return fun(0, sum, arr); // Call recursive function with initial parameters
}


/*
 * Time Complexity:
 * The time complexity is O(n * sum) because each subproblem is solved only once.
 *
 * Space Complexity:
 * The space complexity is O(n * sum) for the memoization table.
 */
