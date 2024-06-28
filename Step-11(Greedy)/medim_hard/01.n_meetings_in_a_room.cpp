/*
QUESTION:
Given `start[]` and `end[]` arrays that denote the starting and ending times of `n` meetings respectively, determine the maximum number of meetings that can be held in one room such that no two meetings overlap.

Example:
Input: start[] = {1, 3, 0, 5, 8, 5}, end[] = {2, 4, 6, 7, 9, 9}, n = 6
Output: 4
Explanation: The maximum set of meetings that can be accommodated is {1, 2}, {3, 4}, {5, 7}, and {8, 9}.

APPROACH:
1. Create a vector of pairs where each pair contains another pair of start and end times, and an index.
2. Sort the vector based on end times. If end times are equal, sort by index.
3. Iterate through the sorted vector and count meetings that do not overlap by comparing start times with the last selected meeting's end time.
4. Return the count of non-overlapping meetings.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

static bool pairCompare(const pair<pair<int, int>, int> &a,
                        const pair<pair<int, int>, int> &b) {
    if (a.first.second != b.first.second) {
        return a.first.second < b.first.second;
    }
    return a.second < b.second;
}

// Function to find the maximum number of meetings that can be performed in a meeting room.
int maxMeetings(int start[], int end[], int n) {
    vector<pair<pair<int, int>, int>> x;

    // Pushing the pair of starting and finish time and their index as pair in another list.
    for (int i = 0; i < n; i++) {
        x.push_back({{start[i], end[i]}, i + 1});
    }

    // Sorting the list.
    sort(x.begin(), x.end(), pairCompare);
    int last = -1;
    int res = 0;

    for (int i = 0; i < n; i++) {
        // If the start time of this meeting is greater than or equal to the finish time of previously selected meeting,
        // then we increment the counter and update last.
        if (x[i].first.first > last) {
            res++;
            last = x[i].first.second;
        }
    }
    // Returning the counter.
    return res;
}

/*

TIME COMPLEXITY:
- O(n log n) for sorting the meetings.

SPACE COMPLEXITY:
- O(n) for storing the meetings and their corresponding times.
*/
