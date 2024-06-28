/*
QUESTION:
Given a vector of integers, determine if it can represent the in-order traversal of a Binary Search Tree (BST). In a BST, the in-order traversal yields nodes in a strictly increasing order.

EXAMPLE:
Input: [1, 2, 3, 4, 5]
Output: true

Input: [1, 3, 2, 4, 5]
Output: false

APPROACH:
1. Iterate through the vector of integers.
2. Check if each element is greater than the previous element.
3. If all elements satisfy this condition, return true.
4. If any element is not greater than the previous element, return false.

CODE:
*/

// Function to determine if a given vector can represent the in-order traversal of a BST
bool isBSTTraversal(vector<int>& nums) {
    // Iterate through the vector, checking if each element is greater than the previous one
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i + 1] <= nums[i]) {
            return false; // Return false if any element is not greater than the previous one
        }
    }
    return true; // Return true if all elements are in strictly increasing order
}

/*
EXAMPLE USAGE:
vector<int> nums1 = {1, 2, 3, 4, 5};
bool result1 = isBSTTraversal(nums1);
// Expected output: true

vector<int> nums2 = {1, 3, 2, 4, 5};
bool result2 = isBSTTraversal(nums2);
// Expected output: false

TIME COMPLEXITY:
- O(n), where n is the number of elements in the vector. Each element is checked once.

SPACE COMPLEXITY:
- O(1), as no additional space is required except for the input vector.
*/
