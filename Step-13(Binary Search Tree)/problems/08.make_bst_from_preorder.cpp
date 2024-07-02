/*
QUESTION:
Given an array that represents preorder traversal of a binary search tree (BST), construct the BST from the given preorder traversal array.

EXAMPLE:
Input: preorder = [10, 5, 1, 7, 40, 50]
Output: BST constructed from the given preorder traversal.

APPROACH:
1. Initialize the current index in the preorder array to 0.
2. Use a recursive helper function to construct the BST.
3. The helper function uses the min and max constraints to ensure that the nodes are placed correctly in the BST.
4. If the current key is within the min and max range, create a new node.
5. Recursively construct the left and right subtrees with updated constraints.

CODE:
*/

class Solution {
public:
    // Function to create a BST from preorder traversal
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0; // Initialize index to 0
        return build(A, i, INT_MAX); // Call the build function with the preorder vector, index, and initial bound
    }

    // Recursive function to build the BST
    TreeNode* build(vector<int>& A, int& i, int bound) {
        // Base case: if index reaches the end of the array or the current value exceeds the bound
        if (i == A.size() || A[i] > bound) return NULL;

        // Create a new node with the current value and increment the index
        TreeNode* root = new TreeNode(A[i++]);

        // Recursively build the left subtree with the current value as the new bound
        root->left = build(A, i, root->val);

        // Recursively build the right subtree with the current bound
        root->right = build(A, i, bound);

        return root; // Return the constructed subtree
    }
};


/*
EXAMPLE USAGE:
vector<int> preorder = {10, 5, 1, 7, 40, 50};
TreeNode* root = bstFromPreorder(preorder);

// The constructed BST from the given preorder traversal
// would look like:
//        10
//       /  \
//      5    40
//     / \     \
//    1   7    50

TIME COMPLEXITY:
- O(n), where n is the number of nodes in the BST. Each node is visited once.

SPACE COMPLEXITY:
- O(n), where n is the number of nodes in the BST. This accounts for the space used by the recursion stack.
*/
