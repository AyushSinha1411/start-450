/*
QUESTION:
Write a function to count the number of different bits between two integers a and b. The function should return the number of bits that are different between the binary representations of a and b.

Example:
Input: a = 4, b = 7
Output: 2
Explanation: The binary representation of 4 is 100 and 7 is 111. They differ in two bits.

APPROACH:
1. Use bitwise operations to compare the bits of a and b.
2. Iterate through each bit of both integers.
3. Compare the least significant bit of both integers and count the differences.
4. Right shift both integers to compare the next bit.
5. Continue until both integers are zero.

CODE:
*/

#include <iostream>
using namespace std;

// Function to count the number of different bits between two integers
int countBits(int a, int b) {
    int count = 0;
    while (a || b) {
        int last_bit_a = a & 1;
        int last_bit_b = b & 1;
        if (last_bit_a != last_bit_b) count++;
        a = a >> 1;
        b = b >> 1;
    }
    return count;
}

/*
TIME COMPLEXITY: O(log N), where N is the maximum value of the integers a or b. This is because we iterate through the bits of the integers.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameters.
*/