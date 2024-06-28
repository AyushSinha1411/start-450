/*
QUESTION:
Given arrival and departure times of trains at a railway station, find the minimum number of platforms required at the station so that no train waits.

Example:
Input: n = 6, arr[] = {900, 940, 950, 1100, 1500, 1800}, dep[] = {910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: There are at most three trains at the station at the same time (at time 1100).

APPROACH:
1. Sort the arrival and departure times.
2. Use two pointers to traverse the sorted arrival and departure times.
3. If the next event in sorted order is an arrival, increment the platform count.
4. If the next event in sorted order is a departure, decrement the platform count.
5. Track the maximum number of platforms needed at any time.

CODE:
*/

#include <algorithm>
using namespace std;

int countPlatforms(int n, int arr[], int dep[]) {
    // Sort the arrival and departure times
    sort(arr, arr + n);
    sort(dep, dep + n);

    // Initialize platform count and the maximum number of platforms needed
    int ans = 1; // At least one platform needed initially
    int count = 1;
    int i = 1; // Pointer for arrival times
    int j = 0; // Pointer for departure times

    // Traverse the sorted arrival and departure times
    while (i < n && j < n) {
        // If the next event is an arrival, increment the platform count
        if (arr[i] <= dep[j]) {
            count++;
            i++;
        }
        // If the next event is a departure, decrement the platform count
        else {
            count--;
            j++;
        }
        // Update the maximum number of platforms needed
        ans = max(ans, count);
    }
    return ans;
}

/*
TIME COMPLEXITY:
- O(n log n) for sorting the arrival and departure times.
- O(n) for traversing the arrival and departure times.

SPACE COMPLEXITY:
- O(1), as we are using a constant amount of extra space.
- The only additional space used is for the `ans`, `count`, `i`, and `j` variables.
*/
