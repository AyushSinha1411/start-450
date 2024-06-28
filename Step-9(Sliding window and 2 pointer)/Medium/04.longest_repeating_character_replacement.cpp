/*
QUESTION:
Write a function to find the length of the longest substring that can be obtained by replacing at most k characters in the given string s such that all characters in the substring are the same.

Example:
Input: s = "AABABBA", k = 1
Output: 4
Explanation:
Replace the one 'A' in the middle to get "AAAA" or replace the one 'B' in the middle to get "BBBB".

APPROACH:
1. Use the sliding window technique to maintain a window where we can replace at most k characters.
2. Use a vector to keep track of the frequency of each character in the current window.
3. Initialize two pointers, start and end, to define the window.
4. Iterate through the string with the end pointer.
5. Update the frequency of the current character and the maximum frequency seen so far.
6. If the window size minus the maximum frequency exceeds k, the window is invalid, so move the start pointer to the right.
7. Update the maximum length of the window during the iteration.
8. Return the length of the longest valid window.

CODE:
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the length of the longest substring with at most k replacements
int characterReplacement(string s, int k) {
    int start = 0;
    vector<int> frequencyMap(26, 0);
    int maxFrequency = 0;
    int longestSubstringLength = 0;

    for (int end = 0; end < s.length(); end++) {
        // Calculate the offset of the current character entering the window
        int currentChar = s[end] - 'A';

        // Update the frequency of the current character
        frequencyMap[currentChar]++;

        // Update the maximum frequency seen so far
        maxFrequency = max(maxFrequency, frequencyMap[currentChar]);

        // Move the start pointer towards the right if the current window is invalid
        bool isValid = (end + 1 - start - maxFrequency <= k);
        if (!isValid) {
            // Offset of the character moving out of the window
            int outgoingChar = s[start] - 'A';

            // Decrease its frequency
            frequencyMap[outgoingChar]--;

            // Move the start pointer forward
            start++;
        }

        // The window is valid at this point, note down the length
        longestSubstringLength = max(longestSubstringLength, end + 1 - start);
    }

    return longestSubstringLength;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the string. This is because each character is visited at most twice (once by the end pointer and once by the start pointer).
SPACE COMPLEXITY: O(1), since the frequencyMap has a fixed size of 26.
*/
