/*
QUESTION:
Implement a function to perform level-order traversal of a binary tree and return the traversal in a 2D vector.

EXAMPLE USAGE:
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);
vector<vector<int>> result = levelOrder(root); 
// Output: {{1}, {2, 3}, {4, 5}}

APPROACH:
1. Initialize an empty 2D vector `ans` to store the levels.
2. If the root is NULL, return the empty vector.
3. Use a queue to facilitate level-order traversal.
4. Enqueue the root node.
5. While the queue is not empty:
   - Get the size of the current level.
   - Initialize an empty vector `level` to store node values of the current level.
   - For each node at the current level:
     - Dequeue the node.
     - Add its value to the `level` vector.
     - Enqueue its left and right children if they exist.
   - Add the `level` vector to the `ans` vector.
6. Return the `ans` vector.

CODE:
*/

#include <vector>
#include <queue>
using namespace std;

// Structure for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize the node with a value
    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

// Function to perform level-order traversal of a binary tree
vector<vector<int>> levelOrder(TreeNode* root) {
    // Create a 2D vector to store levels
    vector<vector<int>> ans; 
    if (root == nullptr) {
        // If the tree is empty, return an empty vector
        return ans; 
    }
    
    // Create a queue to store nodes for level-order traversal
    queue<TreeNode*> q; 
    // Push the root node to the queue
    q.push(root); 

    while (!q.empty()) {
        // Get the size of the current level
        int size = q.size(); 
        // Create a vector to store nodes at the current level
        vector<int> level; 

        for (int i = 0; i < size; i++) {
            // Get the front node in the queue
            TreeNode* node = q.front(); 
            // Remove the front node from the queue
            q.pop(); 
            // Store the node value in the current level vector
            level.push_back(node->val); 

            // Enqueue the child nodes if they exist
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        // Store the current level in the answer vector
        ans.push_back(level); 
    }
    // Return the level-order traversal of the tree
    return ans; 
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the tree. Each node is visited once.

SPACE COMPLEXITY:
- O(n), for storing the nodes in the queue.
*/
