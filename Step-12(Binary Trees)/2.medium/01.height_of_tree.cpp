/*
QUESTION:
Given the root of a binary tree, find its maximum depth. The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
int depth = maxDepth(root);
// Output: 3

APPROACH:
1. Base case: If the root is NULL, the depth is 0.
2. Recursive calls: Compute the maximum depth of the left and right subtrees.
3. Combine: The maximum depth of the tree is the greater of the depths of the left and right subtrees, plus 1 to account for the current node.

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

// Function to find the maximum depth of a binary tree
int maxDepth(Node* root) {
    // If the root is NULL (empty tree), depth is 0
    if (root == NULL) {
        return 0;
    }
    
    // Recursive call to find the maximum depth of the left subtree
    int lh = maxDepth(root->left);
    
    // Recursive call to find the maximum depth of the right subtree
    int rh = maxDepth(root->right);
    
    // Return the maximum depth of the tree, adding 1 for the current node
    return 1 + max(lh, rh);
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree. Each node is processed once.

SPACE COMPLEXITY:
- O(h), where h is the height of the tree. This is the space used by the system call stack during the recursion.
*/
