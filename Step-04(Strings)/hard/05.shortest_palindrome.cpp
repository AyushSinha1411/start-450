/*
QUESTION:
Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

Example:
Input: "aacecaaa"
Output: "aaacecaaa"

APPROACH:
1. Reverse the input string and concatenate it with the original string using a special character '#' in between to avoid overlap.
2. Use the KMP (Knuth-Morris-Pratt) algorithm to preprocess the concatenated string and build the prefix function (LPS array).
3. The value at the last position of the LPS array gives the length of the longest prefix of the original string which is also a suffix.
4. Use this length to determine the characters to be added in front of the original string to form the shortest palindrome.

CODE:
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string shortestPalindrome(string s) {
    int n = s.size();
    string rev(s);
    reverse(rev.begin(), rev.end()); // Reverse the original string
    string s_new = s + "#" + rev; // Concatenate original, special character, and reversed string
    int n_new = s_new.size();
    
    vector<int> f(n_new, 0); // LPS (Longest Prefix Suffix) array for KMP algorithm
    
    // Build the LPS array
    for (int i = 1; i < n_new; i++) {
        int t = f[i - 1];
        while (t > 0 && s_new[i] != s_new[t]) {
            t = f[t - 1];
        }
        if (s_new[i] == s_new[t]) {
            ++t;
        }
        f[i] = t;
    }
    
    // The characters to add are the characters before the longest palindromic prefix
    return rev.substr(0, n - f[n_new - 1]) + s;
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the input string. The preprocessing step to build the LPS array takes linear time.
SPACE COMPLEXITY: O(n), where 'n' is the length of the input string. The additional space is used for the reversed string and the LPS array.
*/
