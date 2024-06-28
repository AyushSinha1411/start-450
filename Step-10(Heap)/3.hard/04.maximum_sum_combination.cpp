/*
QUESTION:
Given two integer arrays A and B of size N, find the maximum K valid sum combinations from all the possible sum combinations of the elements in the arrays A and B.

Example:
Input:
A = [3, 2, 4, 2]
B = [4, 3, 1, 2]
K = 3

Output:
[8, 8, 7]

APPROACH:
1. Sort both arrays in ascending order.
2. Use a max-heap to keep track of the largest sums.
3. Use a set to avoid processing the same pair of indices.
4. Start with the largest elements in both arrays and push their sum into the heap.
5. Extract the largest sum from the heap and then consider the next possible pairs.
6. Continue this process until we have found K largest sums.

CODE:
*/

#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
    // Sorting both arrays in ascending order.
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ans;

    // Creating a priority queue to store maximum sums of combinations.
    priority_queue<pair<int, pair<int, int>>> pq;

    // Creating a set to store visited combinations.
    set<pair<int, int>> my_set;

    // Pushing the maximum sum of combinations obtained from last elements
    // of both arrays along with their indices.
    pq.push(make_pair(A[N - 1] + B[N - 1], make_pair(N - 1, N - 1)));

    // Inserting the indices of last elements in set.
    my_set.insert(make_pair(N - 1, N - 1));

    // Iterating K times to find K maximum sum combinations.
    for (int count = 0; count < K; count++) {
        // Popping the maximum sum from priority queue.
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();

        // Storing the maximum sum in the answer array.
        ans.push_back(temp.first);

        // Getting the indices of the elements used to get the maximum sum.
        int i = temp.second.first;
        int j = temp.second.second;

        // Checking if it is possible to consider the next element
        // from A array and calculating the sum.
        if (i - 1 >= 0) {
            int sum = A[i - 1] + B[j];

            // Creating a pair to store the indices.
            pair<int, int> temp1 = make_pair(i - 1, j);

            // Checking if the pair already exists in the set.
            if (my_set.find(temp1) == my_set.end()) {
                // If not, pushing the sum and indices to priority queue
                // and inserting the indices in set.
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
        }

        // Checking if it is possible to consider the next element
        // from B array and calculating the sum.
        if (j - 1 >= 0) {
            int sum = A[i] + B[j - 1];

            // Creating a pair to store the indices.
            pair<int, int> temp1 = make_pair(i, j - 1);

            // Checking if the pair already exists in the set.
            if (my_set.find(temp1) == my_set.end()) {
                // If not, pushing the sum and indices to priority queue
                // and inserting the indices in set.
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
        }
    }
    
    // Returning the answer array containing the maximum sum combinations.
    return ans;
}

/*
TIME COMPLEXITY:
- Sorting both arrays takes O(N log N).
- Inserting elements into the priority queue and set takes O(K log K).
- The overall time complexity is O(N log N + K log K).

SPACE COMPLEXITY:
- The space complexity is O(N + K) for storing the priority queue and set.
*/
