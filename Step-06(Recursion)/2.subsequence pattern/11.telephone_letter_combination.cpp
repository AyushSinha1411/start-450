/*
QUESTION:
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. The mapping of digits to letters is the same as on a telephone button.

Example:
Input: digits = "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
Explanation: The digit '2' maps to "abc", and the digit '3' maps to "def". All possible combinations are generated.

APPROACH:
1. Use a backtracking function to explore all possible combinations.
2. At each step, append a letter corresponding to the current digit and recurse to the next digit.
3. Add valid combinations to the result when the path length matches the length of the input digits.

CODE:
*/

// Map digits to their corresponding letters
    vector<string> digitToLetters = {"",    "",    "abc",  "def", "ghi",
                                     "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // Recursive function to generate combinations
    void findCombinations(int ind, string &digits, string &current, vector<string> &ans) {
        if (ind == digits.size()) {
            ans.push_back(current);
            return;
        }
        
        string letters = digitToLetters[digits[ind] - '0'];
        for (char letter : letters) {
            current.push_back(letter);
            findCombinations(ind + 1, digits, current, ans);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> ans;
        string current;
        findCombinations(0, digits, current, ans);
        return ans;
    }

/*
TIME COMPLEXITY: O(4^N), where N is the length of the input digits. This is because each digit can map to up to 4 letters.
SPACE COMPLEXITY: O(N), due to the recursion stack for processing each digit.
*/
