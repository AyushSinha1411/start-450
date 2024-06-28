/*
QUESTION:
Given the root of a binary tree, determine the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
int diameter = diameterOfBinaryTree(root);
// Output: 3

APPROACH:
1. Use a helper function `height` to calculate the height of the tree and update the diameter.
2. The diameter is updated as the maximum value of the current diameter or the sum of the heights of the left and right subtrees.
3. The main function `diameterOfBinaryTree` initializes the diameter and calls the `height` function.

CODE:
*/

// Node structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to find the diameter of a binary tree
int diameterOfBinaryTree(Node* root) {
    // Initialize the variable to store the diameter of the tree
    int diameter = 0;
    // Call the height function to traverse the tree and calculate diameter
    height(root, diameter);
    // Return the calculated diameter
    return diameter;
}

// Function to calculate the height of the tree and update the diameter
int height(Node* node, int& diameter) {
    // Base case: If the node is null, return 0 indicating the height of an empty tree
    if (!node) {
        return 0;
    }

    // Recursively calculate the height of left and right subtrees
    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);

    // Update the diameter with the maximum of current diameter or sum of left and right heights
    diameter = max(diameter, lh + rh);

    // Return the height of the current node's subtree
    return 1 + max(lh, rh);
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree. Each node is processed once.

SPACE COMPLEXITY:
- O(h), where h is the height of the tree. This is the space used by the system call stack during the recursion.
*/
