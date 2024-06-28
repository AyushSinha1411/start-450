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

#include <string>
#include <climits>
using namespace std;

// Function to find the minimum window in s1 containing all characters of s2 in order
string minWindow(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    int start = 0, len = INT_MAX, count = 0;

    for (int i = 0; i < m; i++) {
        if (s1[i] == s2[count]) count++;

        // All characters in s2 are matched. Now reduce the window to the rightmost part which has all the characters in s2
        if (count == n) {
            int j = i;
            while (count > 0) {
                if (s2[count - 1] == s1[j--]) {
                    count--;
                }
            }
            j++; // index in s1 which is the first character in s2

            if (len > i - j + 1) {
                len = i - j + 1;
                start = j;
            }
            // move back i so it starts next search from j+1 in next iteration
            i = j;
        }
    }

    if (len == INT_MAX) return "";
    return s1.substr(start, len);
}

/*
TIME COMPLEXITY: O(M*N), where M is the length of s1 and N is the length of s2. This is because each character in s1 is visited and potentially re-visited to find the minimal window.
SPACE COMPLEXITY: O(1), since we only use a few extra variables for calculations.
*/
