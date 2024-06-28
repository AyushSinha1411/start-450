/*
QUESTION:
Given a string s and an integer k, count the number of substrings with exactly k distinct characters. The function substrCount should return this count.

Example:
Input: s = "pqpqs", k = 2
Output: 7

APPROACH:
1. Use a helper function atMostK to count the number of substrings with at most k distinct characters.
2. Calculate the number of substrings with exactly k distinct characters by subtracting the count of substrings with at most k-1 distinct characters from the count of substrings with at most k distinct characters.

CODE:
*/

// Function to count substrings with at most k distinct characters
#include <bits/stdc++.h>
using namespace std;
long long int atMostK(string s, int k) {
    if (k < 0) return 0;

    int i = 0, j = 0, cnt = 0;
    long long int res = 0;
    int m[26] = {0};  // Frequency array for characters 'a' to 'z'

    // Sliding window approach to count substrings with at most k distinct characters
    while (j < s.length()) {
        m[s[j] - 'a']++;
        if (m[s[j] - 'a'] == 1) cnt++;  // New distinct character found

        // If there are more than k distinct characters, shrink the window from the left
        while (cnt > k) {
            m[s[i] - 'a']--;
            if (m[s[i] - 'a'] == 0) cnt--;  // A distinct character is removed
            i++;
        }

        // All substrings ending at j and starting from i to j are valid
        res += (j - i + 1);
        j++;
    }
    return res;
}

// Function to count substrings with exactly k distinct characters
long long int substrCount(string s, int k) {
    return atMostK(s, k) - atMostK(s, k - 1);
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the string. The sliding window ensures each character is processed at most twice.
SPACE COMPLEXITY: O(1), as the frequency array has a fixed size of 26.
*/
