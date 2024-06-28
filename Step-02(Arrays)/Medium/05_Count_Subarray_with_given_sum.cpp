/*
QUESTION:
Given an array of integers and an integer k, find the total number of continuous subarrays whose sum equals to k.

Example:
Input:
arr = [1, 1, 1], k = 2
Output:
The total number of continuous subarrays with sum equal to k is: 2

APPROACH:
1. Initialize a map mpp to store prefix sums and their frequencies.
2. Initialize variables preSum to store the prefix sum, cnt to store the count of subarrays with sum equal to k, and set mpp[0] = 1.
3. Iterate through the array and update the prefix sum by adding each element.
4. Calculate the value of x - k, where x is the current prefix sum.
5. Increment cnt by the frequency of the prefix sum (x - k) stored in the map.
6. Update the frequency of the current prefix sum in the map.
7. Return cnt, which contains the total number of continuous subarrays with sum equal to k.

CODE:
*/

#include <vector>
#include <unordered_map>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int>& arr, int k) {
    int n = arr.size(); // Size of the given array
    unordered_map<int, int> mpp; // Map to store prefix sums and their frequencies
    int preSum = 0, cnt = 0; // Variables to store prefix sum and count of subarrays

    mpp[0] = 1; // Setting 0 in the map
    for (int i = 0; i < n; i++) {
        // Add current element to prefix sum
        preSum += arr[i];
        // Calculate x - k
        int remove = preSum - k;
        // Add the number of subarrays to be removed
        cnt += mpp[remove];
        // Update the count of prefix sum in the map
        mpp[preSum] += 1;
    }
    return cnt; // Return the total number of continuous subarrays with sum equal to k
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(N), as extra space is used for the map.
*/
