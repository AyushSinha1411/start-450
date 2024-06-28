/*
QUESTION:
Implement binary search to find the index of the first occurrence of a given value 'x' in a sorted array 'arr'. If 'x' is not found, return the index where it would be inserted in order to maintain sorted order.

Example:
Input:
arr = [1, 3, 5, 6], x = 5
Output:
2 // Index of the first occurrence of 5 in the array

Input:
arr = [1, 3, 5, 6], x = 2
Output:
1 // Index where 2 would be inserted to maintain sorted order

APPROACH:
1. Initialize two pointers 'low' and 'high' to the start and end of the array respectively.
2. Initialize 'ans' to 'n' (size of the array).
3. Iterate until 'low' is less than or equal to 'high'.
4. Calculate the middle index 'mid' as the average of 'low' and 'high'.
5. If the element at 'mid' is greater than or equal to 'x', update 'ans' to 'mid' and search on the left side.
6. If the element at 'mid' is less than 'x', search on the right side.
7. Repeat steps 3-6 until 'low' becomes greater than 'high'.
8. Return 'ans', which will be the index where 'x' would be inserted to maintain sorted order.

CODE:
*/

#include <vector>
using namespace std;

int searchInsert(vector<int>& arr, int x) {
    int n = arr.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            // look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

/*
TIME COMPLEXITY: O(log n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
