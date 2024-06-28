/*
QUESTION:
Given a boolean 2D array 'matrix' of size 'n x m' where each row is sorted. Find the row with the maximum number of 1s.

Example:
Input:
matrix = [
  [0, 0, 0, 1],
  [0, 1, 1, 1],
  [0, 0, 1, 1],
  [0, 0, 0, 0]
]
n = 4, m = 4
Output:
1 // The row with index 1 has the maximum number of 1s.

APPROACH:
1. Initialize 'cnt_max' to store the maximum number of 1s encountered and 'index' to store the index of the row with maximum 1s.
2. Traverse each row of the matrix.
3. Count the number of 1s in each row using binary search.
4. Update 'cnt_max' and 'index' if the current row has more 1s than the previous maximum.
5. Return the index of the row with maximum 1s.

CODE:
*/

#include <vector>
using namespace std;

// Function to find the lower bound of an element in a sorted array
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // Check if mid is a possible answer
        if (arr[mid] >= x) {
            ans = mid;
            // Look for smaller index on the left
            high = mid - 1;
        }
        else {
            // Look on the right
            low = mid + 1;
        }
    }
    return ans;
}

// Function to find the row with the maximum number of 1s
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0; // Maximum number of 1s encountered
    int index = -1; // Index of row with maximum 1s

    // Traverse each row
    for (int i = 0; i < n; i++) {
        // Count the number of 1s in the current row
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        // Update maximum count and index if needed
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index; // Return index of row with maximum 1s
}

/*
TIME COMPLEXITY: O(n * log(m)), where 'n' is the number of rows and 'm' is the number of columns.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
