/*
QUESTION:
Implement a function to perform inorder traversal of a binary tree and return the traversal in a vector.

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
vector<int> result = inOrder(root); 
// Output: {4, 2, 5, 1, 3}

APPROACH:
1. Initialize an empty vector `arr` to store the traversal result.
2. Use a helper function `inorder` to recursively traverse the tree.
3. In the helper function:
   - If the current node is NULL, return.
   - Recursively traverse the left subtree.
   - Add the current node's value to the `arr` vector.
   - Recursively traverse the right subtree.
4. Call the helper function starting from the root.
5. Return the `arr` vector containing the inorder traversal result.

CODE:
*/

#include <vector>
using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to perform inorder traversal of the tree and store values in 'arr'
void inorder(Node* root, vector<int> &arr){
    // If the current node is NULL (base case for recursion), return
    if (root == nullptr) {
        return;
    }
    // Recursively traverse the left subtree
    inorder(root->left, arr);
    // Push the current node's value into the vector
    arr.push_back(root->data);
    // Recursively traverse the right subtree
    inorder(root->right, arr);
}

// Function to initiate inorder traversal and return the resulting vector
vector<int> inOrder(Node* root){
    // Create an empty vector to store inorder traversal values
    vector<int> arr;
    // Call the inorder traversal function
    inorder(root, arr);
    // Return the resulting vector containing inorder traversal values
    return arr;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree. Each node is visited once.

SPACE COMPLEXITY:
- O(n), for storing the values in the vector and the recursion stack.
*/
