/*
QUESTION:
Write a function to find the minimum window in string s1 which will contain all the characters of string s2 in the same order. If there is no such window, return the empty string.

Example:
Input: s1 = "abcdebdde", s2 = "bde"
Output: "bcde"
Explanation: The minimum window substring is "bcde" which contains all characters 'b', 'd', and 'e' from string s2 in order.

APPROACH:
1. Iterate through the string s1 and match the characters with string s2.
2. When all characters in s2 are matched, try to shrink the window from the leftmost part containing all characters of s2.
3. Update the minimum window length and position during the shrinking process.
4. Return the minimum window substring.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s1, string s2) {
    int m = s1.size(); // Length of s1
    int n = s2.size(); // Length of s2
    int start = 0; // Start index of the minimum window in s1
    int len = INT_MAX; // Length of the minimum window, initialized to a very large value
    int count = 0; // Count of matched characters from s2 in s1

    // Iterate through s1 to find the minimum window that contains s2 in order
    for (int i = 0; i < m; i++) {
        if (s1[i] == s2[count]) count++; // If current character in s1 matches the current character in s2, increase the count

        // When all characters in s2 are matched in order
        if (count == n) {
            int j = i; // Start from the current position i
            // Move backward to find the minimum window by matching all characters of s2 in reverse order
            while (count > 0) {
                if (s2[count - 1] == s1[j--]) {
                    count--; // Reduce the count as we match characters from s2 in reverse order
                }
            }
            j++; // j is now the index in s1 where the first character of s2 is found in this window

            // Update the minimum length and start index if a smaller window is found
            if (len > i - j + 1) {
                len = i - j + 1;
                start = j;
            }
            // Move i back to the index after the start of the found window so the next search starts from j+1
            i = j;
        }
    }

    // If len is not updated, no valid window was found, return an empty string
    if (len == INT_MAX) return "";
    return s1.substr(start, len); // Return the minimum window substring
}


/*
TIME COMPLEXITY: O(M*N), where M is the length of s1 and N is the length of s2. This is because each character in s1 is visited and potentially re-visited to find the minimal window.
SPACE COMPLEXITY: O(1), since we only use a few extra variables for calculations.
*/
