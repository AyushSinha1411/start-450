#include <bits/stdc++.h>
using namespace std;

/*
 * Question:
 * Convert a string to a 32-bit signed integer (similar to C/C++'s `atoi` function). Handle leading whitespaces, optional sign, and numeric digits. 
 * Clamp the result within the 32-bit signed integer range if necessary.
 *
 * Approach:
 * 1. Define a helper function that processes the string recursively.
 * 2. Handle the whitespace and optional sign.
 * 3. Convert the digits to an integer recursively.
 * 4. Clamp the result to the 32-bit signed integer range.
 */

// Recursive function to convert string to integer
int myAtoiHelper(string &s, int index, int sign, long long current) {
    // Base case: end of string or non-digit character
    if (index == s.length() || !isdigit(s[index])) {
        return sign * current;
    }
    
    // Append the current digit to the number
    current = current * 10 + (s[index] - '0');
    
    // Clamp to the 32-bit signed integer range
    if (sign * current <= INT_MIN) return INT_MIN;
    if (sign * current >= INT_MAX) return INT_MAX;
    
    // Recursive call for the next character
    return myAtoiHelper(s, index + 1, sign, current);
}

int myAtoi(string s) {
    int index = 0;
    // Ignore leading whitespace
    while (index < s.length() && s[index] == ' ') {
        index++;
    }
    
    // Determine the sign
    int sign = 1;
    if (index < s.length() && (s[index] == '-' || s[index] == '+')) {
        sign = (s[index] == '-') ? -1 : 1;
        index++;
    }
    
    // Start the recursive conversion
    return myAtoiHelper(s, index, sign, 0);
}

int main() {
    string str = "   -42";
    cout << myAtoi(str) << endl; // Output: -42
    return 0;
}

/*
 * Time Complexity:
 * The time complexity is O(n), where n is the length of the input string.
 *
 * Space Complexity:
 * The space complexity is O(n) due to the recursion stack.
 */
