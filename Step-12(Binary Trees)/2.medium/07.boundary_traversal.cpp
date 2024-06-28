/*
QUESTION:
Given a binary tree, return the boundary traversal of its nodes' values. The boundary includes the left boundary, leaves, and the right boundary in order, excluding duplicate leaves and nodes already included in the left boundary.

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->left->right->left = new Node(8);
root->left->right->right = new Node(9);
root->right->left = new Node(6);
root->right->right = new Node(7);
root->right->right->left = new Node(10);
root->right->right->right = new Node(11);

vector<int> result = printBoundary(root);
// Output: {1, 2, 4, 8, 9, 10, 11, 7, 3}

APPROACH:
1. Check if a node is a leaf.
2. Traverse and add the left boundary of the tree.
3. Traverse and add all the leaf nodes.
4. Traverse and add the right boundary of the tree.
5. Combine the results in the order: left boundary, leaves, right boundary (reversed).

CODE:
*/
/*
          1
         / \
        2   3
         \
          4
           \
            5
             \
              6
    Boundary Traversal of the above binary tree is
    1 2 4 5 6 3
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

// Function to check if a node is a leaf
bool isLeaf(Node* root) {
    return !root->left && !root->right;
}

// Function to add the left boundary of the tree
void addLeftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while (curr) {
        // If the current node is not a leaf, add its value to the result
        if (!isLeaf(curr)) {
            res.push_back(curr->data);
        }
        // Move to the left child if it exists, otherwise move to the right child
        if (curr->left) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
}

// Function to add the right boundary of the tree
void addRightBoundary(Node* root, vector<int>& res) {
    Node* curr = root->right;
    vector<int> temp;
    while (curr) {
        // If the current node is not a leaf, add its value to a temporary vector
        if (!isLeaf(curr)) {
            temp.push_back(curr->data);
        }
        // Move to the right child if it exists, otherwise move to the left child
        if (curr->right) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    // Reverse and add the values from the temporary vector to the result
    for (int i = temp.size() - 1; i >= 0; --i) {
        res.push_back(temp[i]);
    }
}

// Function to add the leaves of the tree
void addLeaves(Node* root, vector<int>& res) {
    // If the current node is a leaf, add its value to the result
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    // Recursively add leaves of the left and right subtrees
    if (root->left) {
        addLeaves(root->left, res);
    }
    if (root->right) {
        addLeaves(root->right, res);
    }
}

// Main function to perform the boundary traversal of the binary tree
vector<int> printBoundary(Node* root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    // If the root is not a leaf, add its value to the result
    if (!isLeaf(root)) {
        res.push_back(root->data);
    }

    // Add the left boundary, leaves, and right boundary in order
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Each node is visited at most once.

SPACE COMPLEXITY:
- O(n), for storing the result and additional structures used during traversal.
*/
