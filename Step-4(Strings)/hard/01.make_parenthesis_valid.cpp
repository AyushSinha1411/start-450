/*
QUESTION:
Given a string s containing only the characters '(' and ')', return the minimum number of parentheses we must add to make the resulting parentheses string valid.

Example:
Input: "())"
Output: 1

Input: "((("
Output: 3

APPROACH:
1. Initialize two counters: missingRight to count missing ')' and unbalancedLeft to count unmatched '('.
2. Iterate through the string:
   a. Increment unbalancedLeft for each '('.
   b. For each ')', if there are unmatched '(', decrement unbalancedLeft. Otherwise, increment missingRight.
3. The total number of parentheses to add is the sum of missingRight and unbalancedLeft.

CODE:
*/

#include <string>
using namespace std;

int minAddToMakeValid(string s) {
    int missingRight = 0;  // Counter for missing ')'
    int unbalancedLeft = 0;  // Counter for unmatched '('

    // Iterate through each character in the string
    for (char c : s) {
        if (c == '(') {
            unbalancedLeft++;  // Increment for an unmatched '('
        } else if (c == ')') {
            if (unbalancedLeft > 0) {
                unbalancedLeft--;  // Match a '(' with this ')'
            } else {
                missingRight++;  // Increment for a missing ')'
            }
        }
    }

    // Total characters to add to make the string valid
    return missingRight + unbalancedLeft;
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the input string. Each character is processed exactly once.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used for the counters.
*/
