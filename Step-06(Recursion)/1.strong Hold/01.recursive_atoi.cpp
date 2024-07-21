// Question: Implement the `myAtoi` function which converts a string to a 32-bit signed integer (similar to C/C++'s `atoi` function). The function should discard leading whitespaces, take an optional '+' or '-' sign, and stop at the first non-digit character. If the integer is out of the 32-bit signed integer range, clamp it to INT_MAX or INT_MIN.

class Solution {
public:
    int myAtoi(string s) {
        int i = 0; // Initialize index to traverse the string
        int sign = 1; // Initialize sign to positive
        long ans = 0; // Initialize answer to 0

        // Skip leading whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Check for optional sign
        if (i < s.length() && s[i] == '-') {
            sign = -1; // Set sign to negative
            i++;
        } else if (i < s.length() && s[i] == '+') {
            i++; // Sign is positive, just skip it
        }

        // Convert digits to integer
        while (i < s.length()) {
            // Check if current character is a digit
            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + (s[i] - '0'); // Add digit to answer

                // Check for overflow
                if (ans > INT_MAX && sign == -1) {
                    return INT_MIN; // Return INT_MIN if overflow in negative
                } else if (ans > INT_MAX && sign == 1) {
                    return INT_MAX; // Return INT_MAX if overflow in positive
                }

                i++; // Move to next character
            } else {
                break; // Break if current character is not a digit
            }
        }

        return ans * sign; // Return final result with sign
    }
};

// Time Complexity: O(n), where n is the length of the string. Each character is processed at most once.
// Space Complexity: O(1), since only a fixed amount of extra space is used.
