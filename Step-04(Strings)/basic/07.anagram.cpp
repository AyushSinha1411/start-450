/*
QUESTION:
Given two strings s and t, determine if t is an anagram of s. An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

Example:
Input: s = "anagram", t = "nagaram"
Output: true

Input: s = "rat", t = "car"
Output: false

APPROACH:
1. Check if the lengths of s and t are different. If so, return false as they cannot be anagrams.
2. Use an unordered_map to track the frequency of each character in s.
3. Increment the count for each character in s.
4. Decrement the count for each character in t.
5. If the count of any character becomes negative, return false as it indicates an imbalance.
6. If all characters are balanced, return true.

CODE:
*/

#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    // Check if the lengths of s and t are different
    if (s.length() != t.length()) {
        return false;
    }

    // Use unordered_map for character frequency tracking
    unordered_map<char, int> charCount;

    // Increment count for each character in s
    for (char c : s) {
        charCount[c]++;
    }

    // Decrement count for each character in t
    for (char c : t) {
        charCount[c]--;
        // If count becomes negative, not an anagram
        if (charCount[c] < 0) {
            return false;
        }
    }

    // All characters balanced, strings are anagrams
    return true;
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the strings s and t. Each character is processed a constant number of times.
SPACE COMPLEXITY: O(1), as the unordered_map will use a constant amount of extra space proportional to the number of unique characters (at most 26 for lowercase English letters).
*/
