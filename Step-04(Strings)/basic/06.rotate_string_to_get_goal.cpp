/*
Question:
Given two strings `s` and `goal`, determine if `s` can become `goal` after some number of shifts. A shift is moving the leftmost character of `s` to the rightmost position. If `s` can become `goal` after some number of shifts, return true; otherwise, return false.

Example:
Input: s = "abcde", goal = "cdeab"
Output: true
Explanation: After shifting "abcde" 2 times, it becomes "cdeab".

Approach:
1. Check if the lengths of `s` and `goal` are the same. If not, return false.
2. Concatenate `s` with itself to create a new string `double_s`.
3. Check if `goal` is a substring of `double_s`.
4. If `goal` is a substring of `double_s`, return true; otherwise, return false.
*/
bool canBecomeGoal(string s, string goal) {
    // Check if the lengths of s and goal are the same
    if (s.length() != goal.length()) {
        return false;
    }

    // Concatenate s with itself
    string double_s = s + s;

    // Check if goal is a substring of double_s
    if (double_s.find(goal) != string::npos) {
        return true;
    }

    // If goal is not found, return false
    return false;
}
/*
Time Complexity: O(n), where n is the length of the string `s`.
Space Complexity: O(n), for storing the concatenated string.
*/
