/*
QUESTION:
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
1. 0 <= a, b, c, d < n
2. a, b, c, and d are distinct.
3. nums[a] + nums[b] + nums[c] + nums[d] == target
4. You may return the answer in any order.

Example:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

APPROACH:
1. Sort the given array nums.
2. Iterate through the array and avoid duplicates while moving the index i.
3. Inside the loop, iterate through the array again and avoid duplicates while moving the index j.
4. Use two pointers approach with two pointers, k and l, starting from j + 1 and n - 1 respectively.
5. While k < l, calculate the sum of the four elements (nums[i], nums[j], nums[k], nums[l]).
6. If the sum is equal to the target, store the quadruplet in the answer vector and skip duplicates for both k and l.
7. If the sum is less than the target, increment k.
8. If the sum is greater than the target, decrement l.
9. Continue until k < l.
10. Return the answer vector containing all unique quadruplets.

CODE:
*/

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); // Size of the array
    vector<vector<int>> ans; // Vector to store unique quadruplets

    // Sort the given array nums
    sort(nums.begin(), nums.end());

    // Calculating the quadruplets
    for (int i = 0; i < n; i++) {
        // Avoid duplicates while moving index i
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            // Avoid duplicates while moving index j
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            // Two pointers approach
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i] + nums[j] + nums[k] + nums[l]; // Calculate the sum of four elements

                if (sum == target) {
                    // If sum is equal to target, store the quadruplet in the answer vector
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;

                    // Skip duplicates for both k and l
                    while (k < l && nums[k] == nums[k - 1]) {
                        k++;
                    }
                    while (k < l && nums[l] == nums[l + 1]) {
                        l--;
                    }
                } else if (sum < target) {
                    k++; // Increment k if sum is less than target
                } else {
                    l--; // Decrement l if sum is greater than target
                }
            }
        }
    }

    return ans; // Return the answer vector containing all unique quadruplets
}

/*
TIME COMPLEXITY: O(N^3), where N is the size of the array.
SPACE COMPLEXITY: O(1) (excluding the space required for the answer vector).
*/
