/*
QUESTION:
Given a string s, find the longest palindromic substring in s. A palindrome is a string that reads the same forward and backward.

Example:
Input: "babad"
Output: "bab" (or "aba", as both are correct answers)

APPROACH:
1. If the string length is less than or equal to 1, return the string itself.
2. Define a helper function expand_from_center to expand around the center and find the longest palindrome.
3. Iterate through the string, treating each character (and the gap between each pair of characters) as the center of a potential palindrome.
4. For each center, use expand_from_center to find the longest palindrome with that center.
5. Update the maximum length palindrome found so far.
6. Return the longest palindrome found.

CODE:
*/

#include <string>
using namespace std;

string longestPalindrome(string s) {
    // If the string length is less than or equal to 1, return the string itself
    if (s.length() <= 1) {
        return s;
    }

    // Helper function to expand around the center and find the longest palindrome
    auto expand_from_center = [&](int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    };

    string max_str = s.substr(0, 1); // Initialize the maximum palindrome with the first character

    // Iterate through the string
    for (int i = 0; i < s.length() - 1; i++) {
        // Find the longest palindrome with the center at i (odd length)
        string odd = expand_from_center(i, i);
        // Find the longest palindrome with the center between i and i+1 (even length)
        string even = expand_from_center(i, i + 1);

        // Update the maximum palindrome string if a longer one is found
        if (odd.length() > max_str.length()) {
            max_str = odd;
        }
        if (even.length() > max_str.length()) {
            max_str = even;
        }
    }

    // Return the longest palindrome substring found
    return max_str;
}

/*
TIME COMPLEXITY: O(n^2), where 'n' is the length of the input string. Each expansion can take O(n) time and there are O(n) centers to consider.
SPACE COMPLEXITY: O(1), as we only use a few extra variables and do not use space proportional to the input size.
*/
