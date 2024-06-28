/*
QUESTION:
Given a binary tree, write a function to check if it satisfies the children sum property. The children sum property is defined as the value of each node being equal to the sum of the values of its left and right children. If either child is not present, its value is considered as 0.

EXAMPLE USAGE:
TreeNode* root = new TreeNode(10);
root->left = new TreeNode(8);
root->right = new TreeNode(2);
root->left->left = new TreeNode(3);
root->left->right = new TreeNode(5);
root->right->right = new TreeNode(2);

bool result = isSumProperty(root);
cout << result << endl; // Output: 1

APPROACH:
1. Check if the current node is NULL or a leaf node. If yes, return 1 (true).
2. Calculate the sum of the left and right children's values, treating NULL children as having a value of 0.
3. Check if the current node's value is equal to the sum of its children's values.
4. Recursively check the left and right subtrees.
5. Return true only if all nodes satisfy the children sum property.

CODE:
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if the binary tree
// satisfies the children sum property
int isSumProperty(TreeNode* node) {
    // Base case: If the node is NULL or
    // it's a leaf node, return true (1)
    if (node == NULL || (node->left == NULL && node->right == NULL)) {
        return 1;
    }

    // Initialize sum of left and right children
    int sum = 0;

    // If left child is present, add its value to sum
    if (node->left != NULL) {
        sum += node->left->val;
    }

    // If right child is present, add its value to sum
    if (node->right != NULL) {
        sum += node->right->val;
    }

    // Check if the node's value equals the sum of its children
    // and recursively check the left and right subtrees
    return ((node->val == sum) 
            && isSumProperty(node->left) 
            && isSumProperty(node->right));
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Each node is visited once.

SPACE COMPLEXITY:
- O(h), where h is the height of the binary tree. This space is used for the recursive call stack. In the worst case, the height of the tree is n (for a skewed tree), leading to O(n) space complexity.
*/
