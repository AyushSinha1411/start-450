/*
QUESTION:
Write a function to convert a prefix expression to an infix expression.

Example:
Input: pre_exp = "*-A/BC-/AKL"
Output: "((A-(B/C))*((A/K)-L))"

APPROACH:
1. Use a stack to store intermediate results.
2. Read the prefix expression from right to left.
3. If the character is an operator, pop two operands from the stack, form a string by concatenating the operator and the two operands with parentheses, and push the result back to the stack.
4. If the character is an operand, push it to the stack as a string.
5. The final element in the stack will be the infix expression.

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
        case '^':
        case '%':
            return true;
    }
    return false;
}

// Function to convert prefix expression to infix expression
string preToInfix(string pre_exp) {
    stack<string> s;

    // Length of expression
    int length = pre_exp.size();

    // Reading from right to left
    for (int i = length - 1; i >= 0; i--) {
        // Check if symbol is operator
        if (isOperator(pre_exp[i])) {
            // Pop two operands from stack
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // Concat the operands and operator
            string temp = "(" + op1 + pre_exp[i] + op2 + ")";

            // Push string temp back to stack
            s.push(temp);
        } else {
            // If symbol is an operand, push the operand to the stack
            s.push(string(1, pre_exp[i]));
        }
    }

    // Stack now contains the infix expression
    return s.top();
}

/*
TIME COMPLEXITY: O(N), where N is the length of the prefix expression. This is because we iterate through the expression once and each stack operation (push/pop) is O(1).
SPACE COMPLEXITY: O(N), for the stack and the result string.
*/
