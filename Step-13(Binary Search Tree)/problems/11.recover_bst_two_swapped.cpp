/*
QUESTION:
Recover a Binary Search Tree (BST) where two nodes have been swapped by mistake. The task is to correct the BST by swapping back the two nodes without changing the structure of the tree.

EXAMPLE:
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: The node values 1 and 3 are swapped by mistake.

APPROACH:
1. Use Morris Traversal to achieve O(1) space complexity.
2. Identify the two nodes that are swapped by mistake by maintaining pointers during the traversal.
3. Swap the values of the identified nodes to correct the BST.

CODE:
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to recover a Binary Search Tree where two nodes have been swapped
void recoverTree(TreeNode* root) {
    // Pointers to track the nodes to be swapped
    TreeNode *x = nullptr, *y = nullptr, *pred = nullptr, *predecessor = nullptr;

    // Use Morris Traversal to traverse the tree in-order
    while (root != nullptr) {
        // If there is a left child, find the predecessor
        if (root->left != nullptr) {
            predecessor = root->left;
            while (predecessor->right != nullptr && predecessor->right != root) {
                predecessor = predecessor->right;
            }

            // Set the right child of the predecessor to the current root
            if (predecessor->right == nullptr) {
                predecessor->right = root;
                root = root->left;
            }
            // If the link already exists, break it and check for swapped nodes
            else {
                // Check for swapped nodes
                if (pred != nullptr && root->val < pred->val) {
                    y = root;
                    if (x == nullptr) x = pred;
                }
                pred = root;
                predecessor->right = nullptr;
                root = root->right;
            }
        }
        // If there is no left child, just go right
        else {
            // Check for swapped nodes
            if (pred != nullptr && root->val < pred->val) {
                y = root;
                if (x == nullptr) x = pred;
            }
            pred = root;
            root = root->right;
        }
    }
    // Swap the values of the two identified nodes
    swap(x->val, y->val);
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(3);
root->left = new TreeNode(1);
root->right = new TreeNode(4);
root->right->left = new TreeNode(2);

recoverTree(root); // Corrects the BST

TIME COMPLEXITY:
- O(n), where n is the number of nodes in the BST. Each node is processed at most twice.

SPACE COMPLEXITY:
- O(1), using Morris Traversal, we achieve constant space complexity for the traversal.
*/
