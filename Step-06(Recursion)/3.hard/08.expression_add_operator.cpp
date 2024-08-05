/*
 * Question:
 * Given a string `num` that contains only digits and an integer `target`, return all possibilities to add binary operators (not unary) +, -, or *
 * between the digits so they evaluate to the target value.
 *
 * Approach:
 * 1. Use a recursive function to explore all possible ways to insert operators between the digits.
 * 2. Use a helper function to perform the recursion, passing along the current expression, current value, previous value, and position.
 * 3. Base case: If the position reaches the end of the string, check if the current value matches the target.
 * 4. Recursive case: For each position, try adding each operator and recurse.
 */

void helper(string &num, int target, int pos, long currVal, long prevVal, string expr, vector<string> &result) {
    // Base case: if the position reaches the end of the string
    if (pos == num.size()) {
        // Check if the current value equals the target value
        if (currVal == target) {
            result.push_back(expr);
        }
        return;
    }

    // Recursive case: try each possible next operand
    for (int i = pos; i < num.size(); ++i) {
        // Avoid numbers with leading zero
        if (i != pos && num[pos] == '0') break;
        
        // Parse the current number
        string currStr = num.substr(pos, i - pos + 1);
        long currNum = stol(currStr);
        
        // If at the beginning of the expression, just recurse without any operator
        if (pos == 0) {
            helper(num, target, i + 1, currNum, currNum, currStr, result);
        } else {
            // Try addition
            helper(num, target, i + 1, currVal + currNum, currNum, expr + "+" + currStr, result);
            // Try subtraction
            helper(num, target, i + 1, currVal - currNum, -currNum, expr + "-" + currStr, result);
            // Try multiplication
            helper(num, target, i + 1, currVal - prevVal + prevVal * currNum, prevVal * currNum, expr + "*" + currStr, result);
        }
    }
}

// Function to find all expressions that add up to the target
vector<string> addOperators(string num, int target) {
    vector<string> result;
    helper(num, target, 0, 0, 0, "", result);
    return result;
}

/*
 * Time Complexity:
 * The time complexity is O(4^n), where n is the length of the input string `num`. This is because each position can potentially lead to four recursive calls (+, -, *, and the next digit).
 *
 * Space Complexity:
 * The space complexity is O(n), where n is the length of the input string `num`, due to the recursion stack.
 */
