/*
QUESTION:
Given two strings str1 and str2, find the minimum number of operations required to convert str1 into str2. The allowed operations are insertion and deletion of characters.

APPROACH:
1. Calculate the length of the Longest Common Subsequence (LCS) between the two strings.
2. The minimum number of operations required to convert str1 to str2 is the sum of:
   a. The number of deletions required to remove characters from str1 that are not in the LCS.
   b. The number of insertions required to add characters to str1 to match str2.

EXAMPLE:
Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 
- Remove 'h' from "heap" -> "eap"
- Remove 'e' from "eap" -> "ap"
- Insert 'p' at the beginning -> "pea"

CODE:
*/

// Function to calculate the length of the Longest Common Subsequence
int lcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    // Initialize the first row and first column to 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }

    for (int ind1 = 1; ind1 <= n; ind1++) {
        for (int ind2 = 1; ind2 <= m; ind2++) {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    return dp[n][m];
}

// Function to calculate the minimum operations required to convert str1 to str2
int canYouMake(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    
    // Calculate the length of the longest common subsequence between str1 and str2
    int k = lcs(str1, str2);
    
    // Calculate the minimum operations required to convert str1 to str2
    return (n - k) + (m - k);
}

// Function to calculate the length of the Longest Common Subsequence using space optimization
int lcsOptimized(string s1, string s2) {
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

// Function to calculate the minimum operations required to convert str1 to str2 using space optimization
int canYouMakeOptimized(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    
    // Calculate the length of the longest common subsequence between str1 and str2
    int k = lcsOptimized(str1, str2);
    
    // Calculate the minimum operations required to convert str1 to str2
    return (n - k) + (m - k);
}

/*
TIME COMPLEXITY:
- Both approaches: O(n * m), where n and m are the lengths of the two strings.

SPACE COMPLEXITY:
- Basic approach: O(n * m) for the dp array.
- Space-optimized approach: O(m) for the cur and prev arrays.

EXAMPLE USAGE:
string str1 = "heap";
string str2 = "pea";
int resultBasic = canYouMake(str1, str2); // Using basic approach
int resultOptimized = canYouMakeOptimized(str1, str2); // Using space-optimized approach
*/
