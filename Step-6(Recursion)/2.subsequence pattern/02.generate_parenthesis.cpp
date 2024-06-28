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

// Function to generate all combinations of well-formed parentheses
void generateParenthesis(int left, int right, string& s, vector<string>& answer) {
    // Base case: if no more parentheses to add
    if (left == 0 && right == 0) {
        answer.push_back(s);
        return;
    }

    // If the state is invalid
    if (left > right || left < 0 || right < 0) {
        return;
    }

    // Add a left parenthesis and recurse
    s.push_back('{');
    generateParenthesis(left - 1, right, s, answer);
    s.pop_back();

    // Add a right parenthesis and recurse
    s.push_back('}');
    generateParenthesis(left, right - 1, s, answer);
    s.pop_back();
}

/*
TIME COMPLEXITY: O(2^N), where N is the number of pairs of parentheses. This is because each position can either be an opening or closing parenthesis.
SPACE COMPLEXITY: O(N), due to the recursion stack for processing each character in the string.
*/
