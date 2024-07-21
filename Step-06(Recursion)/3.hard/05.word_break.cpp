// Question: Word Break
// Given a string `s` and a dictionary of strings `wordDict`, return true if `s` can be segmented into a space-separated sequence of one or more dictionary words.
// Example:
// s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Recursive with Memoization (Top-Down DP)
class Solution1 {
public:
    unordered_set<string> st; // Set to store dictionary words
    int t[301]; // Memoization array
    int n; // Length of the string

    bool solve(string &s, int idx) {
        // Base case: if index reaches the end of the string, return true
        if (idx == n) {
            return true;
        }

        // Check if the remaining substring is in the dictionary
        if (st.find(s.substr(idx, n - idx)) != st.end()) {
            return true;
        }

        // If the result is already computed, return it
        if (t[idx] != -1)
            return t[idx];

        // Try to partition the string at different lengths
        for (int l = 1; l <= n; l++) {
            string temp = s.substr(idx, l); // Substring from idx with length l
            if (st.find(temp) != st.end() && solve(s, idx + l))
                return t[idx] = true; // Store and return true if partition is valid
        }

        return t[idx] = false; // Store and return false if no valid partition is found
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(t, -1, sizeof(t)); // Initialize memoization array to -1
        st = unordered_set<string>(wordDict.begin(), wordDict.end()); // Initialize set with wordDict

        return solve(s, 0); // Start solving from index 0
    }
};

// Time Complexity: O(n^2), where `n` is the length of the string. Each recursive call checks substrings of different lengths.
// Space Complexity: O(n), where `n` is the depth of the recursion tree and space used by the memoization array.

// Approach 2: Bottom-Up DP
class Solution2 {
public:
    bool solve(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end()); // Set to store dictionary words
        int n = s.length();
        vector<bool> t(n + 1, false); // DP array to store results

        t[0] = true; // Empty string can always be segmented

        // Fill the DP array
        for (int i = 1; i <= n; i++) {
            // Try different breaking points
            for (int j = 0; j < i; j++) {
                string temp = s.substr(j, i - j); // Substring from j to i
                if (st.find(temp) != st.end() && t[j]) {
                    t[i] = true; // If substring is in dictionary and previous part can be segmented
                    break; // No need to check further
                }
            }
        }

        return t[n]; // Return the result for the entire string
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, wordDict);
    }
};

// Time Complexity: O(n^2), where `n` is the length of the string. We check each substring.
// Space Complexity: O(n), where `n` is the length of the string, used by the DP array.

// Main function to test the solutions
int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    
    Solution1 sol1;
    bool result1 = sol1.wordBreak(s, wordDict);
    cout << (result1 ? "true" : "false") << endl; // Output: true
    
    Solution2 sol2;
    bool result2 = sol2.wordBreak(s, wordDict);
    cout << (result2 ? "true" : "false") << endl; // Output: true
    
    return 0;
}