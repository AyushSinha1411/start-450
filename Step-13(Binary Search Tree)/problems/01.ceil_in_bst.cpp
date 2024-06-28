/*
QUESTION:
Given the root of a Binary Search Tree (BST) and a key, write a function to find the ceiling of the key in the BST. The ceiling of a key is the smallest element in the BST that is greater than or equal to the key.

EXAMPLE:
Input: root = [8, 4, 12, 2, 6, 10, 14], key = 5
Output: 6

Input: root = [8, 4, 12, 2, 6, 10, 14], key = 13
Output: 14

APPROACH:
1. Initialize a variable to store the ceiling value and set it to -1 initially.
2. Traverse the BST starting from the root.
3. If the current node's value is equal to the key, set the ceiling to the current node's value and return it.
4. If the key is greater than the current node's value, move to the right subtree.
5. If the key is smaller than the current node's value, update the ceiling to the current node's value and move to the left subtree.
6. Continue this process until the end of the tree is reached or the key is found.
7. Return the computed ceiling value.

CODE:
*/

int findCeil(TreeNode* root, int key) {
    // Initialize the variable to store the ceiling value
    int ceil = -1; 
    
    // Traverse the BST until reaching the end or finding the key
    while (root) {
        // If the key is found, assign it as the ceiling and return
        if (root->val == key) {
            ceil = root->val;
            return ceil;
        } 
        
        // If the key is greater, move to the right subtree
        if (key > root->val) {
            root = root->right;
        } else {
            // If the key is smaller, update ceil and move to the left subtree
            ceil = root->val;
            root = root->left;
        }
    }
    
    // Return the computed ceiling value
    return ceil;
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(8);
root->left = new TreeNode(4);
root->right = new TreeNode(12);
root->left->left = new TreeNode(2);
root->left->right = new TreeNode(6);
root->right->left = new TreeNode(10);
root->right->right = new TreeNode(14);

int result = findCeil(root, 5);
// Expected output: 6

TIME COMPLEXITY:
- O(h), where h is the height of the tree. In the worst case, h can be equal to the number of nodes (n) in a skewed tree.

SPACE COMPLEXITY:
- O(1), as no additional space is required beyond the input and a few variables.
*/
