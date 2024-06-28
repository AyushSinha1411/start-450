/*
QUESTION:
Given a binary tree, return its top view as a vector of node values. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left = new Node(6);
root->right->right = new Node(7);

vector<int> result = topView(root);
// Output: {4, 2, 1, 3, 7}

APPROACH:
1. Use a map to store the first node encountered at each vertical level.
2. Use a queue for BFS traversal, where each element is a pair containing a node and its vertical position.
3. Perform BFS traversal to populate the map with the top view nodes.
4. Transfer values from the map to the result vector in order of their vertical levels.

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
    Top view of the above binary tree is
    2 1 3 6
*/

#include <iostream>
#include <vector>
#include <map>
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

// Function to return the top view of the binary tree
vector<int> topView(Node* root) {
    // Vector to store the result
    vector<int> ans;
    
    // Check if the tree is empty
    if (root == NULL) {
        return ans;
    }
    
    // Map to store the top view nodes based on their vertical positions
    map<int, int> mpp;
    
    // Queue for BFS traversal, each element is a pair containing node and its vertical position
    queue<pair<Node*, int>> q;
    
    // Push the root node with its vertical position (0) into the queue
    q.push({root, 0});
    
    // BFS traversal
    while (!q.empty()) {
        // Retrieve the node and its vertical position from the front of the queue
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        
        // If the vertical position is not already in the map, add the node's data to the map
        if (mpp.find(line) == mpp.end()) {
            mpp[line] = node->data;
        }
        
        // Process left child
        if (node->left != NULL) {
            // Push the left child with a decreased vertical position into the queue
            q.push({node->left, line - 1});
        }
        
        // Process right child
        if (node->right != NULL) {
            // Push the right child with an increased vertical position into the queue
            q.push({node->right, line + 1});
        }
    }
    
    // Transfer values from the map to the result vector
    for (auto it : mpp) {
        ans.push_back(it.second);
    }
    
    return ans;
}

/*
TIME COMPLEXITY:
- O(n log n), where n is the number of nodes in the binary tree. The sorting of nodes based on their vertical level takes log n time.

SPACE COMPLEXITY:
- O(n), for storing the map, queue, and result vector.
*/
