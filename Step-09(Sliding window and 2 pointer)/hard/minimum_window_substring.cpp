// Question: Given two strings s and t, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
// Example:
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring is "BANC".
// Approach:
// We use the sliding window technique and a hashmap to keep track of the count of characters in t. 
// We expand the window by moving the right pointer, and when we have all the characters of t in the current window, 
// we move the left pointer to minimize the window size. The minimum length of the valid window is updated during the process.
// Time Complexity: O(n), where n is the length of the string s. Each character is visited at most twice.
// Space Complexity: O(1), since the size of the hashmap is constant.

#include <string>
#include <vector>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    // Edge case: if either string is empty
    if (s.empty() || t.empty()) {
        return "";
    }

    vector<int> hash(256, 0); // Hashmap to count characters in t
    int left = 0, right = 0;  // Left and right pointers for the sliding window
    int minLen = INT_MAX;     // Minimum length of the valid window
    int startIdx = -1;        // Starting index of the minimum window substring
    int count = 0;            // Count of characters from t in the current window
    int n = s.size();         // Length of string s
    int m = t.size();         // Length of string t

    // Initialize the hashmap with the count of characters in t
    for (int i = 0; i < m; i++) {
        hash[t[i]]++;
    }

    // Iterate over the string with the right pointer
    while (right < n) {
        // If the current character is in t, increment the count
        if (hash[s[right]] > 0) {
            count++;
        }
        // Decrement the count of the current character in the hashmap
        hash[s[right]]--;

        // When we have all characters of t in the current window
        while (count == m) {
            // Update the minimum length of the window
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                startIdx = left;
            }

            // Move the left pointer to minimize the window size
            hash[s[left]]++;
            if (hash[s[left]] > 0) {
                count--;
            }
            left++;
        }
        right++;
    }

    // Return the minimum window substring or an empty string if not found
    return startIdx == -1 ? "" : s.substr(startIdx, minLen);
}
