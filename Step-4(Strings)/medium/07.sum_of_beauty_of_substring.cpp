/*
QUESTION:
Given a string s, calculate the sum of the beauty of all its substrings. The beauty of a string is defined as the difference between the frequency of the most frequent and least frequent characters in the string.

Example:
Input: "aabcb"
Output: 5

APPROACH:
1. Iterate over all possible starting points of substrings.
2. For each starting point, maintain a frequency array to count the occurrences of each character.
3. For each ending point of substrings starting at the current starting point, update the frequency array.
4. Calculate the beauty of the current substring as the difference between the maximum and minimum frequencies of characters that appear in the substring.
5. Accumulate the beauty of all substrings and return the total beauty.

CODE:
*/

#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int beautySum(string s) {
    int n = s.size();
    int totalBeauty = 0;
    
    // Iterate over all starting points of substrings
    for (int i = 0; i < n; ++i) {
        vector<int> freq(26, 0); // Frequency array for characters 'a' to 'z'
        // Iterate over all ending points of substrings starting at i
        for (int j = i; j < n; ++j) {
            freq[s[j] - 'a']++; // Update frequency of the current character
            
            int maxFreq = INT_MIN, minFreq = INT_MAX;
            // Calculate max and min frequencies in the current substring
            for (int k = 0; k < 26; ++k) {
                if (freq[k] > 0) {
                    maxFreq = max(maxFreq, freq[k]);
                    minFreq = min(minFreq, freq[k]);
                }
            }
            // Add the beauty of the current substring to the total beauty
            totalBeauty += (maxFreq - minFreq);
        }
    }
    return totalBeauty; // Return the total beauty of all substrings
}

/*
TIME COMPLEXITY: O(n^3), where 'n' is the length of the input string. We have nested loops for the starting and ending points of substrings, and an inner loop to calculate max and min frequencies.
SPACE COMPLEXITY: O(1), as the frequency array size is constant (26 for lowercase English letters).
*/
