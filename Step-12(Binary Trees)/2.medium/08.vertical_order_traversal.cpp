/*
QUESTION:
Given a binary tree, return its vertical order traversal as a 2D vector. In vertical order traversal, nodes are sorted by their vertical level and then by their level in the tree. If two nodes have the same vertical and level, they are sorted by their value.

EXAMPLE USAGE:
Node* root = new Node(1);
root->left = new Node(2);
root->right = new Node(3);
root->left->left = new Node(4);
root->left->right = new Node(5);
root->right->left = new Node(6);
root->right->right = new Node(7);

vector<vector<int>> result = findVertical(root);
// Output: {{4}, {2}, {1, 5, 6}, {3}, {7}}

APPROACH:
1. Use a map to store nodes based on their vertical and level information.
2. Use a queue for BFS traversal, where each element is a pair containing a node and its vertical and level information.
3. Perform BFS traversal to populate the map.
4. Prepare the final result vector by combining values from the map in the desired order.

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
    Vertical Order Traversal of the above binary tree is
    2 1 4 3 5 6
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
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

// Function to perform vertical order traversal and return a 2D vector of node values
vector<vector<int>> findVertical(Node* root){
    // Map to store nodes based on vertical and level information
    map<int, map<int, multiset<int>>> nodes;
    
    // Queue for BFS traversal, each element is a pair containing node and its vertical and level information
    queue<pair<Node*, pair<int, int>>> todo;
    
    // Push the root node with initial vertical and level values (0, 0)
    todo.push({root, {0, 0}});
    
    // BFS traversal
    while(!todo.empty()){
        // Retrieve the node and its vertical and level information from the front of the queue
        auto p = todo.front();
        todo.pop();
        Node* temp = p.first;
        
        // Extract the vertical and level information
        int x = p.second.first;  // x -> vertical
        int y = p.second.second; // y -> level
        
        // Insert the node value into the corresponding vertical and level in the map
        nodes[x][y].insert(temp->data);
        
        // Process left child
        if(temp->left){
            todo.push({
                temp->left,
                {
                    x-1, // Move left in terms of vertical
                    y+1  // Move down in terms of level
                }
            });
        }
        
        // Process right child
        if(temp->right){
            todo.push({
                temp->right, 
                {
                    x+1, // Move right in terms of vertical
                    y+1  // Move down in terms of level
                }
            });
        }
    }
    
    // Prepare the final result vector by combining values from the map
    vector<vector<int>> ans;
    for(auto p: nodes){
        vector<int> col;
        for(auto q: p.second){
            // Insert node values into the column vector
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        // Add the column vector to the final result
        ans.push_back(col);
    }
    return ans;
}

/*
TIME COMPLEXITY:
- O(n log n), where n is the number of nodes in the binary tree. Sorting nodes based on their vertical level and depth takes log n time.

SPACE COMPLEXITY:
- O(n), for storing the map, queue, and result vectors.
*/
