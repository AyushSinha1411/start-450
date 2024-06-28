/*
QUESTION:
Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

APPROACH:
1. Sort the intervals based on the starting times.
2. Initialize an empty result vector.
3. Iterate through the sorted intervals:
   - If the result vector is empty or the current interval does not overlap with the last interval in the result, add it to the result.
   - If the current interval overlaps with the last interval in the result, merge them by updating the end time of the last interval.
4. Return the result vector containing merged intervals.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& arr) {
    int n = arr.size(); // Size of the array

    // Sort the intervals based on the starting times
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans; // Resultant merged intervals

    for (int i = 0; i < n; i++) {
        // If the result is empty or the current interval does not overlap with the last interval
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]); // Add the current interval
        } else {
            // Merge the current interval with the last interval in the result
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans; // Return the merged intervals
}

/*
TIME COMPLEXITY:
- O(n log n) for sorting the intervals.
- O(n) for merging intervals.

SPACE COMPLEXITY:
- O(n) for storing the merged intervals.

EXAMPLE USAGE:
vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
vector<vector<int>> result = mergeOverlappingIntervals(intervals);
// result will be [[1, 6], [8, 10], [15, 18]]
*/
