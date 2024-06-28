/*
QUESTION:
Given an array of integers, find all the leaders in the array. An element is called a leader if it is greater than all the elements to its right side.

Example:
Input:
arr = [16, 17, 4, 3, 5, 2]
Output:
The leaders in the array are: [17, 5, 2]

APPROACH:
1. Initialize an empty vector to store the leaders.
2. Traverse the array from right to left.
3. The last element of the array is always a leader, so push it into the ans vector.
4. Initialize a variable max to keep track of the maximum number encountered from the right side.
5. Traverse the array from second last element to the first:
   - If the current element is greater than max, it is a leader. Push it into the ans vector and update max.
6. Return the ans vector containing all the leaders.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to print all the leaders in the array
vector<int> printLeaders(int arr[], int n) {
    vector<int> ans; // Vector to store leaders
    int max = arr[n - 1]; // Initialize max with the last element of the array
    ans.push_back(arr[n - 1]); // Last element is always a leader

    // Traverse the array from second last element to the first
    for (int i = n - 2; i >= 0; i--) {
        // If current element is greater than max, it is a leader
        if (arr[i] > max) {
            ans.push_back(arr[i]); // Push the leader into the ans vector
            max = arr[i]; // Update max
        }
    }

    return ans; // Return the vector containing all the leaders
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(N), as extra space is used for storing leaders.
*/
