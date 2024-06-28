/*
QUESTION:
Given a string, generate all possible subsets (combinations of characters) of the string.

Example:
Input: s = "abc"
Output: "abc", "ab", "ac", "a", "bc", "b", "c", ""
Explanation: All possible subsets of the string "abc" are generated.

APPROACH:
1. Use a recursive function to generate subsets.
2. At each step, decide whether to include the current character in the subset.
3. Use backtracking to explore both possibilities (including or excluding the current character).
4. Print each subset when the end of the string is reached.

CODE:
*/

#include <iostream>
#include <string>
using namespace std;

// Recursive function to generate all subsets of a string
void solve(int i, string s, string &f) {
    // Base case: if the end of the string is reached
    if (i == s.length()) {
        cout << f << " ";
        return;
    }

    // Include the current character in the subset
    f = f + s[i];
    solve(i + 1, s, f);

    // Backtrack and remove the current character from the subset
    f.pop_back();
    solve(i + 1, s, f);
}

/*
TIME COMPLEXITY: O(2^N), where N is the length of the string. This is because there are 2^N subsets of a string of length N.
SPACE COMPLEXITY: O(N), due to the recursion stack for processing each character in the string.
*/
