/*
QUESTION:
Write a function to determine if a given integer n is odd or even. Return the string "odd" if the number is odd, and "even" if the number is even.

Example:
Input: n = 5
Output: "odd"
Explanation: The number 5 is odd.

APPROACH:
1. Use bitwise AND to check the least significant bit of the integer.
2. If the least significant bit is 1, the number is odd.
3. If the least significant bit is 0, the number is even.

CODE:
*/

#include <iostream>
using namespace std;

// Function to determine if a given integer is odd or even using bitwise AND
string oddEven(int n) {
    return (n & 1) ? "odd" : "even";
}

/*
TIME COMPLEXITY: O(1), as the operation to check if a number is even or odd using bitwise AND is performed in constant time.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameter.
*/
