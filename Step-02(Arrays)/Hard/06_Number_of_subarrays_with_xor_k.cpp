/*
QUESTION:
Given an array of integers A and an integer K, find the number of subarrays having XOR of elements as K.

Example:
Input: A = [4, 2, 2, 6, 4], K = 6
Output: 4
Explanation: The subarrays with XOR of elements as 6 are [4, 2], [2, 2, 6], [6], [4].

APPROACH:
1. Initialize variables xr (XOR of elements), cnt (count of subarrays), and an unordered_map to store prefix XOR and its occurrences.
2. Initialize xr to 0 and insert (0, 1) into the map to handle the case when the XOR of the whole array equals K.
3. Iterate through the array A.
4. Calculate the prefix XOR xr by XORing the current element with xr.
5. Calculate x = xr XOR K, which represents the desired XOR value.
6. Increment cnt by the number of occurrences of x in the map.
7. Increment the occurrence of xr in the map.
8. Return cnt, which represents the count of subarrays with XOR of elements as K.

CODE:
*/

#include <unordered_map>
#include <vector>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); // Size of the given array
    int xr = 0; // XOR of elements
    unordered_map<int, int> mpp; // Map to store prefix XOR and its occurrences
    mpp[xr]++; // Initialize with (0, 1) to handle cases where the whole array XOR equals K
    int cnt = 0; // Count of subarrays with XOR of elements as K

    for (int i = 0; i < n; i++) {
        xr ^= a[i]; // Calculate prefix XOR

        int x = xr ^ k; // Desired XOR value

        cnt += mpp[x]; // Increment cnt by the number of occurrences of x in the map

        mpp[xr]++; // Increment the occurrence of xr in the map
    }

    return cnt; // Return the count of subarrays with XOR of elements as K
}

/*
TIME COMPLEXITY: O(N), where N is the size of the array.
SPACE COMPLEXITY: O(N), as the unordered_map can store up to N distinct prefix XOR values.
*/
