/*
QUESTION:
You are given two sorted arrays 'a' and 'b' of integers. Find the median of the two sorted arrays.

Example:
Input:
a = [1, 3]
b = [2]
Output:
2.0 // The median of the two sorted arrays is 2.0.

APPROACH:
1. Ensure that 'a' has the smaller size among the two arrays. If not, swap 'a' and 'b'.
2. Initialize variables 'n1' and 'n2' to store the sizes of arrays 'a' and 'b' respectively.
3. Calculate the total length of the merged array 'n'.
4. Calculate the length of the left half of the merged array 'left'.
5. Apply binary search on array 'a' to find the correct partition such that elements to the left of the partition are smaller than or equal to elements to the right.
6. Calculate the corresponding partition in array 'b'.
7. Determine the values of 'l1', 'l2', 'r1', and 'r2'.
8. If 'l1' <= 'r2' and 'l2' <= 'r1', calculate the median based on whether 'n' is odd or even.
9. If 'l1' > 'r2', adjust the search space by updating 'high' to 'mid1 - 1'.
10. If 'l2' > 'r1', adjust the search space by updating 'low' to 'mid1 + 1'.
11. Repeat steps 5-10 until a valid partition is found.
12. Return the calculated median.

CODE:
*/

#include <vector>
#include <climits>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    // Ensure that 'a' has the smaller size among the two arrays
    if (n1 > n2) return median(b, a);

    int n = n1 + n2; // Total length
    int left = (n1 + n2 + 1) / 2; // Length of left half

    // Apply binary search
    int low = 0, high = n1;
    while (low <= high) {
        int mid1 = (low + high) >> 1; // Calculate mid value for array 'a'
        int mid2 = left - mid1; // Calculate mid value for array 'b'

        // Calculate values of 'l1', 'l2', 'r1', and 'r2'
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        // Check if partitions are valid
        if (l1 <= r2 && l2 <= r1) {
            // Calculate median based on odd or even length of 'n'
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        // Adjust search space
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; // Dummy return statement
}

/*
TIME COMPLEXITY: O(log(min(n1, n2))), where n1 and n2 are the sizes of arrays 'a' and 'b' respectively.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
