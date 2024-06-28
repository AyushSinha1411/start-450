/*
QUESTION:
Find two indices in an array such that the elements at these indices add up to a given target.

Example:
Input:
n = 4
arr = [2, 7, 11, 15]
target = 9
Output:
The indices of the two numbers are: [0, 1] (because arr[0] + arr[1] = 2 + 7 = 9)

APPROACH:
1. Initialize an unordered map mpp to store the elements and their indices.
2. Iterate through the array:
   - For each element, calculate the value needed to reach the target (moreNeeded = target - num).
   - Check if moreNeeded is in the map. If it is, return the indices of moreNeeded and the current element.
   - If not, add the current element and its index to the map.
3. If no such pair is found, return [-1, -1].

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find two indices such that the elements add up to the target
vector<int> twoSum(int n, vector<int>& arr, int target) {
    unordered_map<int, int> mpp; // Map to store elements and their indices

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;

        // Check if the required number to reach the target is already in the map
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i}; // Return the indices of the two numbers
        }

        // Add the current number and its index to the map
        mpp[num] = i;
    }

    return {-1, -1}; // Return [-1, -1] if no such pair is found
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(N), due to the usage of the unordered map to store elements and their indices.
*/
