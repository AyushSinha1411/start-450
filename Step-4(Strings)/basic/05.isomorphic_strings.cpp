/*
QUESTION:
Given two strings s and t, determine if they are isomorphic. Two strings are isomorphic if the characters in s can be replaced to get t. All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example:
Input: s = "egg", t = "add"
Output: true

Input: s = "foo", t = "bar"
Output: false

APPROACH:
1. Use two arrays to keep track of the mappings between characters in s and t.
2. Initialize the arrays to store the mappings for characters in s to t and t to s.
3. Iterate through each character in the strings s and t simultaneously.
4. For each character pair, check if the mapping exists in both arrays:
   a. If no mapping exists, create the mapping in both arrays.
   b. If a mapping exists, ensure it is consistent in both arrays.
   c. If the mapping is inconsistent, return false.
5. If all character pairs are checked and the mappings are consistent, return true.

CODE:
*/

#include <string>
using namespace std;

bool isIsomorphic(string s, string t) {
    int mappingDictStoT[256] = {0};
    int mappingDictTtoS[256] = {0};

    // Iterate through each character in the strings s and t
    for (int i = 0; i < s.length(); ++i) {
        char c1 = s[i];
        char c2 = t[i];

        // Case 1: No mapping exists in either of the dictionaries
        if (mappingDictStoT[c1] == 0 && mappingDictTtoS[c2] == 0) {
            // Create the mapping in both dictionaries
            mappingDictStoT[c1] = c2;
            mappingDictTtoS[c2] = c1;
        }
        // Case 2: Either mapping doesn't exist in one of the dictionaries
        // or Mapping exists and it doesn't match in either of the dictionaries
        else if (!(mappingDictStoT[c1] == c2 && mappingDictTtoS[c2] == c1)) {
            return false;
        }
    }

    // All mappings are consistent
    return true;
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the strings s and t. Each character is processed exactly once.
SPACE COMPLEXITY: O(1), as the space used by the mapping arrays is constant and does not depend on the input size.
*/
