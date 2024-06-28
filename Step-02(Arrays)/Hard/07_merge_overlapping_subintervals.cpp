/*
QUESTION:
Given a list of intervals represented as vectors of integers [start, end], merge all overlapping intervals.

Example:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: The intervals [1,3] and [2,6] overlap and are merged into [1,6].

APPROACH:
1. Sort the intervals based on their start times.
2. Initialize an empty vector ans to store merged intervals.
3. Iterate through the sorted intervals.
4. If the current interval does not overlap with the last interval in ans, add it to ans.
5. If it overlaps, merge it with the last interval in ans.
6. Return ans, containing merged intervals.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // Size of the array

    // Sort the intervals based on their start times
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans; // Vector to store merged intervals

    for (int i = 0; i < n; i++) {
        // If the current interval does not overlap with the last interval in ans, add it to ans
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        } 
        // If it overlaps, merge it with the last interval in ans
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans; // Return merged intervals
}

/*
TIME COMPLEXITY: O(N log N), where N is the number of intervals, due to sorting.
SPACE COMPLEXITY: O(N), where N is the number of intervals, to store the merged intervals.
*/
