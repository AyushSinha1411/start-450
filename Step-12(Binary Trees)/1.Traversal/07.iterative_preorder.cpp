/*
QUESTION:
Implement a function to perform preorder traversal of a binary tree iteratively and return the traversal in a vector.

EXAMPLE USAGE:
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);
vector<int> result = preorderTraversal(root); 
// Output: {1, 2, 4, 5, 3}

APPROACH:
1. Initialize an empty vector `preorder` to store the traversal result.
2. If the root is NULL, return the empty vector.
3. Use a stack to facilitate iterative traversal.
4. Push the root node onto the stack.
5. While the stack is not empty:
   - Pop the top node from the stack.
   - Add its value to the `preorder` vector.
   - Push its right child onto the stack if it exists.
   - Push its left child onto the stack if it exists.
6. Return the `preorder` vector.

CODE:
*/

#include <vector>
#include <stack>
using namespace std;

// Structure for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize the node with a value
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Function to perform preorder traversal of a binary tree iteratively
vector<int> preorderTraversal(TreeNode* root) {
    // Initialize vector to store the preorder traversal result
    vector<int> preorder;
    
    // If the root is null, return an empty traversal result
    if (root == nullptr) {
        return preorder;
    }
    
    // Create a stack to store nodes during traversal
    stack<TreeNode*> st;
    // Push the root node onto the stack
    st.push(root);
    
    // Perform iterative preorder traversal
    while (!st.empty()) {
        // Get the current node from the top of the stack
        root = st.top();
        // Remove the node from the stack
        st.pop();
        
        // Add the node's value to the preorder traversal result
        preorder.push_back(root->val);
        
        // Push the right child onto the stack if it exists
        if (root->right != nullptr) {
            st.push(root->right);
        }
        
        // Push the left child onto the stack if it exists
        if (root->left != nullptr) {
            st.push(root->left);
        }
    }
    
    // Return the preorder traversal result
    return preorder;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree. Each node is visited once.

SPACE COMPLEXITY:
- O(n), for storing the nodes in the stack.
*/
