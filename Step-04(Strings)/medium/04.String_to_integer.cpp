/*
QUESTION:
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to the C/C++ function atoi). The function discards leading whitespace characters, then takes an optional initial '+' or '-' sign followed by numerical digits, and interprets these characters as a numerical value. The function stops reading the input string when it encounters a non-digit character or reaches the end of the string. If the numerical value is out of the 32-bit signed integer range, return INT_MAX (2^31 - 1) or INT_MIN (-2^31).

Example:
Input: "42"
Output: 42

Input: "   -42"
Output: -42

Input: "4193 with words"
Output: 4193

Input: "words and 987"
Output: 0

APPROACH:
1. Discard all leading whitespace characters.
2. Check for an optional initial '+' or '-' sign and set the sign accordingly.
3. Iterate through the characters of the string until a non-digit character is encountered or the end of the string is reached.
4. Convert the numerical digits to an integer, checking for overflow and underflow conditions.
5. Return the resulting integer, considering the sign.

CODE:
*/

#include <string>
#include <climits>
using namespace std;

int myAtoi(string input) {
    int sign = 1;          // To store the sign of the number
    int result = 0;        // To store the resulting integer
    int index = 0;         // To iterate through the string
    int n = input.size();  // Length of the input string

    // Discard all spaces from the beginning of the input string
    while (index < n && input[index] == ' ') {
        index++;
    }

    // Check for the sign of the number
    if (index < n && input[index] == '+') {
        sign = 1;
        index++;
    } else if (index < n && input[index] == '-') {
        sign = -1;
        index++;
    }

    // Traverse the next digits of input and stop if it is not a digit
    while (index < n && isdigit(input[index])) {
        int digit = input[index] - '0';

        // Check overflow and underflow conditions
        if (result > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        // Append current digit to the result
        result = result * 10 + digit;
        index++;
    }

    // Return the resulting integer multiplied by the sign
    return sign * result;
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the input string. Each character is processed at most once.
SPACE COMPLEXITY: O(1), as no extra space proportional to the input size is used.
*/
