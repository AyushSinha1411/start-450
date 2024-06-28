/*
QUESTION:
Find the size of the largest BST (Binary Search Tree) subtree in a binary tree.

EXAMPLE:
Input: root = [10,5,15,1,8,null,7]
Output: 3
Explanation: The largest BST subtree is [5,1,8] with size 3.

APPROACH:
1. Use a helper function to recursively determine the size of the largest BST subtree.
2. The helper function returns information about the current subtree:
   - Minimum value in the subtree
   - Maximum value in the subtree
   - Size of the largest BST subtree
3. Use these properties to determine if the current subtree is a valid BST.
4. Update the size of the largest BST subtree accordingly.

CODE:
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Struct to store the properties of a subtree
struct NodeValue {
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize)
        : minNode(minNode), maxNode(maxNode), maxSize(maxSize) {}
};

// Helper function to find the largest BST subtree recursively
NodeValue largestBSTSubtreeHelper(TreeNode* root) {
    // An empty tree is a BST of size 0
    if (!root) {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }

    // Get values from left and right subtrees of the current tree
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);

    // Check if the current tree is a BST based on its left and right subtrees' properties
    if (left.maxNode < root->val && root->val < right.minNode) {
        // It is a BST, update the values for the current tree
        return NodeValue(min(root->val, left.minNode),
                         max(root->val, right.maxNode),
                         left.maxSize + right.maxSize + 1);
    }

    // If the current tree is not a BST, return values indicating invalid tree properties
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

// Function to find the size of the largest BST subtree
int largestBSTSubtree(TreeNode* root) {
    return largestBSTSubtreeHelper(root).maxSize;
}

/*
EXAMPLE USAGE:
TreeNode* root = new TreeNode(10);
root->left = new TreeNode(5);
root->right = new TreeNode(15);
root->left->left = new TreeNode(1);
root->left->right = new TreeNode(8);
root->right->right = new TreeNode(7);

int size = largestBSTSubtree(root); // Returns 3

TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Each node is processed once.

SPACE COMPLEXITY:
- O(h), where h is the height of the binary tree. This is the space used by the recursion stack.
*/
