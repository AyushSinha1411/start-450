/*
EXAMPLE:
Input: s1 = "ABCBDAB", s2 = "BDCAB"
Output: 4
Explanation: The LCS is "BDAB".

QUESTION:
Given two strings s1 and s2, find the length of the Longest Common Subsequence (LCS).

APPROACH:
1. Use three approaches to solve the problem:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Function to find the length of the Longest Common Subsequence (LCS) using memoization
int lcsUtil(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp) {
    // Base case: If either string reaches the end, return 0
    if (ind1 < 0 || ind2 < 0)
        return 0;

    // If the result for this pair of indices is already calculated, return it
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    // If the characters at the current indices match, increment the LCS length
    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
    else
        // If the characters don't match, consider two options: moving either left or up in the strings
        return dp[ind1][ind2] = max(lcsUtil(s1, s2, ind1, ind2 - 1, dp), lcsUtil(s1, s2, ind1 - 1, ind2, dp));
}

// Function to calculate the length of the Longest Common Subsequence using memoization
int lcsMemoization(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1)); // Create a DP table
    return lcsUtil(s1, s2, n - 1, m - 1, dp); // Call the utility function to calculate the LCS length
}

// Function to find the length of the Longest Common Subsequence (LCS) using tabulation
int lcsTabulation(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Create a DP table

    // Fill in the DP table to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
        }
    }

    return dp[n][m]; // Return the length of the Longest Common Subsequence
}

// Function to find the length of the Longest Common Subsequence (LCS) using space optimization
int lcsSpaceOptimized(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Initialize two vectors to store the current and previous rows of the DP table
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Base case is covered as we have initialized the prev and cur vectors to 0.

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1]; // Characters match, increment LCS length
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]); // Characters don't match, consider the maximum from above or left
        }
        prev = cur; // Update the previous row with the current row
    }

    return prev[m]; // Return the length of the Longest Common Subsequence
}

/*
TIME COMPLEXITY:
- All approaches: O(n * m), where n and m are the lengths of the two strings.

SPACE COMPLEXITY:
- Memoization approach: O(n * m) for the dp array.
- Tabulation approach: O(n * m) for the dp array.
- Space-optimized approach: O(m) for the cur and prev arrays.

EXAMPLE USAGE:
string s1 = "ABCBDAB";
string s2 = "BDCAB";
int resultMemoization = lcsMemoization(s1, s2); // Using memoization
int resultTabulation = lcsTabulation(s1, s2); // Using tabulation
int resultOptimized = lcsSpaceOptimized(s1, s2); // Using space-optimized approach
*/
