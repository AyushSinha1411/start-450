/*
QUESTION:
Given two strings, determine which string has more unique subsequences. Return the string with the greater number of unique subsequences. If both have the same number, return the first string.

Example:
Input: str1 = "abc", str2 = "abcd"
Output: "abcd"
Explanation: The string "abc" has 8 unique subsequences, while "abcd" has 16 unique subsequences. Hence, "abcd" is returned.

APPROACH:
1. Use a recursive function to generate all subsequences of a string and store them in an unordered_set to ensure uniqueness.
2. Compare the sizes of the sets of unique subsequences for both strings.
3. Return the string with the greater number of unique subsequences.

CODE:
*/

#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<string> sn;

// Recursive function to generate all unique subsequences of a string
void subsequences(string& s, char op[], int i, int j) {
    // Base case: if the end of the string is reached
    if (s[i] == '\0') {
        op[j] = '\0';
        // Insert each generated subsequence into the set
        sn.insert(op);
        return;
    }

    // Include the current character in the subsequence
    op[j] = s[i];
    subsequences(s, op, i + 1, j + 1);

    // Exclude the current character from the subsequence
    subsequences(s, op, i + 1, j);
}

// Function to determine which string has more unique subsequences
string betterString(string str1, string str2) {
    int m = str1.size();
    char op[m + 1];
    subsequences(str1, op, 0, 0);

    int a = sn.size();
    sn.clear();

    m = str2.size();
    char op1[m + 1];
    subsequences(str2, op1, 0, 0);

    int b = sn.size();

    if (b > a) {
        return str2;
    }

    return str1;
}

/*
TIME COMPLEXITY: O(2^N), where N is the length of the string. This is because there are 2^N possible subsequences for a string of length N.
SPACE COMPLEXITY: O(2^N), due to the storage of unique subsequences in the set and the recursion stack.
*/
