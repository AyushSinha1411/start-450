/*
QUESTION:
Given a string str, count the number of palindromic subsequences in it. Since the result can be very large, return it modulo 1000000007.

Example:
Input: "abcb"
Output: 6
Explanation: The palindromic subsequences are: "a", "b", "c", "b", "bcb", "aba".

APPROACH:
1. Initialize a 2D array dp where dp[i][j] will store the count of palindromic subsequences in the substring str[i..j].
2. Each single character is a palindrome, so initialize dp[i][i] = 1.
3. For each possible length of substring (from 2 to n), update the dp table:
   a. If the characters at both ends of the substring are the same (str[i] == str[j]), then:
      dp[i][j] = (dp[i+1][j] + dp[i][j-1] + 1) % MOD.
   b. If the characters at both ends are different (str[i] != str[j]), then:
      dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + MOD) % MOD.
4. Return dp[0][n-1] which contains the count of palindromic subsequences in the entire string.

CODE:
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MOD = 1000000007; // Define the modulo constant for large numbers

class Solution {
public:
    long long int countPS(string str) {
        int n = str.length(); // Get the length of the input string
        long long int dp[n][n]; // Define a 2D array to store the count of palindromic subsequences
        memset(dp, 0, sizeof(dp)); // Initialize the 2D array with 0

        // Base case: Every single character is a palindrome
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        // Fill the dp table for substrings of length greater than 1
        for (int len = 2; len <= n; ++len) { // Length of substring ranges from 2 to n
            for (int i = 0; i <= n - len; ++i) { // Start index of the substring
                int j = i + len - 1; // End index of the substring
                if (str[i] == str[j]) {
                    // If the characters at the start and end are the same
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
                    // dp[i + 1][j] is the count of palindromic subsequences excluding the current start character
                    // dp[i][j - 1] is the count of palindromic subsequences excluding the current end character
                    // 1 is added because str[i] and str[j] form a new palindromic subsequence
                } else {
                    // If the characters at the start and end are different
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                    // dp[i + 1][j] is the count of palindromic subsequences excluding the current start character
                    // dp[i][j - 1] is the count of palindromic subsequences excluding the current end character
                    // dp[i + 1][j - 1] is subtracted because these subsequences are counted twice
                    // Adding MOD before taking modulo ensures that we don't get a negative result
                }
            }
        }

        // Return the count of palindromic subsequences for the entire string
        return dp[0][n - 1];
    }
};


/*
TIME COMPLEXITY: O(n^2), where 'n' is the length of the input string. The dynamic programming table is filled in a nested loop over all substrings.
SPACE COMPLEXITY: O(n^2), due to the 2D dp array used to store the results for all substrings.
*/
