/*
QUESTION:
Given a Binary Search Tree (BST) and a node 'p', find the inorder successor of that node in the BST. The inorder successor of a node 'p' in a BST is the node with the smallest key greater than 'p.val'.

EXAMPLE:
Input: root = [2,1,3], p = 1
Output: 2
Explanation: The inorder successor of 1 is 2.

APPROACH:
1. Initialize a variable 'successor' to null.
2. Traverse the tree starting from the root.
3. If the value of node 'p' is greater than or equal to the value of the current node, move to the right subtree.
4. If the value of node 'p' is less than the value of the current node, update 'successor' to the current node and move to the left subtree.
5. Continue this process until the end of the tree is reached.
6. Return the 'successor'.

CODE:
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the inorder successor of a node in a BST
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    // Initialize the successor to null
    TreeNode* successor = nullptr;
    
    // Traverse the tree starting from the root
    while (root != nullptr) {
        // If the value of 'p' is greater than or equal to the current node's value
        if (p->val >= root->val) {
            // Move to the right subtree
            root = root->right;
        } else {
            // Update the successor to the current node
            successor = root;
            // Move to the left subtree
            root = root->left;
        }
    }
    
    // Return the inorder successor
    return successor;
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(2);
root->left = new TreeNode(1);
root->right = new TreeNode(3);
TreeNode* p = root->left;

TreeNode* successor = inorderSuccessor(root, p);
// The inorder successor of node with value 1 is the node with value 2.

TIME COMPLEXITY:
- O(h), where h is the height of the tree. In the worst case, this can be O(n) if the tree is skewed.

SPACE COMPLEXITY:
- O(1), as no additional space other than a few pointers is used.
*/
