// Question: Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
// The string is valid if:
// 1. Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// 2. Any right parenthesis ')' must have a corresponding left parenthesis '('.
// 3. Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// 4. '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
// Example:
// Input: s = "(*))"
// Output: true
// Explanation: The string is valid since it can be converted to "(())" or "()" or "(()".
// Approach:
// We use two variables min and max to represent the minimum and maximum possible number of open parentheses.
// We iterate through the string and update these variables based on the current character.
// If at any point, max becomes negative, it means there are more closing parentheses than opening ones, so we return false.
// If min becomes negative, we reset it to 0 since '*' can balance it out.
// Finally, we return true if min is 0 at the end, indicating all open parentheses are closed.
// Time Complexity: O(n), where n is the length of the string. Each character is processed once.
// Space Complexity: O(1), since we are using a fixed number of extra variables.

#include <string>
using namespace std;

bool checkValidString(string s) {
    int n = s.size();  // Length of the input string
    int minOpen = 0;   // Minimum possible number of open parentheses
    int maxOpen = 0;   // Maximum possible number of open parentheses

    // Iterate through the string
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            minOpen++;  // Increase both min and max for '('
            maxOpen++;
        } else if (s[i] == ')') {
            minOpen--;  // Decrease both min and max for ')'
            maxOpen--;
        } else {
            minOpen--;  // Decrease min and increase max for '*'
            maxOpen++;
        }

        if (minOpen < 0) {
            minOpen = 0;  // Reset min to 0 if it becomes negative
        }
        if (maxOpen < 0) {
            return false; // Return false if max becomes negative
        }
    }

    return minOpen == 0; // Return true if min is 0 at the end
}
