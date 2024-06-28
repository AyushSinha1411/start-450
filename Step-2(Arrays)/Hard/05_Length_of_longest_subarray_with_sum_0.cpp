/*
QUESTION:
Given an integer array A of size N, find the length of the longest subarray with sum equal to 0.

Example:
Input: A = [15, -2, 2, -8, 1, 7, 10, 23], N = 8
Output: 5
Explanation: The longest subarray with sum equal to 0 is [-2, 2, -8, 1, 7].

APPROACH:
1. Initialize an unordered_map to store the prefix sum and its corresponding index.
2. Initialize variables maxi and sum to keep track of the maximum length and current sum respectively.
3. Iterate through the array A.
4. Calculate the prefix sum by adding the current element to the sum.
5. If the sum becomes 0, update maxi to i + 1 (length of the subarray).
6. If the sum is already present in the map, update maxi by taking the maximum of current maxi and i - mpp[sum].
7. If the sum is not present in the map, store it along with its index in the map.
8. Return maxi.

CODE:
*/

#include <unordered_map>
using namespace std;

int maxLen(int A[], int n) {
    unordered_map<int, int> mpp; // Map to store prefix sum and its index
    int maxi = 0; // Maximum length of subarray with sum equal to 0
    int sum = 0; // Current sum of elements

    for (int i = 0; i < n; i++) {
        sum += A[i]; // Calculate prefix sum

        if (sum == 0) {
            maxi = i + 1; // Update maxi if sum is 0
        } else {
            if (mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); // Update maxi if sum is present in the map
            } else {
                mpp[sum] = i; // Store sum along with its index in the map
            }
        }
    }

    return maxi; // Return the maximum length of subarray with sum equal to 0
}

/*
TIME COMPLEXITY: O(N), where N is the size of the array.
SPACE COMPLEXITY: O(N), as the unordered_map can store up to N distinct prefix sums.
*/
