/*
QUESTION:
Given a rod of length `n` and an array of prices `price[]` that contains prices of all pieces of size smaller than `n`. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Example:
Input: 
n = 8, price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output: 22
Explanation: By cutting the rod into 2 pieces of lengths 2 and 6, we get the maximum value of 22 (5 + 17).

APPROACH:
1. Use dynamic programming to store the maximum value obtainable for rod lengths from 0 to n.
2. Initialize the base case where a rod of length 0 has a value of 0.
3. Iterate through all possible rod lengths and all possible cuts to calculate the maximum value obtainable.
4. Return the maximum value obtainable for the given rod length.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

int cutRod(int price[], int n) {
    // Create a dp array to store maximum value obtainable for rod lengths 0 to n
    vector<int> dp(n + 1, -1);

    // Base case: If the rod length is 0, return 0
    dp[0] = 0;

    // Iterate through all possible rod lengths
    for (int i = 1; i <= n; ++i) {
        // Iterate through all possible cuts for the current rod length
        for (int j = 1; j <= i; ++j) {
            // Calculate the maximum value obtainable by cutting the rod
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
        }
    }

    // Return the maximum value obtainable for rod length n
    return dp[n];
}

/*
TIME COMPLEXITY:
- O(n^2), where n is the length of the rod. This is because we iterate through all possible lengths and all possible cuts for each length.

SPACE COMPLEXITY:
- O(n), for the dp array storing maximum value obtainable for rod lengths 0 to n.
*/
