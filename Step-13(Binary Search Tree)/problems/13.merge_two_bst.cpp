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

class BSTIterator {
private:
    stack<TreeNode*> myStack;

public:
    // Constructor that initializes the stack with the leftmost path of the tree
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    // Returns whether we have a next smallest number
    bool hasNext() {
        return !myStack.empty();
    }

    // Returns the next smallest number
    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    // Helper function to push all leftmost nodes to the stack
    void pushAll(TreeNode* node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};

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
