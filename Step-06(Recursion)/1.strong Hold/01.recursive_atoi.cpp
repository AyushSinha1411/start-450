/*
QUESTION:
Write a recursive function to convert a string of numeric characters to an integer (similar to the atoi function). The function should handle the base case of an empty string or a string containing non-numeric characters by returning 0.

APPROACH:
1. Check if the string contains any non-numeric characters. If so, return 0.
2. Use recursion to convert the string to an integer. The base case is a single digit.
3. For strings with more than one digit, recursively call the function for the first n-1 characters, multiply the result by 10, and add the last digit.

CODE:
*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// Recursive function to compute atoi()
int myAtoiRecursive(char* str, int n) {
    // If str is NULL or str contains non-numeric characters then return 0 as the number is not valid
    if (str == NULL) return 0;

    // Check if the string contains any non-numeric characters
    for (int i = 0; i < n; ++i) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }

    // Base case (Only one digit)
    if (n == 1) {
        return *str - '0';
    }

    // If more than 1 digits, recur for (n-1), multiply result with 10 and add last digit
    return (10 * myAtoiRecursive(str, n - 1) + str[n - 1] - '0');
}

/*
TIME COMPLEXITY: O(N), where N is the length of the string. This is because we traverse the string once to check for non-numeric characters and then recursively process each character.
SPACE COMPLEXITY: O(N), due to the recursion stack for processing each character.
*/
