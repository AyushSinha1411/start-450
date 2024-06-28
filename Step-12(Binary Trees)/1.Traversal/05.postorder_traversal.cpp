/*
QUESTION:
Implement a function to perform postorder traversal of a binary tree and store the traversal in a vector.

EXAMPLE USAGE:
Node* root = new Node(10);
root->left = new Node(5);
root->right = new Node(15);
vector<int> result = postOrder(root); // Output: {5, 15, 10}

APPROACH:
1. Define a helper function `postorder` to perform the postorder traversal of the tree.
2. In the `postorder` function, first check if the current node is NULL; if it is, return.
3. Recursively traverse the left subtree.
4. Recursively traverse the right subtree.
5. Push the current node's data to the vector.
6. Define the `postOrder` function to initialize an empty vector and call the `postorder` function, passing the root node and the vector.
7. Return the vector containing the postorder traversal of the tree.

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

// Function to perform postorder traversal recursively
void postorder(Node* root, vector<int>& arr){
    // Base case: if root is null, return
    if(root == NULL){
        return;
    }
    // Traverse left subtree
    postorder(root->left, arr);
    // Traverse right subtree
    postorder(root->right, arr);
    // Visit the node (append node's data to the array)
    arr.push_back(root->data);
}

// Function to get the postorder traversal of a binary tree
vector<int> postOrder(Node* root){
    // Create a vector to store the traversal result
    vector<int> arr;
    // Perform postorder traversal starting from the root
    postorder(root, arr);
    // Return the postorder traversal result
    return arr;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree. Each node is visited once.

SPACE COMPLEXITY:
- O(h), where h is the height of the tree. This space is used by the recursion stack.
*/
