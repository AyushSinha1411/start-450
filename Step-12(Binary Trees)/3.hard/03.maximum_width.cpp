/*
QUESTION:
Given the root of a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels. The width of one level is defined as the number of nodes between the leftmost and rightmost non-null nodes in the level, including the end nodes, without counting null nodes between them.

EXAMPLE USAGE:
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(3);
root->right = new TreeNode(2);
root->left->left = new TreeNode(5);
root->left->right = new TreeNode(3);
root->right->right = new TreeNode(9);

int result = widthOfBinaryTree(root);
// Output: 4

APPROACH:
1. Use level-order traversal (BFS) to traverse the tree.
2. For each level, track the position of each node relative to the leftmost node in that level.
3. Calculate the width of the current level as the difference between the positions of the rightmost and leftmost nodes plus one.
4. Keep track of the maximum width encountered during the traversal.

Input:
           1
         /   \
       2      3
     /   \      \
    4     5      8 
               /   \
              6     7

Output:  3

CODE:
*/

#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the maximum width of the binary tree
int widthOfBinaryTree(TreeNode* root) {
    // If the root is null, the width is zero
    if (!root) {
        return 0;
    }

    // Initialize a variable 'ans' to store the maximum width
    int ans = 0;

    // Create a queue to perform level-order traversal,
    // where each element is a pair of TreeNode* and its position in the level
    queue<pair<TreeNode*, int>> q;
    // Push the root node and its position (0) into the queue
    q.push({root, 0});

    // Perform level-order traversal
    while (!q.empty()) {
        // Get the number of nodes at the current level
        int size = q.size();
        // Get the position of the front node in the current level
        int mmin = q.front().second;
        
        // Store the first and last positions of nodes in the current level
        int first, last;

        // Process each node in the current level
        for (int i = 0; i < size; i++) {
            // Calculate current position relative to the minimum position in the level
            int cur_id = q.front().second - mmin;
            // Get the current node
            TreeNode* node = q.front().first;
            // Pop the front node from the queue
            q.pop();

            // If this is the first node in the level, update the 'first' variable
            if (i == 0) {
                first = cur_id;
            }

            // If this is the last node in the level, update the 'last' variable
            if (i == size - 1) {
                last = cur_id;
            }

            // Enqueue the left child of the current node with its position
            if (node->left) {
                q.push({node->left, cur_id * 2 + 1});
            }

            // Enqueue the right child of the current node with its position
            if (node->right) {
                q.push({node->right, cur_id * 2 + 2});
            }
        }

        // Update the maximum width by calculating the difference between the first and last positions, and adding 1
        ans = max(ans, last - first + 1);
    }

    // Return the maximum width of the binary tree
    return ans;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Each node is visited once during the level-order traversal.

SPACE COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. In the worst case, the queue can store all nodes at the deepest level.
*/
