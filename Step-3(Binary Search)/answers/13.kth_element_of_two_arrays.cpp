/*
QUESTION:
You are given two sorted arrays 'a' and 'b' of integers of sizes 'm' and 'n' respectively. Find the kth element in the merged sorted array of 'a' and 'b'.

Example:
Input:
a = [1, 3, 8]
b = [2, 4, 5, 6, 7]
k = 4
Output:
4 // The 4th element in the merged sorted array is 4.

APPROACH:
1. Ensure that 'a' has the smaller size among the two arrays. If not, swap 'a' and 'b'.
2. Initialize 'left' to store the length of the left half of the merged array.
3. Apply binary search on 'a' to find the correct partition such that elements to the left of the partition are smaller than or equal to elements to the right.
4. Calculate the corresponding partition in 'b'.
5. Determine the values of 'l1', 'l2', 'r1', and 'r2'.
6. If 'l1' <= 'r2' and 'l2' <= 'r1', return the maximum of 'l1' and 'l2'.
7. If 'l1' > 'r2', adjust the search space by updating 'high' to 'mid1 - 1'.
8. If 'l2' > 'r1', adjust the search space by updating 'low' to 'mid1 + 1'.
9. Repeat steps 3-8 until the kth element is found.
10. Return the kth element.

CODE:
*/

#include <vector>
#include <climits>
using namespace std;

int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) {
    // Ensure that 'a' has the smaller size among the two arrays
    if (m > n) return kthElement(b, a, n, m, k);

    int left = k; // Length of left half

    // Apply binary search
    int low = max(0, k - n), high = min(k, m);
    while (low <= high) {
        int mid1 = (low + high) >> 1; // Calculate mid value for array 'a'
        int mid2 = left - mid1; // Calculate mid value for array 'b'

        // Calculate values of 'l1', 'l2', 'r1', and 'r2'
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < m) r1 = a[mid1];
        if (mid2 < n) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        // Check if partitions are valid
        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        // Adjust search space
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; // Dummy return statement
}

/*
TIME COMPLEXITY: O(log(min(m, n))), where m and n are the sizes of arrays 'a' and 'b' respectively.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
