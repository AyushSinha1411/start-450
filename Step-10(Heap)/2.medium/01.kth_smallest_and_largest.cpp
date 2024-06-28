/*
QUESTION:
Write functions to find the k-th largest and k-th smallest elements in an array using max-heap and min-heap respectively. The functions should print the k-th largest and k-th smallest elements.

Example:
Input: arr = [3, 2, 1, 5, 6, 4], k = 2
Output: Kth Largest element 5
        Kth Smallest element 2

APPROACH:
1. `kth_Largest_MaxHeap` function:
   - Use a max-heap (priority_queue in C++) to store all elements.
   - Extract the maximum element (k-1) times to get the k-th largest element.
2. `kth_Smallest_MinHeap` function:
   - Use a min-heap (priority_queue with greater<int> in C++) to store all elements.
   - Extract the minimum element (k-1) times to get the k-th smallest element.

CODE:
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to find k-th largest element using max-heap
void kth_Largest_MaxHeap(vector<int>& arr, int k) {
    priority_queue<int> pq;
    int n = arr.size();

    // Push all elements into the max-heap
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
    }

    // Remove the largest element (k-1) times
    int f = k - 1;
    while (f > 0) {
        pq.pop();
        f--;
    }

    // The top element is the k-th largest element
    cout << "Kth Largest element " << pq.top() << "\n";
}

// Function to find k-th smallest element using min-heap
void kth_Smallest_MinHeap(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = arr.size();

    // Push all elements into the min-heap
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
    }

    // Remove the smallest element (k-1) times
    int f = k - 1;
    while (f > 0) {
        pq.pop();
        f--;
    }

    // The top element is the k-th smallest element
    cout << "Kth Smallest element " << pq.top() << "\n";
}

/*
TIME COMPLEXITY:
- Both functions: O(N log N), where N is the number of elements in the array.
  - Insertion into the priority_queue takes O(log N) time and we do it N times.
  - Extracting the top element k times takes O(k log N) time.

SPACE COMPLEXITY:
- Both functions: O(N) for storing the elements in the priority_queue.
*/
