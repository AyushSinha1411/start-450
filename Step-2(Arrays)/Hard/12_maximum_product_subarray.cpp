/*
QUESTION:
Given an array 'arr', find the maximum product of any contiguous subarray.

Example:
Input:
arr = [2, 3, -2, 4], n = 4
Output:
6 // Subarray: [2, 3]

APPROACH:
1. Initialize two variables 'pre' and 'suff' to keep track of the product of elements encountered so far from the left and right ends respectively.
2. Iterate through the array and update 'pre' and 'suff' by multiplying with the current element.
3. Keep track of the maximum product encountered so far using the 'ans' variable.
4. Update 'ans' with the maximum of 'pre', 'suff', and the current maximum product.
5. Return 'ans' as the result.

CODE:
*/

#include <vector>
#include <climits>
using namespace std;

int maxProductSubArray(vector<int> &arr) {
    int n = arr.size(); // size of array

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

/*
TIME COMPLEXITY: O(n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
