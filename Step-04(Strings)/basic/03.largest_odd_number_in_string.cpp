/*
QUESTION:
Given a string num representing a large integer, return the largest-valued odd integer (as a string) that is a non-empty prefix of num. If no such odd integer exists, return an empty string.

Example:
Input: "35427"
Output: "35427"

APPROACH:
1. Iterate through the string num from the end to the beginning.
2. Check each digit to see if it is odd.
3. If an odd digit is found, return the substring from the start of the string to the current index.
4. If no odd digit is found, return an empty string.

CODE:
*/

#include <string>
using namespace std;

string largestOddNumber(string num) {
    // Iterate from the end of the string to the beginning
    for (int i = num.size() - 1; i >= 0; i--) {
        // Check if the current digit is odd
        if ((num[i] - '0') % 2 != 0) {
            // Return the substring from the start to the current index (inclusive)
            return num.substr(0, i + 1);
        }
    }
    // If no odd digit is found, return an empty string
    return "";
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the input string. Each character is checked exactly once.
SPACE COMPLEXITY: O(1), as no additional space proportional to the input size is used.
*/
