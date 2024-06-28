/*
QUESTION:
Given a binary tree, write a function to determine if it is a valid binary search tree (BST). A valid BST is defined as follows:
- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

EXAMPLE:
Input: [2,1,3]
Output: true

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

APPROACH:
1. Use a helper function to recursively validate the BST property.
2. Pass the minimum and maximum values allowed for each node as arguments.
3. For each node, check if its value violates the BST property.
4. Recursively validate the left and right subtrees with updated constraints.

CODE:
*/

// Function to check if a given binary
// tree is a valid binary search tree (BST)
bool isValid(TreeNode* root) {
    // Calls the helper function isValidBST
    // with initial min and max values
    return isValidBST(root, LONG_MIN, LONG_MAX); 
}

// Helper function to recursively validate the BST property
bool isValidBST(TreeNode* root, long minVal, long maxVal) {
    if (root == nullptr) {
        // Base case: an empty
        // tree is a valid BST
        return true; 
    }
    
    // Checks if the current node
    // violates the BST property
    if (root->val >= maxVal || root->val <= minVal) {
        return false; 
    }

    // Recursively checks left and right
    // subtrees with updated constraints
    // that every value on its left subtree
    // should be smaller than the current node
    // and every value on its right subtree
    // should be greater than the current node
    return isValidBST(root->left, minVal, root->val)
            && isValidBST(root->right, root->val, maxVal);
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(2);
root->left = new TreeNode(1);
root->right = new TreeNode(3);

bool result = isValid(root);
// Expected output: true

TreeNode* root2 = new TreeNode(5);
root2->left = new TreeNode(1);
root2->right = new TreeNode(4);
root2->right->left = new TreeNode(3);
root2->right->right = new TreeNode(6);

bool result2 = isValid(root2);
// Expected output: false

TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree, since we visit each node exactly once.

SPACE COMPLEXITY:
- O(h), where h is the height of the tree, due to the recursive call stack.
*/
