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

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<string> combinations;
    unordered_map<char, string> letters = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    string phoneDigits;

public:
    // Function to return all possible letter combinations that the number could represent
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return combinations;
        }
        phoneDigits = digits;
        backtrack(0, "");
        return combinations;
    }

private:
    // Backtracking function to generate all letter combinations
    void backtrack(int index, string path) {
        // If the current path length matches the length of phoneDigits, add to combinations
        if (path.length() == phoneDigits.length()) {
            combinations.push_back(path);
            return;
        }
        // Get the letters corresponding to the current digit
        string possibleLetters = letters[phoneDigits[index]];
        for (char letter : possibleLetters) {
            // Append the letter and recurse to the next digit
            path.push_back(letter);
            backtrack(index + 1, path);
            // Backtrack and remove the last letter
            path.pop_back();
        }
    }
};

/*
TIME COMPLEXITY: O(4^N), where N is the length of the input digits. This is because each digit can map to up to 4 letters.
SPACE COMPLEXITY: O(N), due to the recursion stack for processing each digit.
*/
