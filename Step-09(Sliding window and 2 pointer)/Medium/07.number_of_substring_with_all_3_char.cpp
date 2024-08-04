// Question: Given a string s consisting only of characters 'a', 'b', and 'c', return the number of substrings containing all three characters 'a', 'b', and 'c'.
// Example:
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing all three characters are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc", and "abc".
// Approach:
// We use a sliding window technique and a hashmap to keep track of the last seen positions of 'a', 'b', and 'c'.
// As we iterate through the string, we update the last seen positions and calculate the number of valid substrings ending at the current position.
// Time Complexity: O(n), where n is the length of the string. Each character is visited once.
// Space Complexity: O(1), since the size of the hashmap is fixed.

#include <string>
#include <algorithm>
using namespace std;

int numberOfSubstrings(string s) {
    int n = s.size();  // Length of the input string
    int count = 0;     // Count of substrings containing all three characters
    int lastSeen[3] = {-1, -1, -1}; // Last seen positions of 'a', 'b', and 'c'

    // Iterate over the string
    for (int i = 0; i < n; ++i) {
        // Update the last seen position of the current character
        lastSeen[s[i] - 'a'] = i;

        // Check if all three characters have been seen
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            // Calculate the number of valid substrings ending at the current position
            count += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
        }
    }

    return count; // Return the count of substrings containing all three characters
}
