/*
QUESTION:
Write a function to find the element that occurs an odd number of times in an array. Assume that exactly one element in the array occurs an odd number of times, while all others occur an even number of times.

Example:
Input: ar = [2, 3, 4, 3, 1, 4, 1]
Output: 2
Explanation: The number 2 occurs an odd number of times in the array.

APPROACH:
1. Initialize a result variable to 0.
2. Iterate through each element in the array.
3. Use the XOR operator to accumulate the result.
4. The element that occurs an odd number of times will remain in the result.

CODE:
*/

#include <iostream>
using namespace std;

// Function to find the element that occurs an odd number of times in the array
int getOddOccurrence(int ar[], int ar_size) {
    int res = 0;
    for (int i = 0; i < ar_size; i++) {
        res = res ^ ar[i];
    }
    return res;
}

/*
TIME COMPLEXITY: O(N), where N is the size of the array. This is because we iterate through the array once.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameters.
*/