/*
QUESTION:
Write a function to convert an infix expression to a prefix expression.

Example:
Input: infix = "(A-B/C)*(A/K-L)"
Output: "*-A/BC-/AKL"

APPROACH:
1. Reverse the infix expression.
2. Replace '(' with ')' and vice versa.
3. Get the postfix expression of the modified infix expression.
4. Reverse the postfix expression to get the prefix expression.

CODE:
*/

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Function to check if character is an operator
bool isOperator(char c) {
    return (!isalpha(c) && !isdigit(c));
}

// Function to get the priority of operators
int getPriority(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) {
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> char_stack;
    string output;

    for (int i = 0; i < l; i++) {
        // If the scanned character is an operand, add it to output.
        if (isalpha(infix[i]) || isdigit(infix[i]))
            output += infix[i];
        // If the scanned character is ‘(‘, push it to the stack.
        else if (infix[i] == '(')
            char_stack.push('(');
        // If the scanned character is ‘)’, pop and output from the stack until an ‘(‘ is encountered.
        else if (infix[i] == ')') {
            while (char_stack.top() != '(') {
                output += char_stack.top();
                char_stack.pop();
            }
            // Remove '(' from the stack
            char_stack.pop();
        }
        // Operator found
        else {
            if (isOperator(char_stack.top())) {
                if (infix[i] == '^') {
                    while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                } else {
                    while (getPriority(infix[i]) < getPriority(char_stack.top())) {
                        output += char_stack.top();
                        char_stack.pop();
                    }
                }
                // Push current Operator on stack
                char_stack.push(infix[i]);
            }
        }
    }
    while (!char_stack.empty()) {
        output += char_stack.top();
        char_stack.pop();
    }
    return output;
}

// Function to convert infix expression to prefix expression
string infixToPrefix(string infix) {
    // Reverse String and replace ( with ) and vice versa
    // Get Postfix
    // Reverse Postfix
    int l = infix.size();

    // Reverse infix
    reverse(infix.begin(), infix.end());

    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    string prefix = infixToPostfix(infix);

    // Reverse postfix to get prefix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the infix expression. This is because we iterate through the expression multiple times and each stack operation (push/pop) is O(1).
SPACE COMPLEXITY: O(N), for the stack and the result strings.
*/
