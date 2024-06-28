/*
QUESTION:
Write a function to serialize a binary tree to a single string and a function to deserialize that string back to a binary tree. The serialized format should be such that it allows for easy reconstruction of the original tree.

EXAMPLE:
Input:
    Tree:
       1
      / \
     2   3
        / \
       4   5
Output:
    Serialized: "1,2,3,#,#,4,5,#,#,#,#,"

APPROACH:
1. **Serialization**:
    - Perform a level-order traversal (BFS) of the tree.
    - Append node values to a string, using "#" for null nodes.
    - Use a comma as a delimiter between values.

2. **Deserialization**:
    - Use a stringstream to parse the serialized string.
    - Use a queue to manage nodes during reconstruction.
    - Create new nodes for each value, setting left and right children appropriately.

CODE:
*/

#include <iostream>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Function to serialize the tree into a single string
    string serialize(TreeNode* root) {
        // Check if the tree is empty
        if (!root) {
            return "";
        }

        // Initialize an empty string to store the serialized data
        string s = "";
        // Use a queue for level-order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal
        while (!q.empty()) {
            // Get the front node in the queue
            TreeNode* curNode = q.front();
            q.pop();

            // Check if the current node is null and append "#" to the string
            if (curNode == nullptr) {
                s += "#,";
            } else {
                // Append the value of the current node to the string
                s += to_string(curNode->val) + ",";
                // Push the left and right children to the queue for further traversal
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        // Return the serialized string
        return s;
    }

    // Function to deserialize the encoded data to a tree
    TreeNode* deserialize(string data) {
        // Check if the serialized data is empty
        if (data.empty()) {
            return nullptr;
        }

        // Use a stringstream to tokenize the serialized data
        stringstream s(data);
        string str;
        // Read the root value from the serialized data
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        // Use a queue for level-order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal to reconstruct the tree
        while (!q.empty()) {
            // Get the front node in the queue
            TreeNode* node = q.front();
            q.pop();

            // Read the value of the left child from the serialized data
            getline(s, str, ',');
            // If the value is not "#", create a new left child and push it to the queue
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Read the value of the right child from the serialized data
            getline(s, str, ',');
            // If the value is not "#", create a new right child and push it to the queue
            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        // Return the reconstructed root of the tree
        return root;
    }
}

/*
EXAMPLE USAGE:
Codec ser, deser;
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->right->left = new TreeNode(4);
root->right->right = new TreeNode(5);

string serialized = ser.serialize(root);
TreeNode* deserialized = deser.deserialize(serialized);

cout << "Serialized: " << serialized << endl;
// Expected output: Serialized: "1,2,3,#,#,4,5,#,#,#,#,"

/*
TIME COMPLEXITY:
- O(n), where n is the number of nodes in the binary tree. Both serialization and deserialization visit each node once.

SPACE COMPLEXITY:
- O(n), due to the space required for the queue during the level-order traversal and the string storage.
*/
