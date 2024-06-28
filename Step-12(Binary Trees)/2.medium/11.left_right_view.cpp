/*
QUESTION:
Given a binary tree, return its right view and left view as vectors of node values. The right view of a binary tree is the set of nodes visible when the tree is viewed from the right side, and the left view is the set of nodes visible when viewed from the left side.

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->right = new Node(6);

vector<int> rightView = rightsideView(root);
// Output: {1, 3, 6}

vector<int> leftView = leftsideView(root);
// Output: {1, 2, 4}

APPROACH:
1. Use recursive functions to traverse the binary tree and populate the right and left views.
2. For the right view, traverse the tree in a right-to-left manner and for the left view, traverse in a left-to-right manner.
3. Keep track of the current level and add the first node encountered at each level to the result vector.


CODE:
*/

#include <iostream>
#include <vector>
using namespace std;

// Node structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to return the Right view of the binary tree
vector<int> rightsideView(Node* root) {
    // Vector to store the result
    vector<int> res;

    // Call the recursive function to populate the right-side view
    recursionRight(root, 0, res);

    return res;
}

// Function to return the Left view of the binary tree
vector<int> leftsideView(Node* root) {
    // Vector to store the result
    vector<int> res;

    // Call the recursive function to populate the left-side view
    recursionLeft(root, 0, res);

    return res;
}

private:
    // Recursive function to traverse the binary tree and populate the left-side view
    void recursionLeft(Node* root, int level, vector<int>& res) {
        // Check if the current node is NULL
        if (root == NULL) {
            return;
        }

        // Check if the size of the result vector is equal to the current level
        if (res.size() == level) {
            // If equal, add the value of the current node to the result vector
            res.push_back(root->data);
        }

        // Recursively call the function for the left child with an increased level
        recursionLeft(root->left, level + 1, res);

        // Recursively call the function for the right child with an increased level
        recursionLeft(root->right, level + 1, res);
    }

    // Recursive function to traverse the binary tree and populate the right-side view
    void recursionRight(Node* root, int level, vector<int>& res) {
        // Check if the current node is NULL
        if (root == NULL) {
            return;
        }

        // Check if the size of the result vector is equal to the current level
        if (res.size() == level) {
            // If equal, add the value of the current node to the result vector
            res.push_back(root->data);
        }

        // Recursively call the function for the right child with an increased level
        recursionRight(root->right, level + 1, res);

        // Recursively call the function for the left child with an increased level
        recursionRight(root->left, level + 1, res);
    }

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Each node is visited once.

SPACE COMPLEXITY:
- O(h), where h is the height of the binary tree. The maximum space used by the recursion stack.
*/
