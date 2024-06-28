/*
QUESTION:
Given a binary tree, perform preorder, inorder, and postorder traversal in a single traversal of the tree and return the results.

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
vector<vector<int>> result = preInPostTraversal(root);
// Output: 
// Preorder: {1, 2, 4, 5, 3}
// Inorder: {4, 2, 5, 1, 3}
// Postorder: {4, 5, 2, 3, 1}

APPROACH:
1. Create vectors to store preorder, inorder, and postorder traversal results.
2. Use a stack to maintain nodes along with their traversal state.
3. Start with the root node and state 1 (preorder).
4. Use a loop to process nodes in the stack:
   - For state 1, process the node for preorder, move to state 2, and push the left child if it exists.
   - For state 2, process the node for inorder, move to state 3, and push the right child if it exists.
   - For state 3, process the node for postorder.
5. Return the vectors containing the traversal results.

CODE:
*/

#include <vector>
#include <stack>
using namespace std;

// Node structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to get the preorder, inorder, and postorder traversal of a binary tree in one traversal
vector<vector<int>> preInPostTraversal(Node* root) {
    // Vectors to store traversals
    vector<int> pre, in, post;

    // If the tree is empty, return empty traversals
    if (root == NULL) {
        return {};
    }

    // Stack to maintain nodes and their traversal state
    stack<pair<Node*, int>> st;

    // Start with the root node and state 1 (preorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // This is part of preorder
        if (it.second == 1) {
            // Store the node's data in the preorder traversal
            pre.push_back(it.first->data);
            // Move to state 2 (inorder) for this node
            it.second = 2;
            // Push the updated state back onto the stack
            st.push(it); 

            // Push left child onto the stack for processing
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        // This is part of inorder
        else if (it.second == 2) {
            // Store the node's data in the inorder traversal
            in.push_back(it.first->data);
            // Move to state 3 (postorder) for this node
            it.second = 3;
            // Push the updated state back onto the stack
            st.push(it); 

            // Push right child onto the stack for processing
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        // This is part of postorder
        else {
            // Store the node's data in the postorder traversal
            post.push_back(it.first->data);
        }
    }

    // Return the vectors containing preorder, inorder, and postorder traversals
    return {pre, in, post};
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree. Each node is processed once.

SPACE COMPLEXITY:
- O(n), for storing nodes in the stack and the traversal results.
*/
