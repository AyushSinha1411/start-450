/*
EXAMPLE:
Input: s1 = "rabbbit", s2 = "rabbit"
Output: 3
Explanation: The three distinct subsequences are:
1. "rabbbit" -> "rabbit" (delete the 3rd 'b')
2. "rabbbit" -> "rabbit" (delete the 4th 'b')
3. "rabbbit" -> "rabbit" (delete the 5th 'b')

QUESTION:
Given two strings s1 and s2, find the number of distinct subsequences of s2 in s1.

APPROACH:
1. Use three approaches to solve the problem:
   a. Recursive approach with memoization.
   b. Tabulation approach.
   c. Space-optimized approach.

CODE:
*/

// Constant to handle large numbers with modulo operation
const int prime = 1e9 + 7;

// Function to count the number of distinct subsequences of s2 in s1 using memoization
int countUtil(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp) {
    // If s2 has been completely matched, return 1 (found a valid subsequence)
    if (ind2 < 0)
        return 1;
    
    // If s1 has been completely traversed but s2 hasn't, return 0
    if (ind1 < 0)
        return 0;

    // If the result for this state has already been calculated, return it
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;

    // If the characters match, consider two options: leave one character in s1 and s2
    // or leave one character in s1 and continue matching s2
    if (s1[ind1] == s2[ind2]) {
        int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);

        result = (leaveOne + stay) % prime;
    } else {
        // If characters don't match, just leave one character in s1 and continue matching s2
        result = countUtil(s1, s2, ind1 - 1, ind2, dp);
    }

    // Store the result and return it
    dp[ind1][ind2] = result;
    return result;
}

// Function to count the number of distinct subsequences of s2 in s1 using memoization
int subsequenceCountingMemo(string &s1, string &s2, int lt, int ls) {
    vector<vector<int>> dp(lt, vector<int>(ls, -1));
    return countUtil(s1, s2, lt - 1, ls - 1, dp);
}

// Function to count the number of distinct subsequences of s2 in s1 using tabulation
int subsequenceCountingTabulation(string &s1, string &s2, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row: empty string s2 can be matched with any non-empty s1 in one way
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Initialize the first column: s1 can't match any non-empty s2
    for (int i = 1; i <= m; i++) {
        dp[0][i] = 0;
    }

    // Fill in the DP array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][m];
}

// Function to count the number of distinct subsequences of s2 in s1 using space optimization
int subsequenceCountingSpaceOptimized(string &s1, string &s2, int n, int m) {
    vector<int> prev(m + 1, 0);

    // Initialize the count for an empty string (base case)
    prev[0] = 1;

    // Iterate through s1 and s2 to calculate the counts
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (s1[i - 1] == s2[j - 1]) {
                prev[j] = (prev[j - 1] + prev[j]) % prime;
            }
        }
    }

    return prev[m];
}

/*
TIME COMPLEXITY:
- All approaches: O(n * m), where n and m are the lengths of the two strings.

SPACE COMPLEXITY:
- Memoization approach: O(n * m) for the dp array.
- Tabulation approach: O(n * m) for the dp array.
- Space-optimized approach: O(m) for the prev array.

EXAMPLE USAGE:
string s1 = "rabbbit";
string s2 = "rabbit";
int resultMemo = subsequenceCountingMemo(s1, s2, s1.size(), s2.size()); // Using memoization
int resultTab = subsequenceCountingTabulation(s1, s2, s1.size(), s2.size()); // Using tabulation
int resultOpt = subsequenceCountingSpaceOptimized(s1, s2, s1.size(), s2.size()); // Using space-optimized approach
*/
