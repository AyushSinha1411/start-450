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
    vector<vector<int>> res; // Resultant list of intervals
    int i = 0; // Index for iterating through intervals
    int n = intervals.size(); // Number of intervals

    // Add all intervals that come before the new interval
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        i++;
    }

    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    // Add the merged interval
    res.push_back(newInterval);

    // Add all intervals that come after the new interval
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
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
