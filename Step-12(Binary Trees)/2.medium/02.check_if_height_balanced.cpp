/*
QUESTION:
Given the root of a binary tree, determine if the tree is height-balanced. A binary tree is height-balanced if for every node, the height difference between its left and right subtrees is at most 1.

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
bool balanced = isBalanced(root);
// Output: true

APPROACH:
1. Use a recursive function `dfsHeight` to calculate the height of the tree.
2. If the tree is not balanced at any node, propagate the unbalance status by returning -1.
3. Use the `isBalanced` function to check if the tree is balanced by calling `dfsHeight`.

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

// Function to check if a binary tree is balanced
bool isBalanced(Node* root) {
    // Check if the tree's height difference between subtrees is less than 2
    // If not, return false; otherwise, return true
    return dfsHeight(root) != -1;
}

// Recursive function to calculate the height of the tree
int dfsHeight(Node* root) {
    // Base case: if the current node is NULL, return 0 (height of an empty tree)
    if (root == NULL) return 0;

    // Recursively calculate the height of the left subtree
    int leftHeight = dfsHeight(root->left);

    // If the left subtree is unbalanced, propagate the unbalance status
    if (leftHeight == -1) 
        return -1;

    // Recursively calculate the height of the right subtree
    int rightHeight = dfsHeight(root->right);

    // If the right subtree is unbalanced, propagate the unbalance status
    if (rightHeight == -1) 
        return -1;

    // Check if the difference in height between left and right subtrees is greater than 1
    // If it's greater, the tree is unbalanced, return -1 to propagate the unbalance status
    if (abs(leftHeight - rightHeight) > 1)  
        return -1;

    // Return the maximum height of left and right subtrees, adding 1 for the current node
    return max(leftHeight, rightHeight) + 1;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree. Each node is processed once.

SPACE COMPLEXITY:
- O(h), where h is the height of the tree. This is the space used by the system call stack during the recursion.
*/
