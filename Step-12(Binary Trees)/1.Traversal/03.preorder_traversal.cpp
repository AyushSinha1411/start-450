/*
QUESTION:
Implement a function to perform preorder traversal of a binary tree and store the traversal in a vector.

EXAMPLE USAGE:
Node* root = new Node(10);
root->left = new Node(5);
root->right = new Node(15);
vector<int> result = preOrder(root); // Output: {10, 5, 15}

APPROACH:
1. Define a helper function `preorder` to perform the preorder traversal of the tree.
2. In the `preorder` function, first check if the current node is NULL; if it is, return.
3. Otherwise, push the current node's data to the vector.
4. Recursively traverse the left subtree, followed by the right subtree.
5. Define the `preOrder` function to initialize an empty vector and call the `preorder` function, passing the root node and the vector.
6. Return the vector containing the preorder traversal of the tree.

CODE:
*/

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to perform preorder traversal of the tree and store values in 'arr'
void preorder(Node* root, vector<int> &arr){
    // If the current node is NULL (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Push the current node's value into the vector
    arr.push_back(root->data);
    // Recursively traverse the left subtree
    preorder(root->left, arr);
    // Recursively traverse the right subtree
    preorder(root->right, arr);
}

// Function to initiate preorder traversal and return the resulting vector
vector<int> preOrder(Node* root){
    // Create an empty vector to store preorder traversal values
    vector<int> arr;
    // Call the preorder traversal function
    preorder(root, arr);
    // Return the resulting vector containing preorder traversal values
    return arr;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree. Each node is visited once.

SPACE COMPLEXITY:
- O(h), where h is the height of the tree. This space is used by the recursion stack.
*/
