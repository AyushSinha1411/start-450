/*
QUESTION:
Given an array of jobs where every job has a deadline and profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, so the minimum time to finish all the jobs is 1 unit. Find the maximum profit and the number of jobs done.

Example:
Input: n = 4, arr[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}}
Output: 2 70
Explanation: By performing jobs {3, 1}, the maximum profit of 70 can be achieved.

APPROACH:
1. Sort the jobs in descending order of profit.
2. Find the maximum deadline.
3. Create an array to keep track of free time slots.
4. Iterate through the sorted jobs and assign them to the latest free slot before their deadline.
5. Track the total number of jobs done and the total profit.

CODE:
*/

#include <algorithm>
#include <utility>
using namespace std;

// Structure to represent a job
struct Job {
    int id; // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution {
public:
    // Comparison function to sort jobs according to their profit in descending order
    static bool comparison(Job a, Job b) {
        return (a.profit > b.profit);
    }

    // Function to find the maximum profit and the number of jobs done
    pair<int, int> JobScheduling(Job arr[], int n) {
        // Sort the jobs according to their profit in descending order
        sort(arr, arr + n, comparison);

        // Find the maximum deadline
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }

        // Create an array to keep track of free time slots
        int slot[maxi + 1];
        for (int i = 0; i <= maxi; i++)
            slot[i] = -1;

        // Initialize variables to keep track of the number of jobs done and the total profit
        int countJobs = 0, jobProfit = 0;

        // Iterate through the sorted jobs
        for (int i = 0; i < n; i++) {
            // Find a free slot for this job (starting from the latest possible slot)
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i; // Assign the job to this slot
                    countJobs++; // Increment the count of jobs done
                    jobProfit += arr[i].profit; // Add the profit
                    break; // Break the loop as we have assigned the job
                }
            }
        }

        // Return the number of jobs done and the total profit as a pair
        return make_pair(countJobs, jobProfit);
    }
}

/*
TIME COMPLEXITY:
- O(n log n) for sorting the jobs by profit.
- O(n * d) for assigning jobs to the latest possible slot, where d is the maximum deadline.

SPACE COMPLEXITY:
- O(d) for the slot array, where d is the maximum deadline.
*/
