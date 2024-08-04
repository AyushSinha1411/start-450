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

    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals based on their end times
        sort(intervals.begin(), intervals.end(), compare);

        int n = intervals.size();
        int lastEndTime = intervals[0][1]; // End time of the last added interval
        int count = 1; // Count of non-overlapping intervals

        // Iterate through the intervals starting from the second interval
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastEndTime) {
                count++;
                lastEndTime = intervals[i][1];
            }
        }

        // The minimum number of intervals to remove is the total number of intervals minus the count of non-overlapping intervals
        return n - count;
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
