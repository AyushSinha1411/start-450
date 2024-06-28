/*
QUESTION:
You are given an array 'boards' of integers representing the lengths of some boards and an integer 'k' representing the number of available painters. You need to find the largest possible minimum length such that each painter paints contiguous boards and no painter is assigned more than 'k' boards.

Example:
Input:
boards = [10, 20, 30, 40], k = 2
Output:
60 // The largest possible minimum length such that each painter paints contiguous boards and no painter is assigned more than 2 boards is 60, which is obtained by assigning boards [10, 20, 30] to the first painter and [40] to the second painter.

APPROACH:
1. Define a helper function 'countPainters' to count the number of painters required for a given maximum time.
2. Use binary search to find the largest possible minimum time.
3. Initialize low to the maximum element in 'boards' and high to the sum of all elements in 'boards'.
4. In each iteration of the binary search:
    a. Calculate the mid value.
    b. Count the number of painters required for this mid value using the 'countPainters' function.
    c. If the number of painters required is greater than 'k', update low to mid + 1; otherwise, update high to mid - 1.
5. Return low, which represents the largest possible minimum length.

CODE:
*/

#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int countPainters(vector<int> &boards, int time) {
    int n = boards.size(); // Size of array
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            // Allocate board to current painter
            boardsPainter += boards[i];
        } else {
            // Allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    // Initialize binary search range
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    // Apply binary search
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate mid value
        // Count the number of painters required for this mid value
        int painters = countPainters(boards, mid);
        if (painters > k) {
            low = mid + 1; // Update low
        } else {
            high = mid - 1; // Update high
        }
    }
    return low; // Return the largest possible minimum length
}

/*
TIME COMPLEXITY: O(n log s), where n is the size of the 'boards' array and s is the difference between the maximum and minimum possible values of the length of boards.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
