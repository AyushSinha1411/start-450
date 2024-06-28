/*
QUESTION:
Given a string num that contains only digits and an integer target, return all possible combinations of num that add up to the target value by inserting the operators '+', '-', and '*' between the digits.

Example:
Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"]
Explanation: Both expressions 1+2+3 and 1*2*3 add up to 6.

APPROACH:
1. Use depth-first search (DFS) to explore all possible combinations of inserting operators.
2. For each substring of num, consider it as an operand and recursively explore all operator insertions.
3. Skip invalid operands that start with '0' (except for the single digit '0').
4. Maintain the current value of the expression and the path of the expression formed so far.
5. Add the expression to the result if it evaluates to the target value when the end of the string is reached.

CODE:
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to add operators between digits to achieve the target value
vector<string> addOperators(string num, int target) {
    vector<string> res;
    dfs(num, target, 0, 0, "", res);
    return res;
}

// Helper function for depth-first search
void dfs(string num, int target, int pos, long long cur, string path, vector<string>& res) {
    if (pos == num.size()) {
        if (cur == target) {
            res.push_back(path);
        }
        return;
    }

    for (int i = pos; i < num.size(); i++) {
        string operand = num.substr(pos, i - pos + 1);
        if (operand.size() > 1 && operand[0] == '0') {
            continue;
        }

        long long n = stoll(operand);
        if (pos == 0) {
            dfs(num, target, i + 1, n, operand, res);
        } else {
            dfs(num, target, i + 1, cur + n, path + "+" + operand, res);
            dfs(num, target, i + 1, cur - n, path + "-" + operand, res);
            dfs(num, target, i + 1, cur * n, path + "*" + operand, res);
        }
    }
}

/*
TIME COMPLEXITY: O(4^N), where N is the length of the string num. This is because there are three operators and a number split decision at each position.
SPACE COMPLEXITY: O(N), due to the recursion stack and storage of intermediate paths.
*/
