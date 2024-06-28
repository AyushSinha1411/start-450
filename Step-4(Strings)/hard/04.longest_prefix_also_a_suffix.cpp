/*
QUESTION:
Given a string s, find the longest prefix of s which is also a suffix. The prefix and suffix should not overlap.

Example:
Input: "ababab"
Output: "abab"

APPROACH:
1. Use the Knuth-Morris-Pratt (KMP) algorithm to preprocess the string and build the LPS (Longest Prefix Suffix) array.
2. The value at the last position of the LPS array gives the length of the longest prefix which is also a suffix.
3. Return the substring from the start of the string up to this length.

CODE:
*/

#include <string>
#include <vector>
using namespace std;

string longestPrefix(string s) {
    int n = s.length();
    vector<int> lps(n, 0); // Create an array to store the longest prefix suffix values

    int len = 0; // Length of the previous longest prefix suffix

    // Preprocess the string to build the LPS (Longest Prefix Suffix) array
    for (int i = 1; i < n;) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // Return the longest prefix which is also a suffix
    return s.substr(0, lps[n - 1]);
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the input string. The preprocessing step to build the LPS array takes linear time.
SPACE COMPLEXITY: O(n), where 'n' is the length of the input string. The additional space is used for the LPS array.
*/
