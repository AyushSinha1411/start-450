/*
QUESTION:
Given the root of a Binary Search Tree (BST) and a key, write a function to find the floor of the key in the BST. The floor of a key is the largest element in the BST that is smaller than or equal to the key.

EXAMPLE:
Input: root = [8, 4, 12, 2, 6, 10, 14], key = 5
Output: 4

Input: root = [8, 4, 12, 2, 6, 10, 14], key = 13
Output: 12

APPROACH:
1. Initialize a variable to store the floor value and set it to -1 initially.
2. Traverse the BST starting from the root.
3. If the current node's value is equal to the key, set the floor to the current node's value and return it.
4. If the key is greater than the current node's value, update the floor to the current node's value and move to the right subtree.
5. If the key is smaller than the current node's value, move to the left subtree.
6. Continue this process until the end of the tree is reached or the key is found.
7. Return the computed floor value.

CODE:
*/

int floorInBST(TreeNode* root, int key) {
    // Initialize the floor variable to store the floor value
    int floor = -1;
    
    // Traverse the BST until reaching the end or finding the key
    while (root) {
        // If the key is found, assign it as the floor value and return
        if (root->val == key) {
            floor = root->val;
            return floor;
        }
        
        // If the key is greater than the current node's value
        if (key > root->val) {
            // Update the floor with the current node's value and move to the right subtree
            floor = root->val;
            root = root->right;
        } else {
            // If the key is smaller than the current node's value, move to the left subtree
            root = root->left;
        }
    }
    
    // Return the computed floor value
    return floor;
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

int result = floorInBST(root, 5);
// Expected output: 4

TIME COMPLEXITY:
- O(h), where h is the height of the tree. In the worst case, h can be equal to the number of nodes (n) in a skewed tree.

SPACE COMPLEXITY:
- O(1), as no additional space is required beyond the input and a few variables.
*/
