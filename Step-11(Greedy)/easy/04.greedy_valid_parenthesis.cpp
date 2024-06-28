/*
QUESTION:
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string as follows:
1. Any left parenthesis '(' must have a corresponding right parenthesis ')'.
2. Any right parenthesis ')' must have a corresponding left parenthesis '('.
3. Left parenthesis '(' must go before the corresponding right parenthesis ')'.
4. '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.

Example:
Input: s = "(*))"
Output: true

APPROACH:
1. Use two stacks, one to store the indices of open parentheses '(' and another for stars '*'.
2. Traverse the string:
   a. Push the index to the corresponding stack if the character is '(' or '*'.
   b. If the character is ')', pop from the openParentheses stack if not empty, otherwise pop from the stars stack.
   c. If neither stack can provide a match, the string is invalid.
3. After traversal, attempt to match any remaining open parentheses with stars.
4. If all open parentheses are matched, the string is valid.

CODE:
*/

#include <stack>
#include <string>
using namespace std;

bool checkValidString(string s) {
    stack<int> openParentheses;
    stack<int> stars; // Store indices of stars for greedy matching
    
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            openParentheses.push(i);
        } else if (s[i] == '*') {
            stars.push(i);
        } else { // Closing parenthesis ')'
            if (!openParentheses.empty()) {
                openParentheses.pop();
            } else if (!stars.empty()) {
                stars.pop();
            } else {
                return false;
            }
        }
    }
    
    // Greedily match remaining stars to open parentheses
    while (!openParentheses.empty() && !stars.empty()) {
        if (openParentheses.top() < stars.top()) {
            openParentheses.pop();
            stars.pop();
        } else {
            break; // If no more valid matches can be made
        }
    }
    
    return openParentheses.empty(); // If all open parentheses are matched
}

/*
EXAMPLE USAGE:
int main() {
    string s = "(*))";
    bool result = checkValidString(s);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}

TIME COMPLEXITY:
- O(n) where n is the length of the string. We iterate through the string twice.

SPACE COMPLEXITY:
- O(n) for storing the indices of open parentheses and stars.
*/
