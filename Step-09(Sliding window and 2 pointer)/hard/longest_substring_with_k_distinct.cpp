// Question: Given a string s and an integer k, return the length of the longest substring that contains at most k distinct characters.
// Example:
// Input: s = "eceba", k = 2
// Output: 3
// Explanation: The substring is "ece" with length 3.
// Approach:
// We use the sliding window technique with a hashmap to keep track of the frequency of each character in the current window. 
// We expand the window by moving the right pointer, and when the number of distinct characters exceeds k, we move the left pointer to maintain the condition. 
// The maximum length of the valid window is updated during the process.
// Time Complexity: O(n), where n is the length of the string. Each character is visited at most twice.
// Space Complexity: O(256) = O(1), since the size of the hashmap is constant.

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    int maxLen = 0; // Maximum length of the substring with at most k distinct characters
    int left = 0;   // Left pointer for the sliding window
    unordered_map<char, int> mpp; // Hashmap to keep track of the count of each character

    // Iterate over the string with the right pointer
    for (int right = 0; right < s.size(); ++right) {
        mpp[s[right]]++; // Increment the count of the current character

        // If the number of distinct characters exceeds k, move the left pointer
       if (mpp.size() > k) {
            mpp[s[left]]--; // Decrement the count of the character at the left pointer
            if (mpp[s[left]] == 0) {
                mpp.erase(s[left]); // Remove the character if its count becomes 0
            }
            left++; // Move the left pointer to the right
        }

        // Update the maximum length of the substring
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen; // Return the maximum length of the substring with at most k distinct characters
}
