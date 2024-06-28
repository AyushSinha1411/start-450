/*
QUESTION:
Given two strings s1 and s2, find the shortest supersequence such that it contains both s1 and s2 as subsequences.

APPROACH:
1. Use Dynamic Programming to find the length of the Longest Common Subsequence (LCS) of the two strings.
2. Construct the shortest supersequence by combining the characters of s1 and s2, ensuring that the LCS is included.

EXAMPLE:
Input: s1 = "abc", s2 = "ac"
Output: "abc"
Explanation: The shortest supersequence is "abc" which contains both s1 ("abc") and s2 ("ac").

CODE:
*/

// Function to find the shortest supersequence of two strings
string shortestSupersequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // Create a 2D DP array to store the length of the LCS
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP array to calculate the length of LCS
    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    // Construct the shortest supersequence
    int i = n, j = m;
    string ans = "";

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans += s1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            ans += s1[i - 1];
            i--;
        } else {
            ans += s2[j - 1];
            j--;
        }
    }

    // Add remaining characters from s1 and s2
    while (i > 0) {
        ans += s1[i - 1];
        i--;
    }
    while (j > 0) {
        ans += s2[j - 1];
        j--;
    }

    // Reverse the string to get the final result
    reverse(ans.begin(), ans.end());
    
    return ans;
}

/*
TIME COMPLEXITY:
- O(n * m), where n and m are the lengths of the two strings.

SPACE COMPLEXITY:
- O(n * m) for the dp array.

EXAMPLE USAGE:
string s1 = "abc";
string s2 = "ac";
string result = shortestSupersequence(s1, s2); // "abc"
*/
