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

 static bool comparator(struct Meeting m1, struct Meeting m2) {
           return (m1.end < m2.end) ;
         
     
    }
     int maxMeetings(int n, int start[], int end[]) {
        struct Meeting meet[n];
        for (int i = 0; i < n; i++) {
            meet[i].start = start[i];
            meet[i].end = end[i];
            meet[i].pos = i + 1;
        }

        // Sorting meetings based on the comparator
        sort(meet, meet + n, comparator);

        int answer=1;

        // The first meeting always gets selected
        int limit = meet[0].end;
  

        // Iterating through the remaining meetings
        for (int i = 1; i < n; i++) {
            if (meet[i].start > limit) {
                limit = meet[i].end;
                answer++;
            }
        }


        // Return the number of meetings that can be performed
        return answer;
    }

/*

TIME COMPLEXITY:
- O(n log n) for sorting the meetings.

SPACE COMPLEXITY:
- O(n) for storing the meetings and their corresponding times.
*/
