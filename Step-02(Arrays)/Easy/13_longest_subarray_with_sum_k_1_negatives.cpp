/*
QUESTION:
Find the length of the longest subarray with a sum equal to k using a prefix sum approach for both positive and negative.

Example:
Input:
a = [1, -1, 5, -2, 3], k = 3
Output:
The length of the longest subarray is: 4 (subarray [1, -1, 5, -2])

APPROACH:
1. Initialize a map preSumMap to store the first occurrence of each prefix sum.
2. Initialize sum to 0 to store the prefix sum and maxLen to 0 to store the maximum length of the subarray with sum equal to k.
3. Iterate through the array:
   - Calculate the prefix sum till the current index i.
   - If the prefix sum is equal to k, update maxLen to i + 1.
   - Calculate the remaining sum (rem = sum - k).
   - If rem is found in the map, calculate the length of the current subarray (i - preSumMap[rem]) and update maxLen if this length is greater.
   - Update the map with the current prefix sum and index if this prefix sum is not already in the map.
4. Return maxLen, which contains the length of the longest subarray with sum equal to k.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest subarray with sum equal to k
int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // Size of the array

    map<int, int> preSumMap; // Map to store the first occurrence of each prefix sum
    int sum = 0; // Initialize prefix sum
    int maxLen = 0; // Initialize maximum length of subarray with sum equal to k

    for (int i = 0; i < n; i++) {
        // Calculate the prefix sum till index i
        sum += a[i];

        // If the prefix sum is equal to k, update maxLen
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // Calculate the remaining sum (sum - k)
        int rem = sum - k;

        // If the remaining sum is found in the map, calculate the length of the current subarray and update maxLen
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // Update the map with the current prefix sum and index if this prefix sum is not already in the map
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen; // Return the maximum length of subarray with sum equal to k
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(N), due to the usage of the map to store prefix sums.
*/
