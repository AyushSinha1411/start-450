/*
QUESTION:
Write a function to determine if a given string of parentheses is valid. A string of parentheses is valid if all types of parentheses are closed and opened in the correct order.

Example:
Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false

APPROACH:
1. Use a stack to keep track of opening parentheses.
2. Iterate through each character in the string.
3. If the character is an opening parenthesis, push it onto the stack.
4. If the character is a closing parenthesis, check if it matches the top of the stack.
5. If it matches, pop the top of the stack; otherwise, return false.
6. After iterating through the string, check if the stack is empty.

CODE:
*/

#include <iostream>
#include <stack>
using namespace std;

// Function to determine if a given string of parentheses is valid
bool isValid(string s) {
    stack<char> st;
    for (auto it : s) {
        if (it == '(' || it == '{' || it == '[') {
            st.push(it);
        } else {
            if (st.size() == 0) return false;
            char ch = st.top();
            st.pop();
            if ((it == ')' && ch == '(') || (it == ']' && ch == '[') || (it == '}' && ch == '{')) {
                continue;
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

/*
TIME COMPLEXITY: O(N), where N is the length of the string. This is because we iterate through the string once.
SPACE COMPLEXITY: O(N), where N is the length of the string. This is the space used by the stack in the worst case.
*/