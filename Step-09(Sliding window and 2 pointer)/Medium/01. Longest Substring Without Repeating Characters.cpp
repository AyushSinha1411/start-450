// Question: Given a string s, find the length of the longest substring without repeating characters.
// Example: 
// Input: "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Approach:
// We use the sliding window technique with two pointers (left and right) and a hash array to keep track of the last seen index of each character. 
// We move the right pointer to expand the window and update the left pointer when a repeating character is found to ensure all characters in the current window are unique.

#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();   // Length of the input string
    int maxlen = 0;       // Maximum length of the substring without repeating characters
    int l = 0, r = 0;     // Left and right pointers for the sliding window

    int hash[255];        // Hash array to keep track of the last seen index of each character
    memset(hash, -1, sizeof(hash)); // Initialize the hash array to -1

    // Iterate over the string with the right pointer
    while (r < n) {
        // If the character at the right pointer has been seen before 
        // and is within the current window (l to r)
        if (hash[s[r]] != -1 && hash[s[r]] >= l) {
            // Move the left pointer to one position right of the last seen index
            l = hash[s[r]] + 1;
        }

        // Update the last seen index of the character at the right pointer
        hash[s[r]] = r;
        
        // Update the maximum length of the substring
        maxlen = max(maxlen, r - l + 1);
        
        // Move the right pointer to the next character
        r++;
    }

    return maxlen; // Return the maximum length of the substring without repeating characters
}
// Time Complexity: O(n), where n is the length of the string. Each character is visited at most twice.
// Space Complexity: O(1), since the hash array size is constant.
