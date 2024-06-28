/*
QUESTION:
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
- countAndSay(1) = "1"
- countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a new digit string.
Given an integer n, generate the nth term of the count-and-say sequence.

Example:
Input: 4
Output: "1211"

Explanation:
- countAndSay(1) = "1"
- countAndSay(2) = "11" (one 1)
- countAndSay(3) = "21" (two 1s)
- countAndSay(4) = "1211" (one 2 followed by one 1)

APPROACH:
1. Initialize the current string as "1".
2. For each sequence number from 2 to n:
   a. Initialize an empty string for the next sequence.
   b. Iterate through the characters of the current string, counting consecutive digits.
   c. Append the count and the digit to the next sequence string.
   d. Update the current string to the next sequence string.
3. Return the resulting string after n iterations.

CODE:
*/

#include <string>
using namespace std;

string countAndSay(int n) {
    string currentString = "1";  // Initialize the first sequence as "1"
    
    // Generate sequences from 2 to n
    for (int i = 2; i <= n; i++) {
        string nextString;  // Initialize the next sequence string
        // Iterate through the current sequence string
        for (int j = 0, k = 0; j < currentString.size(); j = k) {
            // Count consecutive digits
            while (k < currentString.size() && currentString[k] == currentString[j]) {
                k++;
            }
            // Append the count and the digit to the next sequence string
            nextString += to_string(k - j) + currentString[j];
        }
        // Update the current string to the next sequence string
        currentString = nextString;
    }
    
    return currentString;  // Return the nth sequence
}

/*
TIME COMPLEXITY: O(m * n), where 'n' is the given integer and 'm' is the maximum length of the sequence generated. The length of the sequence roughly doubles with each step.
SPACE COMPLEXITY: O(m), where 'm' is the maximum length of the sequence generated. This space is used for the current and next sequence strings.
*/
