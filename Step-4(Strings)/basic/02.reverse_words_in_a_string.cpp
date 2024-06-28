/*
QUESTION:
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example:
Input: "the sky is blue"
Output: "blue is sky the"

APPROACH:
1. Reverse the entire string to bring the words in the correct position but with reversed characters.
2. Iterate through the string to reverse each word to correct their character order.
3. Use two pointers, 'left' and 'right', to track the start and end of each word.
4. Skip leading spaces and reverse each word in place.
5. Append a single space after each word to maintain proper spacing.
6. Resize the string to remove the trailing space.
7. Return the modified string.

CODE:
*/

#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    // Reverse the entire string
    reverse(s.begin(), s.end());
    int n = s.size();
    int left = 0, right = 0, i = 0;

    while (i < n) {
        // Skip leading spaces
        while (i < n && s[i] == ' ') i++;
        if (i == n) break; // Stop if end of string is reached
        
        // Mark the start of a word
        if (left != 0) s[right++] = ' '; // Add a space before the next word
        
        int start = right; // Start index for the word
        while (i < n && s[i] != ' ') {
            s[right++] = s[i++];
        }
        
        // Reverse the characters of the current word
        reverse(s.begin() + start, s.begin() + right);
    }
    
    s.resize(right); // Resize to remove trailing spaces if any
    return s; // Return the modified string
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the input string. Each character is processed a constant number of times.
SPACE COMPLEXITY: O(1), since the operations are performed in-place.
*/
