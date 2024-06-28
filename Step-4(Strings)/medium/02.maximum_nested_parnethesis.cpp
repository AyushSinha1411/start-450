/*
QUESTION:
Given a valid parentheses string s, return the maximum depth of nested parentheses. The depth of a valid parentheses substring is the maximum number of open parentheses that appear at the same time.

Example:
Input: "(1+(2*3)+((8)/4))+1"
Output: 3

APPROACH:
1. Initialize two variables: 'ans' to store the maximum depth and 'openBrackets' to track the current number of open parentheses.
2. Iterate through each character in the string:
   a. If the character is '(', increment 'openBrackets'.
   b. If the character is ')', decrement 'openBrackets'.
   c. Update 'ans' to be the maximum of its current value and 'openBrackets'.
3. Return the value of 'ans' as the maximum depth of nested parentheses.

CODE:
*/

#include <string>
#include <algorithm>
using namespace std;

int maxDepth(string s) {
    int ans = 0;            // To store the maximum depth
    int openBrackets = 0;   // To track the number of open parentheses

    // Iterate through each character in the string
    for (char c : s) {
        if (c == '(') {
            openBrackets++; // Increment for an open parenthesis
        } else if (c == ')') {
            openBrackets--; // Decrement for a close parenthesis
        }
        
        // Update the maximum depth
        ans = max(ans, openBrackets);
    }
    
    // Return the maximum depth of nested parentheses
    return ans;
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the string. Each character is processed exactly once.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
