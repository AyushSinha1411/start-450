/*
QUESTION:
Given an array of size n, where every element is k positions away from its target position, sort the array in O(n log k) time.

Example:
Input: arr = [2, 6, 3, 12, 56, 8], k = 3
Output: [2, 3, 6, 8, 12, 56]

APPROACH:
1. Insert the first k+1 elements into a min-heap (priority_queue in C++).
2. For the rest of the elements, remove the minimum element from the heap and insert the next element from the array.
3. Continue this process until all elements are processed.
4. Extract the remaining elements from the heap to get the sorted order.

CODE:
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to sort an array which is k positions away from its target position
void sortK(int arr[], int n, int k) {
    // Insert first k+1 items into a min-heap
    int size = (n == k) ? k : k + 1;
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + size);

    // i is index for remaining elements in arr[] and index is target index for the current minimum element in the min-heap 'pq'.
    int index = 0;
    for (int i = k + 1; i < n; i++) {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    // Extract the remaining elements from the min-heap and put them back in the array
    while (!pq.empty()) {
        arr[index++] = pq.top();
        pq.pop();
    }
}

/*
TIME COMPLEXITY:
- O(n log k), where n is the number of elements in the array and k is the maximum distance an element is from its target position.
  - Inserting the first k+1 elements into the min-heap takes O(k log k) time.
  - For the remaining elements, each insert and extract operation takes O(log k) time, which is done n-k times.

SPACE COMPLEXITY:
- O(k), as the priority_queue stores k+1 elements.
*/
