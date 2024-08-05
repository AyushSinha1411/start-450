#include <bits/stdc++.h>
using namespace std;

/*
 * Question:
 * Given a string `s` and a dictionary of strings `wordDict`, return true if `s` can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * Approach:
 * 1. Use a recursive function with memoization to check if the string can be segmented.
 * 2. For each position in the string, try to segment the string into a prefix that exists in the dictionary and recurse for the remaining substring.
 * 3. Use a memoization table to store results of subproblems.
 */

// Recursive function to check if the string can be segmented with memoization
bool wordBreakHelper(const string &s, const unordered_set<string> &wordDict, int start, vector<int> &memo) {
    // Base case: if start reaches the end of the string, return true
    if (start == s.size()) {
        return true;
    }
    
    // If the subproblem is already solved, return the stored result
    if (memo[start] != -1) {
        return memo[start];
    }
    
    // Try every possible end position for the current substring
    for (int end = start + 1; end <= s.size(); ++end) {
        // If the current substring is in the dictionary, recurse for the remaining substring
        if (wordDict.find(s.substr(start, end - start)) != wordDict.end() && wordBreakHelper(s, wordDict, end, memo)) {
            return memo[start] = true;
        }
    }
    
    return memo[start] = false; // No valid segmentation found
}

// Function to check if the string can be segmented
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); // Convert vector to unordered_set for faster lookups
    vector<int> memo(s.size(), -1); // Initialize memoization table with -1
    return wordBreakHelper(s, wordSet, 0, memo); // Start the recursion from the first character
}

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << (wordBreak(s, wordDict) ? "true" : "false") << endl; // Output: true
    return 0;
}

/*
 * Time Complexity:
 * The time complexity is O(n^2) in the worst case, where n is the length of the string `s`, due to the memoization reducing the exponential calls.
 *
 * Space Complexity:
 * The space complexity is O(n) for the memoization table and the recursion stack.
 */
