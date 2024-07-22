// Question: Nearly Sorted Array
// Given an array of n elements, where each element is at most k positions away 
// from its target position, sort the array.

// Example:
// Input: arr[] = {6, 5, 3, 2, 8, 10, 9}, k = 3
// Output: arr[] = {2, 3, 5, 6, 8, 9, 10}

// Approach:
// 1. Use a min-heap (priority queue) to keep track of the smallest elements.
// 2. Push elements into the min-heap until its size is greater than k.
// 3. Once the heap size exceeds k, pop the smallest element and push it to the result array.
// 4. Continue this process until all elements are processed.
// 5. Finally, pop all remaining elements from the heap and append them to the result array.

#include <vector>
#include <queue>
using namespace std;

vector<int> nearlySorted(int arr[], int n, int k) {
    // Initialize a min-heap (priority queue)
    priority_queue<int, vector<int>, greater<int>> minh;
    
    // Vector to store the sorted result
    vector<int> ans;

    // Iterate through the array
    for (int i = 0; i < n; i++) {
        // Push the current element into the min-heap
        minh.push(arr[i]);

        // If the heap size exceeds k, pop the smallest element and push it to the result
        if (minh.size() > k) {
            ans.push_back(minh.top());
            minh.pop();
        }
    }

    // Pop and add remaining elements from the heap to the result
    while (minh.size() > 0) {
        ans.push_back(minh.top());
        minh.pop();
    }

    // Return the sorted array
    return ans;
}

// Time Complexity: O(n log k)
// Space Complexity: O(k)