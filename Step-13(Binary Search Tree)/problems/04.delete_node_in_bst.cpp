/*
QUESTION:
Given the root of a binary search tree (BST) and a key, write a function to delete the node with the given key in the BST and return the root node of the modified BST. Ensure that the BST properties are maintained after deletion.

EXAMPLE:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]

APPROACH:
1. If the root is NULL, return NULL.
2. If the root node has the key to be deleted, use a helper function to delete the node and return the new root.
3. Create a dummy node pointing to the root.
4. Traverse the tree to find the node with the given key:
   - If the key is in the left subtree and the left child's value matches the key, delete the node using the helper function.
   - If the key is in the right subtree and the right child's value matches the key, delete the node using the helper function.
   - Continue traversing the tree based on the value of the key.
5. Return the modified tree.
6. The helper function deletes the node and returns the new subtree root:
   - If the node has no left child, return the right child.
   - If the node has no right child, return the left child.
   - If both children exist, store the right child, find the last right node in the left subtree, set its right child to the stored right child, and return the left child as the new subtree root.

CODE:
*/

TreeNode* deleteNode(TreeNode* root, int key) {
    // Check if the root is empty
    if (root == NULL) {
        // Return null if the root is empty
        return NULL; 
    }
    
    // If the current root node has the key to be deleted
    if (root->val == key) {
        // Delete the node using the helper function
        return helper(root); 
    }
    
    // Create a dummy node pointing to the root
    TreeNode* dummy = root;
    // While loop to traverse the tree
    while (root != NULL) {
        // If the value to be deleted
        // is in the left subtree
        if (root->val > key) {
            // If the left child exists and
            // its value matches the key
            if (root->left != NULL && root->left->val == key) {
                // Delete the node using the helper function
                root->left = helper(root->left); 
                break;
            } else {
                // Move to the left subtree
                root = root->left;
            }
        // If the value to be deleted
        // is in the right subtree
        } else {
            // If the right child exists and
            // its value matches the key
            if (root->right != NULL && root->right->val == key) {
                // Delete the node using the helper function
                root->right = helper(root->right);
                break;
            } else {
                // Move to the right subtree
                root = root->right; 
            }
        }
    }
    
    // Return the modified tree
    return dummy; 
}

// Helper function to delete the node
TreeNode* helper(TreeNode* root) {
    // If the left child of the root is null,
    // return the right child
    if (root->left == NULL) {
        return root->right;
    } else if (root->right == NULL) { 
        // If the right child is null,
        // return the left child
        return root->left;
    }
    
    // If both left and right children exist
    // Store the right child
    TreeNode* rightChild = root->right; 
    
    // Find the last right child of the left subtree
    TreeNode* lastRight = findLastRight(root->left);
    
    // Set the right child of the last
    // right node to the stored right child
    lastRight->right = rightChild; 
    
    // Return the left child as the new subtree
    return root->left; 
}

// Helper function to find the
// last right node in a subtree
TreeNode* findLastRight(TreeNode* root) {
    // Traverse to the rightmost node in the subtree
    if (root->right == NULL) {
        // Return the rightmost node
        return root; 
    }
    // Recursively find the last right node
    return findLastRight(root->right); 
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(5);
root->left = new TreeNode(3);
root->right = new TreeNode(6);
root->left->left = new TreeNode(2);
root->left->right = new TreeNode(4);
root->right->right = new TreeNode(7);

int key = 3;
TreeNode* result = deleteNode(root, key);
// Expected output: [5, 4, 6, 2, null, null, 7]

TIME COMPLEXITY:
- O(h), where h is the height of the tree. In the worst case, h can be equal to the number of nodes (n) in a skewed tree.

SPACE COMPLEXITY:
- O(h) due to the recursive calls on the stack, which can be at most the height of the tree.
*/
