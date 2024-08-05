/*
QUESTION:
Write a function to generate all combinations of well-formed parentheses. Given n pairs of parentheses, the function should return all combinations of n pairs.

Example:
Input: n = 3
Output: ["{{{}}}", "{{}{}}", "{{}}{}", "{}{{}}", "{}{}{}"]
Explanation: All combinations of well-formed parentheses with 3 pairs are generated.

APPROACH:
1. Use a recursive function to generate the combinations.
2. Track the count of left and right parentheses to be added.
3. If the number of left or right parentheses to be added becomes less than zero or if more right parentheses are added than left ones, return as it is an invalid state.
4. Add the combination to the result when no more parentheses are left to add.

CODE:
*/

#include <iostream>
#include <vector>
using namespace std;

void generateParenthesisHelper(int n, int open, int close, string current, vector<string>& result) {
    // Base case: if the current string length is 2 * n
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    // If the number of open parentheses is less than n, add an open parenthesis
    if (open < n) {
        generateParenthesisHelper(n, open + 1, close, current + "(", result);
    }

    // If the number of close parentheses is less than the number of open parentheses, add a close parenthesis
    if (close < open) {
        generateParenthesisHelper(n, open, close + 1, current + ")", result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesisHelper(n, 0, 0, "", result);
    return result;
}
/*
TIME COMPLEXITY: O(2^N), where N is the number of pairs of parentheses. This is because each position can either be an opening or closing parenthesis.
SPACE COMPLEXITY: O(N), due to the recursion stack for processing each character in the string.
*/
