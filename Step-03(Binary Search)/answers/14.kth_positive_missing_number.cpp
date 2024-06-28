/*
QUESTION:
Given a sorted array 'vec' of size 'n', where each element of the array is distinct, and an integer 'k', you need to find the kth missing number in the array. If the kth missing number does not exist, return k + n.

Example:
Input:
vec = [2, 3, 4, 7, 11], n = 5, k = 5
Output:
9 // The 5th missing number in the array is 9.

APPROACH:
1. Use binary search to find the kth missing number in the sorted array.
2. Initialize low to 0 and high to n - 1.
3. Calculate the number of missing elements before the mid element.
4. If the number of missing elements is less than k, move to the right half; otherwise, move to the left half.
5. Return k + high + 1 if the kth missing number is not found within the array.

CODE:
*/

#include <vector>
using namespace std;

int missingK(vector<int> &vec, int n, int k) {
    // Initialize low to 0 and high to n - 1.
    int low = 0, high = n - 1;
    // Binary search to find the kth missing number.
    while (low <= high) {
        // Calculate the mid index.
        int mid = (low + high) / 2;
        // Calculate the number of missing elements before the mid element.
        int missing = vec[mid] - (mid + 1);
        // If the number of missing elements is less than k, move to the right half.
        if (missing < k) {
            low = mid + 1;
        }
        // Otherwise, move to the left half.
        else {
            high = mid - 1;
        }
    }
    // Return k + high + 1 if the kth missing number is not found within the array.
    return k + high + 1;
}

/*
TIME COMPLEXITY: O(log n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
