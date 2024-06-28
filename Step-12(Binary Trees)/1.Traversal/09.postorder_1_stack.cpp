/*
QUESTION:
Implement a function to perform postorder traversal of a binary tree iteratively and return the traversal in a vector.

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
vector<int> result = postOrderIterative(root);
// Output: {4, 5, 2, 3, 1}

APPROACH:
1. Initialize an empty vector `postOrderList` to store the traversal result.
2. If the tree is empty, return the empty vector.
3. Create a stack `stk` and push the root node onto it.
4. Use a pointer `prev` to keep track of the previously visited node.
5. Iterate while the stack is not empty:
   - Get the current node from the top of the stack.
   - If traversing down the tree, push left child first if it exists, then right child if it exists.
   - If traversing up from the left, push the right child if it exists.
   - If traversing up from the right, process the current node and pop it from the stack.
6. Update `prev` to the current node at the end of each iteration.
7. Return the `postOrderList` containing the postorder traversal result.

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

// Function to perform postorder traversal iteratively
vector<int> postOrderIterative(Node* root) {
    // Vector to store postorder traversal
    vector<int> postOrderList;

    // If the tree is empty, return an empty traversal
    if (root == NULL) {
        return postOrderList;
    }

    // Create a stack for iterative traversal
    stack<Node*> stk;
    stk.push(root);

    // Pointer to keep track of the previously visited node
    Node* prev = NULL;

    // Iterate while the stack is not empty
    while (!stk.empty()) {
        // Get the current node from the top of the stack
        auto current = stk.top();

        // Traversing down the tree
        if (prev == NULL || prev->left == current || prev->right == current) {
            // Push left child if it exists
            if (current->left) {
                stk.push(current->left);
            }
            // Otherwise, push right child if it exists
            else if (current->right) {
                stk.push(current->right);
            }
            // If no children, process the current node
            else {
                stk.pop();
                postOrderList.push_back(current->data);
            }
        }
        // Traversing up from the left
        else if (current->left == prev) {
            // Push right child if it exists
            if (current->right) {
                stk.push(current->right);
            }
            // Otherwise, process the current node
            else {
                stk.pop();
                postOrderList.push_back(current->data);
            }
        }
        // Traversing up from the right
        else if (current->right == prev) {
            stk.pop();
            postOrderList.push_back(current->data);
        }

        // Update prev to the current node
        prev = current;
    }

    // Return the postorder traversal
    return postOrderList;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree. Each node is visited once.

SPACE COMPLEXITY:
- O(n), for storing the nodes in the stack and the result vector.
*/
