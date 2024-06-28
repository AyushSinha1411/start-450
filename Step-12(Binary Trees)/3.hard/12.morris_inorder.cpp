/*
QUESTION:
Write a function to perform Morris inorder traversal on a binary tree. This method should traverse the tree without using recursion or a stack.

EXAMPLE:
Input:
    Tree:
       1
      / \
     2   3
    / \
   4   5
Output:
    Inorder Traversal: [4, 2, 5, 1, 3]

APPROACH:
1. Initialize the current node as the root.
2. While the current node is not NULL:
    a. If the current node's left child is NULL:
        i. Add the value of the current node to the inorder vector.
        ii. Move to the right child of the current node.
    b. If the current node's left child is not NULL:
        i. Find the predecessor (rightmost node in the left subtree).
        ii. If the predecessor's right child is NULL:
            - Establish a temporary link from the predecessor's right child to the current node.
            - Move to the left child of the current node.
        iii. If the predecessor's right child is already linked to the current node:
            - Remove the temporary link.
            - Add the value of the current node to the inorder vector.
            - Move to the right child of the current node.
3. Return the inorder traversal vector.

CODE:
*/

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform iterative Morris inorder traversal of a binary tree
vector<int> getInorder(TreeNode* root) {
    // Vector to store the inorder traversal result
    vector<int> inorder;
    // Pointer to the current node, starting from the root
    TreeNode* cur = root;
    
    // Loop until the current node is not NULL
    while (cur != NULL) {
        // If the current node's left child is NULL
        if (cur->left == NULL) {
            // Add the value of the current node to the inorder vector
            inorder.push_back(cur->val);
            // Move to the right child
            cur = cur->right;
        } else {
            // If the left child is not NULL, find the predecessor (rightmost node in the left subtree)
            TreeNode* prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }
            
            // If the predecessor's right child is NULL, establish a temporary link and move to the left child
            if (prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            } else {
                // If the predecessor's right child is already linked, remove the link, add current node to inorder vector,
                // and move to the right child
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    
    // Return the inorder traversal result
    return inorder;
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);

vector<int> result = getInorder(root);

for (int val : result) {
    cout << val << " ";
}
// Expected output: 4 2 5 1 3

TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Each node is visited at most twice.

SPACE COMPLEXITY:
- O(1), since no additional space is used other than a few pointers, making it an efficient traversal method.
*/
