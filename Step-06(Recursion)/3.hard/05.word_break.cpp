/*
QUESTION:
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Example:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

APPROACH:
1. Use dynamic programming to determine if the string can be segmented.
2. Create a dp array where dp[i] indicates whether the substring s[0:i] can be segmented.
3. Iterate over the string and for each position, check all possible substrings ending at that position.
4. If a valid word is found that ends at position i and the beginning of the word can be segmented, mark dp[i] as true.
5. Return the value of dp[s.size()] as the result.

CODE:
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

// Function to check if the string can be segmented into a sequence of dictionary words
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true; // Base case: an empty string can always be segmented
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && words.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

/*
TIME COMPLEXITY: O(N^2), where N is the length of the string. This is because for each character in the string, we check all possible substrings ending at that character.
SPACE COMPLEXITY: O(N), due to the dp array used to store the segmentation results.
*/
