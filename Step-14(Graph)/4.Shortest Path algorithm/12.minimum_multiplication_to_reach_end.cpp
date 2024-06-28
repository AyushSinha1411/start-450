/*
QUESTION:
Given an array of integers `arr`, a start integer `start`, and an end integer `end`, find the minimum number of multiplications needed to reach the `end` from `start` by only multiplying by elements in `arr`. If it's not possible to reach the end, return -1.

APPROACH:
1. Use a breadth-first search (BFS) approach to explore the minimal multiplications needed.
2. Represent each state as a pair of current value and the number of multiplications taken to reach that value.
3. Use a queue to perform BFS and a distance array to track the minimum number of multiplications needed to reach each number.
4. For each number, multiply it with every element in the array, check if the new number can be reached with fewer multiplications than previously recorded, and if so, update and push the new state to the queue.
5. If the `end` number is reached, return the number of multiplications; otherwise, return -1 if the queue is exhausted.

CODE:
*/

#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        // Create a queue for storing the numbers as a result of multiplication
        // of the numbers in the array and the start number.
        queue<pair<int, int>> q;
        q.push({start, 0});

        // Create a dist array to store the no. of multiplications to reach
        // a particular number from the start number.
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        int mod = 100000;

        // Multiply the start no. with each of numbers in the arr
        // until we get the end no.
        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto it : arr) {
                int num = (it * node) % mod;

                // If the no. of multiplications are less than before
                // in order to reach a number, we update the dist array.
                if (steps + 1 < dist[num]) {
                    dist[num] = steps + 1;

                    // Whenever we reach the end number
                    // return the calculated steps
                    if (num == end)
                        return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        // If the end no. is unattainable.
        return -1;
    }
};

/*
EXAMPLE USAGE:
Solution sol;
vector<int> arr = {2, 3, 5};
int result = sol.minimumMultiplications(arr, 1, 10);
// Output: 3 (1 -> 2 -> 4 -> 10)

TIME COMPLEXITY:
- O(N * M), where N is the size of the array and M is the number of elements considered in the BFS queue.

SPACE COMPLEXITY:
- O(100000) for the distance array and the queue.

The BFS ensures that we explore the shortest path in terms of multiplications to reach the desired number.
*/
