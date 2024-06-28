/*
EXAMPLE:
Input: S1 = "a*b?d", S2 = "abcd"
Output: true
Explanation: The pattern "a*b?d" matches "abcd".

QUESTION:
Given two strings S1 and S2, where S1 is a wildcard pattern that may contain '*' and '?', determine if S1 matches S2. 
- '*' can match any sequence of characters (including the empty sequence).
- '?' can match any single character.

APPROACH:
1. Use three approaches to solve the problem:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Function to check if a substring of S1 contains only '*'
bool isAllStars(string &S1, int i) {
    for (int j = 0; j <= i; j++) {
        if (S1[j] != '*')
            return false;
    }
    return true;
}

// Function to perform wildcard pattern matching using memoization
bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<bool>> &dp) {
    // Base Cases
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (j < 0 && i >= 0)
        return isAllStars(S1, i);

    // If the result for this state has already been calculated, return it
    if (dp[i][j] != -1)
        return dp[i][j];

    // If the characters at the current positions match or S1 has a '?'
    if (S1[i] == S2[j] || S1[i] == '?')
        return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
    else {
        if (S1[i] == '*')
            // Two options: either '*' represents an empty string or it matches a character in S2
            return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        else
            return false;
    }
}

// Main function to perform wildcard pattern matching using memoization
bool wildcardMatchingMemoization(string &S1, string &S2) {
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to memoize results
    vector<vector<bool>> dp(n, vector<bool>(m, -1));
    return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);
}

// Function to perform wildcard pattern matching using tabulation
bool wildcardMatchingTabulation(string &S1, string &S2) {
    int n = S1.size();
    int m = S2.size();

    // Create a DP table to memoize results
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Initialize the first row and column
    dp[0][0] = true;
    for (int j = 1; j <= m; j++) {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = isAllStars(S1, i);
    }

    // Fill in the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                if (S1[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }
    }

    // The value at dp[n][m] contains whether S1 matches S2
    return dp[n][m];
}

// Function to perform wildcard pattern matching using space optimization
bool wildcardMatchingSpaceOptimized(string &S1, string &S2) {
    int n = S1.size();
    int m = S2.size();

    // Create two arrays to store previous and current rows of matching results
    vector<bool> prev(m + 1, false);
    vector<bool> cur(m + 1, false);

    prev[0] = true; // Initialize the first element of the previous row to true

    for (int i = 1; i <= n; i++) {
        cur[0] = isAllStars(S1, i); // Initialize the first element of the current row
        for (int j = 1; j <= m; j++) {
            if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?') {
                cur[j] = prev[j - 1]; // Characters match or S1 has '?'
            } else {
                if (S1[i - 1] == '*') {
                    cur[j] = prev[j] || cur[j - 1]; // '*' represents empty or a character
                } else {
                    cur[j] = false; // Characters don't match and S1[i-1] is not '*'
                }
            }
        }
        prev = cur; // Update the previous row with the current row
    }

    // The value at prev[m] contains whether S1 matches S2
    return prev[m];
}

/*
TIME COMPLEXITY:
- All approaches: O(n * m), where n and m are the lengths of the two strings.

SPACE COMPLEXITY:
- Memoization approach: O(n * m) for the dp array.
- Tabulation approach: O(n * m) for the dp array.
- Space-optimized approach: O(m) for the prev and cur arrays.

EXAMPLE USAGE:
string S1 = "a*b?d";
string S2 = "abcd";
bool resultMemo = wildcardMatchingMemoization(S1, S2); // Using memoization
bool resultTab = wildcardMatchingTabulation(S1, S2); // Using tabulation
bool resultOpt = wildcardMatchingSpaceOptimized(S1, S2); // Using space-optimized approach
*/
