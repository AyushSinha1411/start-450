/*
QUESTION:
Sort an array consisting of only 0s, 1s, and 2s without using any sorting algorithm.

Example:
Input:
arr = [2, 0, 2, 1, 1, 0], n = 6
Output:
The sorted array is: [0, 0, 1, 1, 2, 2]

APPROACH:
1. Initialize three pointers, low, mid, and high, to 0, 0, and n-1 respectively.
2. Iterate through the array using the mid pointer:
   - If arr[mid] is 0, swap it with arr[low], and increment both low and mid pointers.
   - If arr[mid] is 1, simply increment the mid pointer.
   - If arr[mid] is 2, swap it with arr[high], and decrement the high pointer.
3. Continue this process until mid pointer exceeds the high pointer.
4. This approach ensures that all 0s are moved to the beginning, all 1s remain in the middle, and all 2s are moved to the end of the array.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to sort an array consisting of 0s, 1s, and 2s
void sortArray(vector<int>& arr, int n) {
    int low = 0, mid = 0, high = n - 1; // Initialize three pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]); // Swap 0 to the low position
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++; // Move to the next element if it is 1
        } else {
            swap(arr[mid], arr[high]); // Swap 2 to the high position
            high--;
        }
    }
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
