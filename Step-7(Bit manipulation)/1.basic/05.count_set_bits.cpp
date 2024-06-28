/*
QUESTION:
Write a function to count the number of set bits (1s) in the binary representation of all numbers from 1 to n.

Example:
Input: n = 5
Output: 7
Explanation: The binary representation of numbers from 1 to 5 are:
1 -> 0001 (1 set bit)
2 -> 0010 (1 set bit)
3 -> 0011 (2 set bits)
4 -> 0100 (1 set bit)
5 -> 0101 (2 set bits)
Total number of set bits = 1 + 1 + 2 + 1 + 2 = 7

APPROACH:
1. Increment n by 1 to include the number n itself.
2. Initialize the count of set bits to 0.
3. Use a loop to iterate over powers of 2.
4. For each power of 2, calculate the number of complete pairs of 0s and 1s.
5. Add the number of 1s from these complete pairs to the count.
6. Check for any remaining 1s that do not form a complete pair and add them to the count.
7. Return the total count of set bits.

CODE:
*/

#include <iostream>
using namespace std;

// Function to count the number of set bits from 1 to n
int countSetBits(int n) {
    n++; // Incrementing n to include the number n itself
    int count = 0;

    // Counting set bits from 1 to n
    for (int x = 2; x / 2 < n; x = x * 2) {
        // Total count of pairs of 0s and 1s
        int quotient = n / x;
        // Quotient gives the complete count of pairs of 1s
        // Multiplying it with the (current power of 2) / 2 will give the count of 1s in the current bit
        count += quotient * x / 2;

        int remainder = n % x;
        // If the count of pairs is odd then we add the remaining 1s which could not be grouped together
        if (remainder > x / 2)
            count += remainder - x / 2;
    }

    // Returning count of set bits
    return count;
}

/*
TIME COMPLEXITY: O(log N), where N is the input number. This is because the loop iterates over powers of 2.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameter.
*/
