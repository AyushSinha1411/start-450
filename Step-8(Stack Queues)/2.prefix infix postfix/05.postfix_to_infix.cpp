/*
QUESTION:
Write a function to convert a postfix expression to an infix expression.

Example:
Input: exp = "abc*+"
Output: "a+(b*c)"

APPROACH:
1. Use a stack to store intermediate results.
2. Iterate through each character in the postfix expression.
3. If the character is an operand, push it to the stack as a string.
4. If the character is an operator, pop two operands from the stack, form a string by concatenating them with the operator and parentheses, and push the result back to the stack.
5. The final element in the stack will be the infix expression.

CODE:
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if character is operand or not
bool isOperand(char x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

// Function to convert postfix expression to infix expression
string getInfix(string exp) {
    stack<string> s;

    for (int i = 0; exp[i] != '\0'; i++) {
        // Push operands
        if (isOperand(exp[i])) {
            string op(1, exp[i]);
            s.push(op);
        } else {
            // Pop two operands from stack
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            // Concat the operands and operator with parentheses
            s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }

    // The final element in the stack is the required infix expression
    return s.top();
}

/*
TIME COMPLEXITY: O(N), where N is the length of the postfix expression. This is because we iterate through the expression once and each stack operation (push/pop) is O(1).
SPACE COMPLEXITY: O(N), for the stack and the result string.
*/
