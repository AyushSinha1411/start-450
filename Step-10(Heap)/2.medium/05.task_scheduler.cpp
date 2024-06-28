/*
QUESTION:
Given a list of tasks and an integer n representing the cooldown period, return the least number of units of times that the CPU will take to finish all the given tasks. Tasks can be done in any order and each task is represented by a character.

Example:
Input:
tasks = ['A', 'A', 'A', 'B', 'B', 'B'], n = 2
Output:
8
Explanation:
A -> B -> idle -> A -> B -> idle -> A -> B

APPROACH:
1. Build a frequency map of the tasks.
2. Use a max heap to store the frequencies.
3. Process tasks until the heap is empty, handling the cooldown period.
4. Calculate the total time taken to complete all tasks.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    // Building frequency map
    int freq[26] = {0};
    for (char &ch : tasks) {
        freq[ch - 'A']++;
    }

    // Max heap to store frequencies
    priority_queue<int> pq;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            pq.push(freq[i]);
        }
    }

    int time = 0;
    // Process tasks until the heap is empty
    while (!pq.empty()) {
        int cycle = n + 1;
        vector<int> store;
        int taskCount = 0;
        // Execute tasks in each cycle
        while (cycle-- && !pq.empty()) {
            if (pq.top() > 1) {
                store.push_back(pq.top() - 1);
            }
            pq.pop();
            taskCount++;
        }
        // Restore updated frequencies to the heap
        for (int &x : store) {
            pq.push(x);
        }
        // Add time for the completed cycle
        time += (pq.empty() ? taskCount : n + 1);
    }
    return time;
}

/*
TIME COMPLEXITY:
- O(T log T), where T is the number of unique tasks. 
  - Building the frequency map takes O(T) time.
  - Processing tasks using the priority queue takes O(T log T) time.

SPACE COMPLEXITY:
- O(T), for storing the frequency map and the priority queue.
*/
