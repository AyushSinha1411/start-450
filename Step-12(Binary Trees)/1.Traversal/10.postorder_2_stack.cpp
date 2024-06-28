/*
QUESTION:
Implement a function to perform postorder traversal of a binary tree using two stacks and return the traversal in a vector.

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
vector<int> result = postOrder(root); 
// Output: {4, 5, 2, 3, 1}

APPROACH:
1. Initialize an empty vector `postorder` to store the traversal result.
2. If the tree is empty, return the empty vector.
3. Create two stacks, `st1` and `st2`, for iterative traversal.
4. Push the root node onto the first stack `st1`.
5. While `st1` is not empty:
   - Pop a node from `st1` and push it onto `st2`.
   - Push the left child of the popped node onto `st1` if it exists.
   - Push the right child of the popped node onto `st1` if it exists.
6. After the traversal is complete, `st2` will contain nodes in postorder.
7. Pop nodes from `st2` and add their values to the `postorder` vector.
8. Return the `postorder` vector containing the postorder traversal result.

CODE:
*/

#include <vector>
#include <stack>
using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to return the postorder traversal of a binary tree using two stacks
vector<int> postOrder(Node* root) {
    // Vector to store postorder traversal
    vector<int> postorder;

    // If the tree is empty, return an empty traversal
    if (root == NULL) {
        return postorder;
    }

    // Two stacks for iterative traversal
    stack<Node*> st1, st2;

    // Push the root node onto the first stack
    st1.push(root);

    // Iterative traversal to populate st2 with nodes in postorder
    while (!st1.empty()) {
        // Get the top node from st1
        root = st1.top();
        st1.pop();

        // Push the node onto st2
        st2.push(root);

        // Push left child onto st1 if exists
        if (root->left != NULL) {
            st1.push(root->left);
        }

        // Push right child onto st1 if exists
        if (root->right != NULL) {
            st1.push(root->right);
        }
    }

    // Populate the postorder traversal vector by popping st2
    while (!st2.empty()) {
        postorder.push_back(st2.top()->data);
        st2.pop();
    }

    // Return the postorder traversal
    return postorder;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree. Each node is visited once.

SPACE COMPLEXITY:
- O(n), for storing the nodes in the two stacks and the result vector.
*/
