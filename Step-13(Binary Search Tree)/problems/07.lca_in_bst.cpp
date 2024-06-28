/*
QUESTION:
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. The lowest common ancestor is defined between two nodes p and q as the lowest node in the tree that has both p and q as descendants (where we allow a node to be a descendant of itself).

EXAMPLE:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5

APPROACH:
1. Use a recursive approach to traverse the binary tree.
2. If the current node is null, or matches one of the target nodes, return the current node.
3. Recursively search for the target nodes in the left and right subtrees.
4. If both left and right recursive calls return non-null values, the current node is the LCA.
5. If only one of the recursive calls returns a non-null value, propagate that value up the recursion stack.

CODE:
*/

// Function to find the lowest common
// ancestor of two nodes in a binary tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Base case: if the root is null or one
    // of the nodes is found, return the current root
    if (root == NULL || root == p || root == q) {
        return root;
    }

    // Recursively find the lowest
    // common ancestor in the left subtree
    TreeNode* left = lowestCommonAncestor(root->left, p, q);

    // Recursively find the lowest
    // common ancestor in the right subtree
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If the left subtree doesn't contain the
    // common ancestor, return the right subtree result
    if (left == NULL) {
        return right;
    }
    // If the right subtree doesn't contain the
    // common ancestor, return the left subtree result
    else if (right == NULL) {
        return left;
    }
    // If both subtrees contain the nodes, the
    // current root is the lowest common ancestor
    else {
        return root;
    }
}

/*
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

TreeNode* result = lowestCommonAncestor(root, p, q);
// Expected output: Node with value 3

TreeNode* p2 = root->left; // Node with value 5
TreeNode* q2 = root->left->right->right; // Node with value 4

TreeNode* result2 = lowestCommonAncestor(root, p2, q2);
// Expected output: Node with value 5

TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree, since we visit each node once.

SPACE COMPLEXITY:
- O(h), where h is the height of the tree, due to the recursive call stack.
*/
