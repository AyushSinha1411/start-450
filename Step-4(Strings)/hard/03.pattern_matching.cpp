/*
QUESTION:
Given two strings `text` and `pat`, find the first occurrence of the pattern `pat` in the text `text`. If the pattern is found, return the starting index of the pattern in the text. Otherwise, return -1.

Example:
Input: text = "abcxabcdabxabcdabcdabcy", pat = "abcdabcy"
Output: 15

APPROACH:
1. Use the Knuth-Morris-Pratt (KMP) algorithm to find the first occurrence of the pattern in the text.
2. Preprocess the pattern to build the LPS (Longest Prefix Suffix) array.
3. Use the LPS array to skip characters while matching the pattern in the text.
4. If the pattern is found, return the starting index; otherwise, return -1.

CODE:
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMatching(string text, string pat) {
        int n = text.length();
        int m = pat.length();

        // Edge case: empty pattern
        if (m == 0) return 0;
        
        vector<int> lps(m); // Create an array to store the longest prefix suffix values for pattern

        // Preprocess the pattern to build the LPS (Longest Prefix Suffix) array
        computeLPS(pat, m, lps);

        int i = 0; // Index for text
        int j = 0; // Index for pattern

        // Iterate through the text
        while (i < n) {
            if (text[i] == pat[j]) {
                i++;
                j++;
            }

            // Pattern found
            if (j == m) {
                return i - j;
            }
            // Mismatch after j matches
            else if (i < n && text[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        // Pattern not found
        return -1;
    }

private:
    void computeLPS(const string& pat, int m, vector<int>& lps) {
        int len = 0; // Length of the previous longest prefix suffix

        lps[0] = 0; // lps[0] is always 0

        int i = 1;
        // Build the LPS array
        while (i < m) {
            if (pat[i] == pat[len]) {
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
    }
};

/*
TIME COMPLEXITY: O(n + m), where 'n' is the length of the text and 'm' is the length of the pattern. The preprocessing of the pattern takes O(m) time and the search process takes O(n) time.
SPACE COMPLEXITY: O(m), where 'm' is the length of the pattern. The space is used for the LPS array.
*/
