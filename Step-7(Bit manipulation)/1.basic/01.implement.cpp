/*
QUESTION:
Write a function to perform bit manipulation on a given integer. For a given bit position i, the function should:
1. Print whether the ith bit is set (1) or not (0).
2. Print the number after setting the ith bit.
3. Print the number after clearing the ith bit.

Example:
Input: num = 5, i = 2
Output: 0 7 5
Explanation: For num = 5 (binary 101), the 2nd bit is 0. 
Setting the 2nd bit results in 7 (binary 111). 
Clearing the 2nd bit leaves the number unchanged at 5 (binary 101).

APPROACH:
1. Use bitwise AND to check if the ith bit is set.
2. Use bitwise OR to set the ith bit.
3. Use bitwise AND with the negation of a bit-shifted 1 to clear the ith bit.
4. Print the results accordingly.

CODE:
*/

#include <iostream>
using namespace std;

void bitManipulation(int num, int i) {
    // Check if the ith bit is set
    int g = (num & (1 << (i - 1)));
    if (g) {
        cout << 1 << " ";
    } else {
        cout << 0 << " ";
    }

    // Set the ith bit
    int s = (num | (1 << (i - 1)));
    cout << s << " ";

    // Clear the ith bit
    int c = (num & (~(1 << (i - 1))));
    cout << c << " ";
}

/*
TIME COMPLEXITY: O(1), as bitwise operations are performed in constant time.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameters.
*/
