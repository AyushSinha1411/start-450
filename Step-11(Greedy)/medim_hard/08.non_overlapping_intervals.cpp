/*
QUESTION:
Given an array of intervals `intervals` where intervals[i] = [start_i, end_i], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

APPROACH:
1. Sort the intervals based on their end times.
2. Initialize a variable `k` to keep track of the end time of the last added interval.
3. Iterate through the sorted intervals:
   - If the start time of the current interval is greater than or equal to `k`, update `k` to the end time of the current interval.
   - If the start time of the current interval is less than `k`, increment the count of intervals to be removed.
4. Return the count of removed intervals.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

// Comparator function to sort intervals by their end times
bool compareSecondElement(const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // Sort the intervals by their end times
    sort(intervals.begin(), intervals.end(), compareSecondElement);
    int ans = 0;
    int k = INT_MIN;

    for (int i = 0; i < intervals.size(); i++) {
        int x = intervals[i][0];
        int y = intervals[i][1];

        if (x >= k) {
            // If the start time of the current interval is greater than or equal to k, update k to the end time of the current interval
            k = y;
        } else {
            // If the start time of the current interval is less than k, increment the count of intervals to be removed
            ans++;
        }
    }

    return ans; // Return the count of removed intervals
}

/*
TIME COMPLEXITY:
- O(n log n) for sorting the intervals.
- O(n) for iterating through the intervals to count removals.

SPACE COMPLEXITY:
- O(1) for using constant extra space.

EXAMPLE USAGE:
vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
int result = eraseOverlapIntervals(intervals);
// result will be 1
*/
