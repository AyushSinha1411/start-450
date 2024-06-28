/*
QUESTION:
Given the root of a Binary Search Tree (BST) and a value to be inserted into the BST, write a function to insert the value into the BST and return the root of the modified BST. It is guaranteed that the new value does not exist in the original BST.

EXAMPLE:
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]

Input: root = [], val = 5
Output: [5]

APPROACH:
1. If the root is NULL, create a new TreeNode with the given value and return it as the new root.
2. Initialize a pointer 'cur' to traverse the tree starting from the root.
3. Traverse the tree to find the appropriate position for the new value:
   - If the current node's value is less than or equal to the value to be inserted, move to the right subtree.
     - If the right child is NULL, create a new node with the given value as the right child and break the loop.
     - Otherwise, update 'cur' to the right child and continue.
   - If the current node's value is greater than the value to be inserted, move to the left subtree.
     - If the left child is NULL, create a new node with the given value as the left child and break the loop.
     - Otherwise, update 'cur' to the left child and continue.
4. Return the root of the modified tree after insertion.

CODE:
*/

TreeNode* insertIntoBST(TreeNode* root, int val) {
    // If the root node is NULL, create a new node
    // with the given value and return it as the new root.
    if (root == NULL) {
        return new TreeNode(val);
    }

    // Pointer to traverse the tree.
    TreeNode* cur = root;

    // Traverse the tree to find the appropriate position for insertion.
    while (true) {
        // If the current node's value is less than or equal to the value to be inserted,
        // move to the right subtree.
        if (cur->val <= val) {
            // If the right child of the current node is not NULL, update 'cur' to the right child.
            if (cur->right != NULL) {
                cur = cur->right;
            }
            // If the right child is NULL, create a new node with the given value as the right child
            // and exit the loop.
            else {
                cur->right = new TreeNode(val);
                break;
            }
        }
        // If the current node's value is greater than the value to be inserted,
        // move to the left subtree.
        else {
            // If the left child of the current node is not NULL, update 'cur' to the left child.
            if (cur->left != NULL) {
                cur = cur->left;
            }
            // If the left child is NULL, create a new node with the given value as the left child
            // and exit the loop.
            else {
                cur->left = new TreeNode(val);
                break;
            }
        }
    }
    // Return the root of the modified tree after insertion.
    return root;
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(4);
root->left = new TreeNode(2);
root->right = new TreeNode(7);
root->left->left = new TreeNode(1);
root->left->right = new TreeNode(3);

int val = 5;
TreeNode* result = insertIntoBST(root, val);
// Expected output: [4, 2, 7, 1, 3, 5]

TIME COMPLEXITY:
- O(h), where h is the height of the tree. In the worst case, h can be equal to the number of nodes (n) in a skewed tree.

SPACE COMPLEXITY:
- O(1), as no additional space is required beyond the input and a few variables.
*/
