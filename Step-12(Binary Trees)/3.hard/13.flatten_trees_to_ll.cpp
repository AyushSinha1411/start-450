/*
QUESTION:
Given the root of a binary tree, flatten the tree into a "linked list":
- The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
- The "linked list" should be in the same order as a pre-order traversal of the binary tree.

EXAMPLE:
Input:
    Tree:
       1
      / \
     2   5
    / \   \
   3   4   6
Output:
    Flattened Tree: 1 -> 2 -> 3 -> 4 -> 5 -> 6

APPROACH:
1. Initialize a pointer 'curr' to the root of the tree.
2. Iterate until 'curr' becomes NULL:
    a. If the current node has a left child:
        i. Find the rightmost node in the left subtree.
        ii. Connect the rightmost node in the left subtree to the current node's right child.
        iii. Move the entire left subtree to the right child of the current node.
        iv. Set the left child of the current node to NULL.
    b. Move to the next node on the right side.
3. The tree will be flattened to a linked list in-place.

CODE:
*/

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to flatten a binary tree to a right next Linked List structure
void flatten(TreeNode* root) {
    // Initialize a pointer 'curr' to the root of the tree
    TreeNode* curr = root;

    // Iterate until 'curr' becomes NULL
    while (curr) {
        // Check if the current node has a left child
        if (curr->left) {
            // If yes, find the rightmost node in the left subtree
            TreeNode* pre = curr->left;
            while (pre->right) {
                pre = pre->right;
            }

            // Connect the rightmost node in the left subtree to the current node's right child
            pre->right = curr->right;

            // Move the entire left subtree to the right child of the current node
            curr->right = curr->left;

            // Set the left child of the current node to NULL
            curr->left = NULL;
        }

        // Move to the next node on the right side
        curr = curr->right;
    }
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(5);
root->left->left = new TreeNode(3);
root->left->right = new TreeNode(4);
root->right->right = new TreeNode(6);

flatten(root);

TreeNode* curr = root;
while (curr) {
    cout << curr->val << " ";
    curr = curr->right;
}
// Expected output: 1 2 3 4 5 6

TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Each node is visited once.

SPACE COMPLEXITY:
- O(1), since the tree is flattened in-place without using additional space.
*/
