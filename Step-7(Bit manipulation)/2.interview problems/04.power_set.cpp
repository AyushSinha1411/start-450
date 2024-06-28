/*
QUESTION:
Given a string s, generate all possible non-empty substrings of the string. The substrings should be returned in lexicographical order.

Example:
Input: s = "abc"
Output: ["a", "ab", "abc", "ac", "b", "bc", "c"]
Explanation: All possible non-empty substrings are generated and sorted in lexicographical order.

APPROACH:
1. Use bit manipulation to generate all possible subsets of the string.
2. Iterate through all numbers from 1 to (2^n - 1) where n is the length of the string.
3. For each number, use its binary representation to decide which characters to include in the current substring.
4. Add each non-empty substring to the result vector.
5. Sort the result vector in lexicographical order.

CODE:
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to generate all possible non-empty substrings of the string
vector<string> AllPossibleStrings(string s) {
    int n = s.length();
    vector<string> ans;
    for (int num = 0; num < (1 << n); num++) {
        string sub = "";
        for (int i = 0; i < n; i++) {
            // Check if the ith bit is set or not
            if (num & (1 << i)) {
                sub += s[i];
            }
        }
        if (!sub.empty()) {
            ans.push_back(sub);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

/*
TIME COMPLEXITY: O(2^N * N), where N is the length of the string. This is because there are 2^N subsets and each subset takes O(N) time to generate.
SPACE COMPLEXITY: O(2^N * N), to store all possible non-empty substrings.
*/