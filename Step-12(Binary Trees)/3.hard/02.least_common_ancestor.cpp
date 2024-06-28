/*
QUESTION:
Given the root of a binary tree and two nodes, p and q, find the lowest common ancestor (LCA) of the two nodes. The LCA is defined as the lowest node in the tree that has both p and q as descendants (where we allow a node to be a descendant of itself).

EXAMPLE USAGE:
TreeNode* root = new TreeNode(3);
root->left = new TreeNode(5);
root->right = new TreeNode(1);
root->left->left = new TreeNode(6);
root->left->right = new TreeNode(2);
root->right->left = new TreeNode(0);
root->right->right = new TreeNode(8);
root->left->right->left = new TreeNode(7);
root->left->right->right = new TreeNode(4);

TreeNode* p = root->left; // Node with value 5
TreeNode* q = root->right; // Node with value 1

TreeNode* lca = lowestCommonAncestor(root, p, q);
// Output: Node with value 3

APPROACH:
1. Base case: If the current node is null or matches either p or q, return the current node.
2. Recursively find the LCA in the left subtree.
3. Recursively find the LCA in the right subtree.
4. If both left and right recursive calls return non-null values, it means p and q are found in different subtrees, so the current node is the LCA.
5. Otherwise, return the non-null value from the left or right recursive call.

CODE:
*/

#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base case
    if (root == NULL || root == p || root == q) {
        return root;
    }
    
    // Recursively find LCA in the left subtree
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    
    // Recursively find LCA in the right subtree
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both left and right are not null, we found our result
    if (left != NULL && right != NULL) {
        return root;
    }

    // If only one of left or right is not null, return the non-null node
    return (left != NULL) ? left : right;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Each node is visited once.

SPACE COMPLEXITY:
- O(h), where h is the height of the binary tree. The maximum space used by the recursion stack.
*/
