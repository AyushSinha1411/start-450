/*
QUESTION:
Write a function to find the number of subarrays with exactly k odd numbers in the given array A.

Example:
Input: A = [1, 1, 2, 1, 1], k = 3
Output: 2
Explanation:
The subarrays with exactly 3 odd numbers are [1, 1, 2, 1] and [1, 2, 1, 1].

APPROACH:
1. Use the sliding window technique to maintain a window with exactly k odd numbers.
2. Initialize two pointers, i and j, to define the window.
3. Iterate through the array with the j pointer.
4. If the current element is odd, decrement k and reset the count of valid subarrays ending at j.
5. If k is zero, increment the i pointer until k becomes non-zero, and count the number of valid subarrays.
6. Add the count to the result.
7. Return the total count of valid subarrays.

CODE:
*/

#include <vector>
using namespace std;

// Function to find the number of subarrays with exactly k odd numbers
int numberOfSubarrays(vector<int>& A, int k) {
    int res = 0, i = 0, count = 0, n = A.size();
    
    for (int j = 0; j < n; j++) {
        if (A[j] & 1) {
            --k;
            count = 0;
        }

        // Move the start pointer to the right until k is no longer zero
        while (k == 0) {
            k += A[i++] & 1;
            ++count;
        }

        // Add the count to the result
        res += count;
    }
    
    return res;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the array. This is because each element is visited at most twice (once by the j pointer and once by the i pointer).
SPACE COMPLEXITY: O(1), as we are using only a few extra variables for calculations.
*/
