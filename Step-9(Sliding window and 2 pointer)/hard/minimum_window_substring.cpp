/*
QUESTION:
Write a function to find the minimum window substring in string s that contains all the characters in string t. If there is no such substring, return the empty string.

Example:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring is "BANC" which contains all characters 'A', 'B', and 'C' from string t.

APPROACH:
1. Use the sliding window technique to maintain a window that contains all characters of t.
2. Use a vector to keep track of the frequency of each character in t.
3. Initialize two pointers, start and i, to define the window.
4. Iterate through the string s with the i pointer.
5. Decrease the count of the current character in the frequency vector and decrement the required count if the character is needed.
6. If the required count is zero, update the minimum window length and adjust the start pointer to find the smallest window.
7. Return the minimum window substring.

CODE:
*/

#include <string>
#include <vector>
#include <climits>
using namespace std;

// Function to find the minimum window substring containing all characters of t
string minWindow(string s, string t) {
    if (s.size() == 0 || t.size() == 0) return "";
    
    vector<int> remaining(128, 0);
    int required = t.size();
    
    // Initialize the frequency vector with characters in t
    for (int i = 0; i < required; i++) remaining[t[i]]++;
    
    int minLen = INT_MAX, start = 0, left = 0, i = 0;
    
    while (i <= s.size() && start < s.size()) {
        // Expand the window by moving the right pointer
        if (required) {
            if (i == s.size()) break;
            remaining[s[i]]--;
            if (remaining[s[i]] >= 0) required--;
            i++;
        } 
        // Contract the window by moving the left pointer
        else {
            if (i - start < minLen) {
                minLen = i - start;
                left = start;
            }
            remaining[s[start]]++;
            if (remaining[s[start]] > 0) required++;
            start++;
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(left, minLen);
}

/*
TIME COMPLEXITY: O(N), where N is the length of the string s. This is because each character is visited at most twice (once by the i pointer and once by the start pointer).
SPACE COMPLEXITY: O(1), since the vector has a fixed size of 128 (for ASCII characters).
*/
