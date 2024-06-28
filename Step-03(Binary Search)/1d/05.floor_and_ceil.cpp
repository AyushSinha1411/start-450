/*
QUESTION:
Given a sorted array 'arr' of size 'n', implement functions to find the floor and ceiling of a given number 'x'. If 'x' is present in the array, floor and ceiling are the same as 'x'. If 'x' is smaller than the smallest element in the array, floor does not exist and ceiling is the smallest element. If 'x' is larger than the largest element in the array, ceiling does not exist and floor is the largest element.

Example:
Input:
arr = [1, 2, 8, 10, 10, 12, 19], x = 5
Output:
Floor = 2, Ceiling = 8 // 2 is the largest element smaller than 5, and 8 is the smallest element greater than 5

APPROACH:
1. Implement binary search to find the floor of 'x'. Iterate until 'low' is less than or equal to 'high'.
2. If the element at 'mid' is less than or equal to 'x', update 'ans' to the element at 'mid' and search on the right side.
3. If the element at 'mid' is greater than 'x', search on the left side.
4. Repeat steps 1-3 until 'low' becomes greater than 'high'.
5. Implement binary search to find the ceiling of 'x'. Iterate until 'low' is less than or equal to 'high'.
6. If the element at 'mid' is greater than or equal to 'x', update 'ans' to the element at 'mid' and search on the left side.
7. If the element at 'mid' is less than 'x', search on the right side.
8. Repeat steps 5-7 until 'low' becomes greater than 'high'.
9. Return a pair containing the floor and ceiling of 'x'.

CODE:
*/

#include <utility> // for pair
using namespace std;

int findFloor(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] <= x) {
            ans = arr[mid];
            // look for larger index on the right
            low = mid + 1;
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return ans;
}

int findCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = arr[mid];
            // look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int f = findFloor(arr, n, x);
    int c = findCeil(arr, n, x);
    return make_pair(f, c);
}

/*
TIME COMPLEXITY: O(log n), where n is the size of the array.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
