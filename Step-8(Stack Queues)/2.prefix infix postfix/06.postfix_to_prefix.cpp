/*
QUESTION:
Write a function to convert a postfix expression to a prefix expression.

Example:
Input: post_exp = "ABC/-AK/L-*"
Output: "*-A/BC-/AKL"

APPROACH:
1. Use a stack to store intermediate results.
2. Read the postfix expression from left to right.
3. If the character is an operator, pop two operands from the stack, form a string by concatenating the operator and the two operands, and push the result back to the stack.
4. If the character is an operand, push it to the stack as a string.
5. The final element in the stack will be the prefix expression.

CODE:
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if character is operator or not
bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}

// Function to convert postfix expression to prefix expression
string postToPre(string post_exp) {
    stack<string> s;

    // Length of expression
    int length = post_exp.size();

    // Reading from left to right
    for (int i = 0; i < length; i++) {
        // Check if symbol is operator
        if (isOperator(post_exp[i])) {
            // Pop two operands from stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            // Concat the operands and operator
            string temp = post_exp[i] + op2 + op1;

            // Push string temp back to stack
            s.push(temp);
        } else {
            // If symbol is an operand, push the operand to the stack
            s.push(string(1, post_exp[i]));
        }
    }

    // Stack now contains the prefix expression
    string ans = s.top();
    return ans;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the postfix expression. This is because we iterate through the expression once and each stack operation (push/pop) is O(1).
SPACE COMPLEXITY: O(N), for the stack and the result string.
*/
