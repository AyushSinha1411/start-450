/*
QUESTION:
Given a valid parentheses string S, consider its primitive decomposition: a primitive valid parentheses string is a non-empty string that 
cannot be decomposed into two or more non-empty valid parentheses strings. Your task is to remove the outermost parentheses of every primitive 
string in the primitive decomposition of S and return the resulting string.

Example:
Input: "(()())(())"
Output: "()()()"

APPROACH:
1. Initialize an empty result string 'res'.
2. Use an integer 'opened' to keep track of the balance of opened parentheses.
3. Iterate through each character in the string S:
   a. If the character is '(', increment 'opened'. If 'opened' is greater than 1, add the character to 'res' (it is not an outermost parenthesis).
   b. If the character is ')', decrement 'opened'. If 'opened' is greater than 0, add the character to 'res' (it is not an outermost parenthesis).
4. Return the resulting string 'res' after the loop ends.

CODE:
*/

#include <string>
using namespace std;

string removeOuterParentheses(string S) {
    string res;
    int opened = 0;

    // Iterate through each character in the input string S
    for (char c : S) {
        // If the character is '(', increment 'opened'
        if (c == '(') {
            // If 'opened' is greater than 0, add the character to 'res'
            if (opened++ > 0) res += c;
        }
        // If the character is ')', decrement 'opened'
        else {
            // If 'opened' is greater than 1, add the character to 'res'
            if (opened-- > 1) res += c;
        }
    }
    return res; // Return the resulting string
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the input string. Each character is processed exactly once.
SPACE COMPLEXITY: O(n), where 'n' is the length of the input string. In the worst case, the result string can be of the same length as the input.
*/
