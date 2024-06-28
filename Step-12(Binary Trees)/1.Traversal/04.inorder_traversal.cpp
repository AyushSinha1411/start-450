/*
QUESTION:
Implement a function to perform inorder traversal of a binary tree and store the traversal in a vector.

EXAMPLE USAGE:
Node* root = new Node(10);
root->left = new Node(5);
root->right = new Node(15);
vector<int> result = inOrder(root); // Output: {5, 10, 15}

APPROACH:
1. Define a helper function `inorder` to perform the inorder traversal of the tree.
2. In the `inorder` function, first check if the current node is NULL; if it is, return.
3. Recursively traverse the left subtree.
4. Push the current node's data to the vector.
5. Recursively traverse the right subtree.
6. Define the `inOrder` function to initialize an empty vector and call the `inorder` function, passing the root node and the vector.
7. Return the vector containing the inorder traversal of the tree.

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

// Function to perform inorder traversal of the tree and store values in 'arr'
void inorder(Node* root, vector<int> &arr){
    // If the current node is NULL (base case for recursion), return
    if(root == nullptr){
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
- O(h), where h is the height of the tree. This space is used by the recursion stack.
*/
