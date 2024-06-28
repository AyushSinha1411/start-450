/*
QUESTION:
Write a function to set the rightmost unset bit (0) in the binary representation of a given integer N. If all bits are set, the number should remain unchanged.

Example:
Input: N = 10
Output: 11
Explanation: The binary representation of 10 is 1010. Setting the rightmost unset bit results in 1011, which is 11.

APPROACH:
1. Initialize variables `ans` with the value of N, `pos` to track the bit position, and `flag` to indicate if an unset bit is found.
2. Iterate through the bits of N using a while loop.
3. Check each bit using bitwise AND with 1. If the bit is set, increment the position counter.
4. If an unset bit is found, set the flag and break the loop.
5. If an unset bit was found, set that bit in the result using bitwise OR.
6. Return the modified result.

CODE:
*/

#include <iostream>
using namespace std;

// Function to set the rightmost unset bit in the binary representation of N
int setBit(int N) {
    int ans = N;
    int pos = 0;
    int flag = 0;

    while (N != 0) {
        if (N & 1) {
            pos++;
        } else {
            flag = 1;
            break;
        }
        N = N >> 1;
    }

    if (flag) {
        ans = (ans | (1 << pos));
    }
    return ans;
}

/*
TIME COMPLEXITY: O(log N), where N is the input number. This is because the loop iterates over the bits of N.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameter.
*/
