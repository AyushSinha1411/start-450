/*
QUESTION:
Write a function to find the number of substrings containing at least one occurrence of all characters 'a', 'b', and 'c' in the given string s.

Example:
Input: s = "abcabc"
Output: 10
Explanation:
The substrings containing all characters 'a', 'b', and 'c' are:
"abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc", "abc"

APPROACH:
1. Use the sliding window technique to maintain a window containing at least one occurrence of 'a', 'b', and 'c'.
2. Initialize two pointers, i and j, to define the window.
3. Iterate through the string with the j pointer.
4. Add the current character to the frequency map.
5. If the window contains at least one 'a', 'b', and 'c', count all valid substrings ending at j.
6. Shrink the window from the left by incrementing the i pointer until the window no longer contains all three characters.
7. Add the count of valid substrings to the result.
8. Return the total count of valid substrings.

CODE:
*/

#include <unordered_map>
#include <string>
using namespace std;

// Function to find the number of substrings containing at least one occurrence of 'a', 'b', and 'c'
int numberOfSubstrings(string s) {
    int n = s.size();
    int i = 0, j = 0, count = 0;
    unordered_map<char, int> mp;

    while (j < n) {
        mp[s[j]]++;

        // If the window contains at least one 'a', 'b', and 'c'
        while (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1) {
            count += (n - j);

            // Shrink the window from the left
            mp[s[i]]--;
            i++;
        }
        j++;
    }

    return count;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the string. This is because each character is visited at most twice (once by the j pointer and once by the i pointer).
SPACE COMPLEXITY: O(1), since the map can hold at most three characters ('a', 'b', and 'c').
*/
