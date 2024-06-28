/*
QUESTION:
Given two Binary Search Trees (BSTs), merge them into a single sorted list of integers.

EXAMPLE:
Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Explanation: The merged list contains all elements from both BSTs in sorted order.

APPROACH:
1. Use two stacks to perform in-order traversal of both BSTs simultaneously.
2. Traverse the left subtree of each BST and push nodes onto their respective stacks.
3. Compare the top nodes of both stacks and process the smaller node by adding its value to the result list and moving to its right subtree.
4. Repeat the process until both stacks and both BSTs are fully traversed.

CODE:
*/

// Definition for a binary tree node.
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to merge two BSTs into a sorted list
vector<int> mergeTwoBST(Node* root1, Node* root2) {
    // Vector to store the merged result
    vector<int> res;

    // Two stacks to perform in-order traversal of both BSTs
    stack<Node*> s1, s2;

    // Continue until both stacks and both trees are fully traversed
    while (root1 || root2 || !s1.empty() || !s2.empty()) {
        // Traverse the left subtree of the first BST
        while (root1) {
            s1.push(root1);
            root1 = root1->left;
        }
        // Traverse the left subtree of the second BST
        while (root2) {
            s2.push(root2);
            root2 = root2->left;
        }

        // Case 1: The stack of the second BST is empty or the top of the first stack is smaller
        if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)) {
            root1 = s1.top();
            s1.pop();
            res.push_back(root1->val);
            root1 = root1->right;
        }
        // Case 2: The stack of the first BST is empty or the top of the second stack is smaller
        else {
            root2 = s2.top();
            s2.pop();
            res.push_back(root2->val);
            root2 = root2->right;
        }
    }

    // Return the merged result
    return res;
}

/*
EXAMPLE USAGE:
Node* root1 = new Node(2);
root1->left = new Node(1);
root1->right = new Node(4);

Node* root2 = new Node(1);
root2->left = new Node(0);
root2->right = new Node(3);

vector<int> mergedList = mergeTwoBST(root1, root2);
// The merged list will be [0, 1, 1, 2, 3, 4]

TIME COMPLEXITY:
- O(m + n), where m and n are the number of nodes in the two BSTs. This is because each node is processed exactly once.

SPACE COMPLEXITY:
- O(h1 + h2), where h1 and h2 are the heights of the two BSTs. The space is used by the stacks to store the nodes.
*/
