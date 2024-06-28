/*
QUESTION:
Implement binary search to find the index of a given target element in a sorted array 'nums'.

Example:
Input:
nums = [1, 3, 5, 7, 9], target = 5
Output:
2 // Index of target element 5

APPROACH:
1. Initialize two pointers 'low' and 'high' to the start and end of the array respectively.
2. Iterate until 'low' is less than or equal to 'high'.
3. Calculate the middle index 'mid' as the average of 'low' and 'high'.
4. Compare the target element with the element at 'mid'.
5. If they are equal, return 'mid'.
6. If the target is greater than the element at 'mid', update 'low' to 'mid + 1'.
7. If the target is smaller than the element at 'mid', update 'high' to 'mid - 1'.
8. Repeat steps 3-7 until the target element is found or 'low' becomes greater than 'high'.
9. If the target is not found, return -1.

CODE:
*/

#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); // size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

/*
TIME COMPLEXITY: O(log n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
