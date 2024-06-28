/*
QUESTION:
Given a string s, find the minimum number of insertions required to make it a palindrome.

APPROACH:
1. To solve this problem, first find the length of the Longest Palindromic Subsequence (LPS).
2. The minimum number of insertions required to make the string a palindrome is the difference between the string length and the LPS length.

EXAMPLE:
Input: s = "abcaa"
Output: 2
Explanation: We need to add 'a' and 'c' to make "abcaa" a palindrome "aabcaa".

CODE:
*/

// Function to calculate the length of the Longest Common Subsequence
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Create a 2D DP array to store the length of the LCS
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP array
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    // The value at dp[n][m] contains the length of the LCS
    return dp[n][m];
}

// Function to calculate the length of the Longest Palindromic Subsequence
int longestPalindromeSubsequence(string s) {
    // Create a reversed copy of the string
    string t = s;
    reverse(s.begin(), s.end());
    // Call the LCS function to find the length of the Longest Common Subsequence
    return lcs(s, t);
}

// Function to calculate the minimum insertions required to make a string palindrome
int minInsertion(string s) {
    int n = s.size();
    int k = longestPalindromeSubsequence(s);

    // The minimum insertions required is the difference between the string length and its longest palindromic subsequence length
    return n - k;
}

// Function to calculate the length of the Longest Common Subsequence using space optimization
int lcsSpaceOptimized(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Create two arrays to store the previous and current rows of DP values
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // Base Case is covered as we have initialized the prev and cur to 0.

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            else
                cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
        }
        // Update the prev array with the current values
        prev = cur;
    }

    // The value at prev[m] contains the length of the LCS
    return prev[m];
}

// Function to calculate the length of the Longest Palindromic Subsequence using space optimization
int longestPalindromeSubsequenceOptimized(string s) {
    // Create a reversed copy of the string
    string t = s;
    reverse(s.begin(), s.end());
    // Call the LCS function to find the length of the Longest Common Subsequence
    return lcsSpaceOptimized(s, t);
}

// Function to calculate the minimum insertions required to make a string palindrome using space optimization
int minInsertionOptimized(string s) {
    int n = s.size();
    int k = longestPalindromeSubsequenceOptimized(s);

    // The minimum insertions required is the difference between the string length and its longest palindromic subsequence length
    return n - k;
}

/*
TIME COMPLEXITY:
- Both approaches: O(n * m), where n is the length of the string.

SPACE COMPLEXITY:
- Basic approach: O(n * m) for the dp array.
- Space-optimized approach: O(m) for the cur and prev arrays.

EXAMPLE USAGE:
string s = "abcaa";
int resultBasic = minInsertion(s); // Using basic approach
int resultOptimized = minInsertionOptimized(s); // Using space-optimized approach
*/
