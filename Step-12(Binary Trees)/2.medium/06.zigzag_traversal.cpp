/*
QUESTION:
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left = new Node(6);
root->right->right = new Node(7);

vector<vector<int>> result = ZigZagLevelOrder(root);
// Output: {{1}, {3, 2}, {4, 5, 6, 7}}

APPROACH:
1. Use a queue to perform level-order traversal.
2. Use a boolean flag to determine the direction of traversal (left to right or right to left).
3. For each level, store the values of nodes in a vector, reversing the order based on the flag.
4. Toggle the flag after processing each level.

CODE:
*/
/*
          1
         / \
        2   3
         \
          4
           \
            5
             \
              6
    Zig Zag of the above binary tree is
    1 3 2 4 5 6
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Node structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to perform zigzag level order traversal of a binary tree
vector<vector<int>> ZigZagLevelOrder(Node* root) {
    // Vector to store the result of zigzag traversal
    vector<vector<int>> result;

    // Check if the root is NULL, return an empty result
    if (root == NULL) {
        return result;
    }

    // Queue to perform level order traversal
    queue<Node*> nodesQueue;
    nodesQueue.push(root);

    // Flag to determine the direction of traversal (left to right or right to left)
    bool leftToRight = true;

    // Continue traversal until the queue is empty
    while (!nodesQueue.empty()) {
        // Get the number of nodes at the current level
        int size = nodesQueue.size();

        // Vector to store the values of nodes at the current level
        vector<int> row(size);

        // Traverse nodes at the current level
        for (int i = 0; i < size; i++) {
            // Get the front node from the queue
            Node* node = nodesQueue.front();
            nodesQueue.pop();

            // Determine the index to insert the node's value based on the traversal direction
            int index = leftToRight ? i : (size - 1 - i);

            // Insert the node's value at the determined index
            row[index] = node->data;

            // Enqueue the left and right children if they exist
            if (node->left) {
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        }

        // Switch the traversal direction for the next level
        leftToRight = !leftToRight;

        // Add the current level's values to the result vector
        result.push_back(row);
    }

    // Return the final result of zigzag level order traversal
    return result;
}

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Each node is processed once.

SPACE COMPLEXITY:
- O(n), for storing the result and the nodes in the queue during the traversal.
*/
