/*
QUESTION:
Write a function to swap the values of two integers using bitwise XOR.

Example:
Input: a = 5, b = 10
Output: After swap, a = 10, b = 5
Explanation: The values of a and b are swapped using bitwise XOR operations.

APPROACH:
1. Use bitwise XOR to swap the values of two integers without using a temporary variable.
2. XOR the values of a and b and store the result back in a.
3. XOR the new value of a with b and store the result back in b.
4. XOR the new value of b with a and store the result back in a.

CODE:
*/

#include <iostream>
using namespace std;

// Function to swap the values of two integers using bitwise XOR
void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

/*
TIME COMPLEXITY: O(1), as the bitwise operations are performed in constant time.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameters.
*/