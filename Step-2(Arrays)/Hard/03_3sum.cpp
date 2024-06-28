/*
QUESTION:
Given an array of distinct integers and an integer n, find all unique triplets in the array which gives the sum of zero.

Example:
Input:
n = 6
arr = [-1, 0, 1, 2, -1, -4]
Output:
The unique triplets that sum up to zero are: [[-1, -1, 2], [-1, 0, 1]]

APPROACH:
1. Sort the array to easily handle duplicates and efficiently move pointers.
2. Iterate through the array.
3. Inside the loop, check if the current element is a duplicate, and if so, skip it.
4. Use two pointers approach with one pointer starting from the element next to the current element (j) and the other from the end of the array (k).
5. While j < k, calculate the sum of the three elements.
6. If the sum is less than zero, increment j.
7. If the sum is greater than zero, decrement k.
8. If the sum is zero, store the triplet in the answer vector and skip duplicates for both j and k.
9. Continue until j < k.
10. Return the answer vector containing all unique triplets.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> triplet(int n, vector<int>& arr) {
    vector<vector<int>> ans; // Vector to store unique triplets
    sort(arr.begin(), arr.end()); // Sort the array

    for (int i = 0; i < n; i++) {
        // Remove duplicates
        if (i != 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int j = i + 1; // Pointer j starts from the element next to the current element
        int k = n - 1; // Pointer k starts from the end of the array

        // Two pointers approach
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k]; // Calculate the sum of three elements

            if (sum < 0) {
                j++; // Increment j if sum is less than zero
            } else if (sum > 0) {
                k--; // Decrement k if sum is greater than zero
            } else {
                // If sum is zero, store the triplet in the answer vector
                ans.push_back({arr[i], arr[j], arr[k]});
                j++; // Increment j
                k--; // Decrement k
                // Skip duplicates for both j and k
                while (j < k && arr[j] == arr[j - 1]) {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1]) {
                    k--;
                }
            }
        }
    }
    return ans; // Return the answer vector containing all unique triplets
}

/*
TIME COMPLEXITY: O(N^2), where N is the size of the array.
SPACE COMPLEXITY: O(1) (excluding the space required for the answer vector).
*/
