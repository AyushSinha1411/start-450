/*
QUESTION:
Given two strings s and goal, determine if s can become goal after some number of shifts. A shift is moving the leftmost character of s to the rightmost position. If s can become goal after some number of shifts, return true; otherwise, return false.

Example:
Input: s = "abcde", goal = "cdeab"
Output: true

Input: s = "abcde", goal = "abced"
Output: false

APPROACH:
1. Check if the lengths of s and goal are different. If so, return false as they cannot be rotations of each other.
2. If both strings are empty, return true.
3. Compute the shift table for the goal string using the Knuth-Morris-Pratt (KMP) pattern matching algorithm.
4. Attempt to find the goal string as a substring in the concatenated string s + s.
5. If a match is found, return true; otherwise, return false.

CODE:
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool rotateString(string s, string goal) {
    int N = s.length();
    
    // Check if the lengths of s and goal are different
    if (N != goal.length()) return false;
    
    // If both strings are empty, return true
    if (N == 0) return true;

    // Compute shift table using KMP algorithm
    vector<int> shifts(N + 1, 1);
    int left = -1;
    
    // Populate the shift table
    for (int right = 0; right < N; ++right) {
        // Adjust left position if characters do not match
        while (left >= 0 && goal[left] != goal[right]) {
            left -= shifts[left];
        }
        shifts[right + 1] = right - left++;
    }

    // Find match of goal in s + s
    int matchLen = 0;
    // Iterate over characters in the concatenated string s + s
    for (char c : (s + s)) {
        // Adjust matchLen if characters do not match
        while (matchLen >= 0 && goal[matchLen] != c) {
            matchLen -= shifts[matchLen];
        }
        // Increment matchLen and check if it equals the length of goal
        if (++matchLen == N) return true;
    }

    // If no match is found, return false
    return false;
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the strings s and goal. The KMP algorithm ensures that each character is processed a constant number of times.
SPACE COMPLEXITY: O(n), where 'n' is the length of the string goal. The shift table uses linear space relative to the input size.
*/
