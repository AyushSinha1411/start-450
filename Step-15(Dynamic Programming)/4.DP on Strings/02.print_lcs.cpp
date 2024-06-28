/*
EXAMPLE:
Input: s1 = "ABCBDAB", s2 = "BDCAB"
Output: "BCAB"

QUESTION:
Given two strings s1 and s2, find and print the Longest Common Subsequence (LCS).

APPROACH:
1. Use dynamic programming to calculate the length of the LCS.
2. Construct the LCS string using the DP table.

CODE:
*/

void lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Create a DP table to store lengths of longest common subsequences.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row and first column to 0.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP table.
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1]) {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment the LCS length.
            } else {
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, take the maximum from left or above.
            }
        }
    }

    int len = dp[n][m]; // Length of the LCS.
    int i = n, j = m; // Start from the bottom-right corner of the DP table.

    // Initialize a string to store the LCS.
    string str(len, '$');

    // Backtrack to find the LCS.
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            str[--len] = s1[i - 1]; // If characters match, add to the LCS.
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--; // Move up in the DP table.
        } else {
            j--; // Move left in the DP table.
        }
    }

    // Print the LCS.
    cout << str << endl;
}
/*Time Complexity: O(N*M)

Reason: There are two nested loops

Space Complexity: O(N*M)

Reason: We are using an external array of size ‘N*M’. Stack Space is eliminated.*/