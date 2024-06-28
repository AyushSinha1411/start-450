/*
QUESTION:
Write a function to perform Morris preorder traversal on a binary tree. This method should traverse the tree without using recursion or a stack.

EXAMPLE:
Input:
    Tree:
       1
      / \
     2   3
        / \
       4   5
Output:
    Preorder Traversal: [1, 2, 3, 4, 5]

APPROACH:
1. Initialize the current node as the root.
2. While the current node is not NULL:
    a. If the current node has no left child:
        i. Add the value of the current node to the preorder vector.
        ii. Move to the right child of the current node.
    b. If the current node has a left child:
        i. Find the rightmost node in the left subtree or a node whose right child is not yet processed.
        ii. If the right child of the rightmost node is NULL:
            - Set the right child of the rightmost node to the current node.
            - Move to the left child of the current node.
        iii. If the right child of the rightmost node is not NULL:
            - Reset the right child to NULL.
            - Add the value of the current node to the preorder vector.
            - Move to the right child of the current node.
3. Return the preorder traversal vector.

CODE:
*/

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform iterative Morris preorder traversal of a binary tree
vector<int> getPreorder(TreeNode* root) {
    // Vector to store the preorder traversal result
    vector<int> preorder;
    
    // Pointer to the current node, starting with the root
    TreeNode* cur = root;

    // Iterate until the current node becomes NULL
    while (cur != NULL) {
        // If the current node has no left child
        if (cur->left == NULL) {
            // Add the value of the current node to the preorder vector
            preorder.push_back(cur->val);
            
            // Move to the right child
            cur = cur->right;
        } else {
            // If the current node has a left child
            // Create a pointer to traverse to the rightmost node in the left subtree
            TreeNode* prev = cur->left;
            
            // Traverse to the rightmost node in the left subtree or until we find a node 
            // whose right child is not yet processed
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }
            
            // If the right child of the rightmost node is NULL
            if (prev->right == NULL) {
                // Set the right child of the rightmost node to the current node
                prev->right = cur;
                
                // Add the value of the current node to the preorder vector
                preorder.push_back(cur->val);

                // Move to the left child
                cur = cur->left;
            } else {
                // If the right child of the rightmost node is not NULL
                // Reset the right child to NULL
                prev->right = NULL;
                
                // Move to the right child
                cur = cur->right;
            }
        }
    }
    
    // Return the resulting preorder traversal vector
    return preorder;
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->right->left = new TreeNode(4);
root->right->right = new TreeNode(5);

vector<int> result = getPreorder(root);

for (int val : result) {
    cout << val << " ";
}
// Expected output: 1 2 3 4 5

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Each node is visited at most twice.

SPACE COMPLEXITY:
- O(1), since no additional space is used other than a few pointers, making it an efficient traversal method.
*/
