/*
Question:
Given a string, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order. Additionally, remove any leading, trailing, or extra spaces between words.

Example:
Input: "  The quick brown fox  "
Output: "ehT kciuq nworb xof"

Approach:
1. Trim leading and trailing spaces.
2. Use two pointers to identify the start and end of each word.
3. Reverse the characters in each word in place.
4. Reduce multiple spaces between words to a single space.
5. Return the modified string.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverseWord(string &s, int start, int end) {
    // Reverse the characters in the word from start to end
    while (start < end) {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

string reverseWords(string s) {
    int n = s.length();
    int start = 0;

    // Trim leading and trailing spaces
    while (start < n && s[start] == ' ') start++;
    int end = n - 1;
    while (end >= 0 && s[end] == ' ') end--;

    if (start > end) return ""; // If the entire string is spaces

    // Reverse the characters in each word
    int wordStart = start;
    for (int i = start; i <= end; i++) {
        if (s[i] == ' ' || i == end) {
            int wordEnd = (s[i] == ' ') ? i - 1 : i;
            reverseWord(s, wordStart, wordEnd);
            wordStart = i + 1;
        }
    }

    // Reduce multiple spaces between words to a single space
    string result;
    bool inSpace = false;
    for (int i = start; i <= end; i++) {
        if (s[i] == ' ') {
            if (!inSpace) {
                result += ' ';
                inSpace = true;
            }
        } else {
            result += s[i];
            inSpace = false;
        }
    }

    return result; // Return the final reversed string
}
/*Time Complexity: O(n), where n is the length of the input string.
Space Complexity: O(1), as we are reversing the words in place without using extra space.
*/
