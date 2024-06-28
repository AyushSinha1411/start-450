/*
QUESTION:
Given the root of a Binary Search Tree (BST) and an integer value, write a function to search for a node in the BST that contains this value. If such a node exists, return the node. Otherwise, return NULL.

EXAMPLE:
Input: root = [4, 2, 7, 1, 3], val = 2
Output: Node with value 2

Input: root = [4, 2, 7, 1, 3], val = 5
Output: NULL

APPROACH:
1. Start at the root of the BST.
2. Loop until either the current node is NULL or the value of the current node equals the target value.
3. If the target value is less than the current node's value, move to the left child.
4. If the target value is greater than the current node's value, move to the right child.
5. If the current node's value equals the target value, return the current node.
6. If the loop ends without finding the target value, return NULL.

CODE:
*/

// Function to search for a node with a specified value in a Binary Search Tree (BST).
TreeNode* searchBST(TreeNode* root, int val) {
    // Loop until either the tree is exhausted (NULL) or the value is found.
    while (root != NULL && root->val != val) {
        // Check if the target value is less than the current node's value.
        // If so, move to the left subtree (values smaller than the current node).
        // Otherwise, move to the right subtree (values larger than the current node).
        root = val < root->val ? root->left : root->right;
    }
    // Return the node containing the target value, if found; otherwise, return NULL.
    return root;
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(4);
root->left = new TreeNode(2);
root->right = new TreeNode(7);
root->left->left = new TreeNode(1);
root->left->right = new TreeNode(3);

TreeNode* result1 = searchBST(root, 2);
// Expected output: Node with value 2

TreeNode* result2 = searchBST(root, 5);
// Expected output: NULL

TIME COMPLEXITY:
- O(h), where h is the height of the tree. In the worst case, h can be equal to the number of nodes (n) in a skewed tree.

SPACE COMPLEXITY:
- O(1), as no additional space is required beyond the input and a few variables.
*/
