/*
QUESTION:
Given a set of non-overlapping intervals and a new interval, insert the new interval into the intervals (merge if necessary). The intervals are sorted by their start times.

Example:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

APPROACH:
1. Append the new interval to the list of existing intervals.
2. Sort the intervals based on their starting times.
3. Initialize an empty result vector.
4. Iterate through the sorted intervals:
   - If the result vector is empty or the current interval does not overlap with the last interval in the result, add it to the result.
   - If the current interval overlaps with the last interval in the result, merge them by updating the end time of the last interval.
5. Return the result vector containing merged intervals.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    intervals.push_back(newInterval); // Add the new interval
    sort(intervals.begin(), intervals.end()); // Sort intervals by start times

    vector<vector<int>> ans; // Resultant merged intervals
    for (const auto& interval : intervals) {
        // If the result is empty or the current interval does not overlap with the last interval
        if (ans.empty() || interval[0] > ans.back()[1]) {
            ans.push_back(interval); // Add the current interval
        } else {
            // Merge the current interval with the last interval in the result
            ans.back()[1] = max(ans.back()[1], interval[1]);
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
vector<vector<int>> intervals = {{1, 3}, {6, 9}};
vector<int> newInterval = {2, 5};
vector<vector<int>> result = insert(intervals, newInterval);
// result will be [[1, 5], [6, 9]]
*/
