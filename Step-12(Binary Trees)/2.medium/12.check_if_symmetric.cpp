/*
QUESTION:
Given a binary tree, check whether it is a mirror of itself (symmetric around its center).

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(2);
root->left->left = new Node(3);
root->left->right = new Node(4);
root->right->left = new Node(4);
root->right->right = new Node(3);

bool result = isSymmetric(root);
// Output: true (The tree is symmetric)

APPROACH:
1. Define a utility function `isSymmetricUtil` to check if two subtrees are symmetric.
2. The utility function should:
   - Check if both subtrees are NULL, return true if they are.
   - If one subtree is NULL and the other is not, return false.
   - Recursively check if the left subtree of one tree is a mirror of the right subtree of the other tree and vice versa.
3. Define the public function `isSymmetric` to check if the entire binary tree is symmetric by calling the utility function on the root's left and right children.

     1
   /   \
  2     2
 / \   / \
3   4 4   3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
CODE:
*/

#include <iostream>
using namespace std;

// Node structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to check if two subtrees are symmetric
bool isSymmetricUtil(Node* root1, Node* root2) {
    // Check if either subtree is NULL
    if (root1 == NULL || root2 == NULL) {
        // If one subtree is NULL, the other must also be NULL for symmetry
        return root1 == root2;
    }
    // Check if the data in the current nodes is equal and recursively check for symmetry in subtrees
    return (root1->data == root2->data)
        && isSymmetricUtil(root1->left, root2->right)
        && isSymmetricUtil(root1->right, root2->left);
}

// Public function to check if the entire binary tree is symmetric
bool isSymmetric(Node* root) {
    // Check if the tree is empty
    if (!root) {
        // An empty tree is considered symmetric
        return true;
    }
    // Call the utility function to check symmetry of subtrees
    return isSymmetricUtil(root->left, root->right);
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Each node is visited once.

SPACE COMPLEXITY:
- O(h), where h is the height of the binary tree. The maximum space used by the recursion stack.
*/
