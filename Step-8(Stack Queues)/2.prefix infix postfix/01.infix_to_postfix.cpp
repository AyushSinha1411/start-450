/*
QUESTION:
Write a function to convert an infix expression to a postfix expression.

Example:
Input: s = "a+b*(c^d-e)^(f+g*h)-i"
Output: "abcd^e-fgh*+^*+i-"

APPROACH:
1. Use a stack to keep track of operators and parentheses.
2. Iterate through each character in the infix expression.
3. If the character is an operand, add it to the result string.
4. If the character is an '(', push it onto the stack.
5. If the character is a ')', pop from the stack to the result string until '(' is encountered.
6. If the character is an operator, pop from the stack to the result string while the precedence of the operator at the top of the stack is greater than or equal to the current operator.
7. Push the current operator onto the stack.
8. After iterating through the infix expression, pop all remaining elements from the stack to the result string.

CODE:
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(string s) {
    stack<char> st; // For stack operations, we are using C++ built-in stack
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the scanned character is an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an '(', push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ')', pop and to output string from the stack until an '(' is encountered.
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    cout << "Postfix expression: " << result << endl;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the string. This is because we iterate through the string once and each stack operation (push/pop) is O(1).
SPACE COMPLEXITY: O(N), for the stack and the result string.
*/
