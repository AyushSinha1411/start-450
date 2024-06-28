/*
QUESTION:
Write a function to find the length of the longest substring that contains at most k distinct characters in the given string s.

Example:
Input: s = "eceba", k = 2
Output: 3
Explanation: The longest substring with at most 2 distinct characters is "ece" with a length of 3.

APPROACH:
1. Use a sliding window technique to maintain a window with at most k distinct characters.
2. Initialize two pointers, left and right, to define the window.
3. Use a map to keep track of the frequency of each character in the current window.
4. Iterate through the string with the right pointer.
5. Add the current character to the frequency map.
6. If the size of the map exceeds k, move the left pointer to the right until the size of the map is at most k.
7. Update the maximum length of the window during the iteration.
8. Return the length of the longest valid window.

CODE:
*/

#include <string>
#include <unordered_map>
using namespace std;

// Function to find the length of the longest substring with at most k distinct characters
int lengthOfLongestSubstringKDistinct(string s, int k) {
    int n = s.length();
    int maxSize = 0;
    unordered_map<char, int> counter;

    for (int right = 0; right < n; right++) {
        counter[s[right]]++;

        // While the number of distinct characters exceeds k, move the left pointer
        while (counter.size() > k) {
            char leftChar = s[right - maxSize];
            counter[leftChar]--;
            if (counter[leftChar] == 0) {
                counter.erase(leftChar);
            }
            maxSize++;
        }

        // Update the maximum size of the window
        maxSize = max(maxSize, right - maxSize + 1);
    }

    return maxSize;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the string. This is because each character is visited at most twice (once by the right pointer and once by the left pointer).
SPACE COMPLEXITY: O(K), since the map can hold at most k characters.
*/
