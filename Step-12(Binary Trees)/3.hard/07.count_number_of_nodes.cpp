/*
QUESTION:
Given a complete binary tree, count the number of nodes in the tree.

EXAMPLE USAGE:
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);
root->right->left = new TreeNode(6);

int totalNodes = countNodes(root);
cout << "Total number of nodes: " << totalNodes << endl; // Output: 6

APPROACH:
1. Calculate the height of the leftmost path (left height) and the rightmost path (right height) from the root.
2. If both heights are equal, the tree is a perfect binary tree, and the total number of nodes can be calculated using the formula (2^h - 1).
3. If the heights are not equal, recursively count the nodes in the left and right subtrees and add them together with the root node.

CODE:
*/

#include <iostream>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to count nodes in a binary tree
int countNodes(TreeNode* root) {
    // Base case: If the root is NULL, there are no nodes
    if (root == NULL) {
        return 0;
    }
    
    // Find the left height and right height of the tree
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    
    // Check if the last level is completely filled
    if (lh == rh) {
        // If so, use the formula for total nodes in a perfect binary tree i.e., 2^h - 1
        return (1 << lh) - 1; 
    }
    
    // If the last level is not completely filled, recursively count nodes in left and right subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to find the left height of a tree
int findHeightLeft(TreeNode* node) {
    int height = 0;
    // Traverse left child until reaching the leftmost leaf
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}

// Function to find the right height of a tree
int findHeightRight(TreeNode* node) {
    int height = 0;
    // Traverse right child until reaching the rightmost leaf
    while (node) {
        height++;
        node = node->right;
    }
    return height;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    int totalNodes = countNodes(root);
    cout << "Total number of nodes: " << totalNodes << endl; // Output: 6
    return 0;
}

/*
TIME COMPLEXITY:
- O((log N)^2), where N is the number of nodes in the binary tree. This is because we calculate the height (log N) and then recursively count nodes in the subtrees.

SPACE COMPLEXITY:
- O(log N), where N is the number of nodes in the binary tree. This is due to the recursive call stack.
*/
