/*
QUESTION:
You are given an array 'stalls' representing the positions of stalls, where each stall is represented by an integer position. You want to place 'k' cows in these stalls such that the minimum distance between any two cows is maximized. Find the maximum possible minimum distance.

Example:
Input:
stalls = [1, 2, 4, 8, 9], k = 3
Output:
3 // The maximum possible minimum distance between any two cows is 3.

APPROACH:
1. Sort the stalls array.
2. Use binary search to find the maximum possible minimum distance.
3. Initialize low to 1 and high to the distance between the first and last stall.
4. In each iteration of the binary search:
    a. Calculate the mid distance.
    b. Check if it's possible to place 'k' cows with at least 'mid' distance between them using a helper function.
    c. If possible, update low to mid + 1; otherwise, update high to mid - 1.
5. Return high, which represents the maximum possible minimum distance.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); // Size of array
    int cntCows = 1; // Number of cows placed
    int last = stalls[0]; // Position of last placed cow
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; // Place next cow
            last = stalls[i]; // Update the last location
        }
        if (cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); // Size of array
    // Sort the stalls array
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0]; // Initialize binary search range
    // Apply binary search
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate mid distance
        // Check if it's possible to place 'k' cows with at least 'mid' distance between them
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1; // Update low
        } else {
            high = mid - 1; // Update high
        }
    }
    return high; // Return the maximum possible minimum distance
}

/*
TIME COMPLEXITY: O(n log n + n log d), where n is the size of the stalls array and d is the maximum possible distance between any two stalls.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
