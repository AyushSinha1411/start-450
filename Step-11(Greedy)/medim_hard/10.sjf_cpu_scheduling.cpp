/*
QUESTION:
Given an array `bt` representing the burst times of different processes, the goal is to calculate the average waiting time using the Shortest Job First (SJF) scheduling algorithm. The waiting time for a process is the total time a process has to wait before it gets executed.

Example:
Input: bt = [5, 3, 8, 6]
Output: 4
Explanation:
- First, sort the burst times: [3, 5, 6, 8]
- The waiting times are: [0, 3, 8, 14]
- The average waiting time is (0 + 3 + 8 + 14) / 4 = 6.25

APPROACH:
1. Sort the burst times in ascending order.
2. Initialize two variables, `sum` and `diff`.
3. Iterate over the sorted burst times to compute the total waiting time.
4. Calculate the average waiting time by dividing `diff` by the number of processes.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int>& bt) {
    int sum = 0, diff = 0; // Initialize total sum of burst times and total waiting time difference
    sort(begin(bt), end(bt)); // Sort the burst times in ascending order
    for (auto x : bt) {
        sum += x; // Accumulate burst time
        diff += sum - x; // Calculate waiting time difference
    }
    return diff / bt.size(); // Return the average waiting time
}

/*
TIME COMPLEXITY:
- O(n log n) for sorting the burst times.
- O(n) for iterating through the burst times.

SPACE COMPLEXITY:
- O(1) additional space.

EXAMPLE USAGE:
vector<int> bt = {5, 3, 8, 6};
int result = solve(bt);
// result will be 4
*/
