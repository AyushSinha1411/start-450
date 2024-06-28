/*
QUESTION:
Given an array 'a' of integers, find the number of inversions in the array. An inversion occurs if there are two indices i and j such that i < j but a[i] > a[j].

APPROACH:
1. Implement the merge sort algorithm with slight modifications to count the inversions.
2. During the merge step, while merging the sorted halves, count the inversions.
3. Whenever an element from the right half is smaller than an element from the left half, there are (mid - left + 1) inversions, where 'mid' is the middle index and 'left' is the starting index of the left half.
4. Add this count of inversions to the total count and continue the merge process.
5. Return the total count of inversions.

CODE:
*/
/*
EXAMPLE:
Suppose we have an array: arr = {8, 4, 2, 1, 3, 7, 6, 5}.

EXPECTED OUTPUT:
The number of inversions in the array is 16.

EXPLANATION:
1. (8, 4), (8, 2), (8, 1), (8, 3), (8, 7), (8, 6), (8, 5) => 7 inversions
2. (4, 2), (4, 1), (4, 3), (4, 7), (4, 6), (4, 5) => 6 inversions
3. (2, 1) => 1 inversion
4. (7, 6) => 1 inversion
5. (7, 5), (6, 5) => 2 inversions

TOTAL: 7 + 6 + 1 + 1 + 2 = 17 inversions

IMPLEMENTATION:
*/
#include <vector>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // Temporary array
    int left = low;   // Starting index of left half of arr
    int right = mid + 1; // Starting index of right half of arr

    int cnt = 0; // Count of inversions

    // Storing elements in the temporary array in a sorted manner
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); // Increment count of inversions
            right++;
        }
    }

    // If elements on the left half are still left
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // If elements on the right half are still left
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Transfer all elements from temporary to arr
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Return count of inversions
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);  // Sort left half
    cnt += mergeSort(arr, mid + 1, high); // Sort right half
    cnt += merge(arr, low, mid, high);  // Merge sorted halves and count inversions
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {
    // Count the number of inversions
    return mergeSort(a, 0, n - 1);
}

/*
TIME COMPLEXITY: O(n*log(n)), where n is the size of the array.
SPACE COMPLEXITY: O(n), where n is the size of the array.
*/
