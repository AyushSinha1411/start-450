/*
QUESTION:
Given a string s, find the length of the Longest Palindromic Subsequence (LPS).

APPROACH:
1. To find the LPS, we need to find the Longest Common Subsequence (LCS) between the string s and its reversed version.
2. Use three approaches to solve the LCS problem:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

EXAMPLE:
Input: s = "BBABCBCAB"
Output: 7
Explanation: The LPS is "BABCBAB" or "BACBCAB".

CODE:
*/

// Function to calculate the length of the Longest Common Subsequence using memoization
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

    // Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

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

// Function to calculate the length of the Longest Palindromic Subsequence using memoization
int longestPalindromeSubsequenceMemoization(string s) {
    string t = s;
    reverse(t.begin(), t.end()); // Create a reversed copy of the string
    return lcsMemoization(s, t); // Call the LCS function to find the length of the LCS
}

// Function to calculate the length of the Longest Palindromic Subsequence using tabulation
int longestPalindromeSubsequenceTabulation(string s) {
    string t = s;
    reverse(t.begin(), t.end()); // Create a reversed copy of the string
    return lcsTabulation(s, t); // Call the LCS function to find the length of the LCS
}

// Function to calculate the length of the Longest Palindromic Subsequence using space optimization
int longestPalindromeSubsequenceSpaceOptimized(string s) {
    string t = s;
    reverse(t.begin(), t.end()); // Create a reversed copy of the string
    return lcsSpaceOptimized(s, t); // Call the LCS function to find the length of the LCS
}

/*
TIME COMPLEXITY:
- All approaches: O(n * m), where n is the length of the string.

SPACE COMPLEXITY:
- Memoization approach: O(n * m) for the dp array.
- Tabulation approach: O(n * m) for the dp array.
- Space-optimized approach: O(m) for the cur and prev arrays.

EXAMPLE USAGE:
string s = "BBABCBCAB";
int resultMemoization = longestPalindromeSubsequenceMemoization(s); // Using memoization
int resultTabulation = longestPalindromeSubsequenceTabulation(s); // Using tabulation
int resultOptimized = longestPalindromeSubsequenceSpaceOptimized(s); // Using space-optimized approach
*/
