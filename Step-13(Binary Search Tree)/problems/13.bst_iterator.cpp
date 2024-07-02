class BSTIterator {
private:
    stack<TreeNode*> myStack;

public:
    /**
     * @brief Constructor that initializes the stack with the leftmost path of the tree.
     * @param root - The root of the BST.
     */
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    /**
     * @brief Returns whether we have a next smallest number.
     * @return True if there is a next smallest number, false otherwise.
     */
    bool hasNext() {
        return !myStack.empty();
    }

    /**
     * @brief Returns the next smallest number.
     * @return The next smallest number in the BST.
     */
    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    /**
     * @brief Helper function to push all leftmost nodes to the stack.
     * @param node - The node from which to start pushing leftmost nodes.
     */
    void pushAll(TreeNode* node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};

/**
 * @brief Question:
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST. 
 * Calling next() will return the next smallest number in the BST. Calling hasNext() will return whether the iterator 
 * has more nodes to iterate.
 * 
 * Example:
 * Given a binary search tree:
 * 
 *       7
 *      / \
 *     3   15
 *        /  \
 *       9    20
 * 
 * BSTIterator iterator = new BSTIterator(root);
 * iterator.next();    // returns 3
 * iterator.next();    // returns 7
 * iterator.hasNext(); // returns true
 * iterator.next();    // returns 9
 * iterator.hasNext(); // returns true
 * iterator.next();    // returns 15
 * iterator.hasNext(); // returns true
 * iterator.next();    // returns 20
 * iterator.hasNext(); // returns false
 * 
 * Approach:
 * 1. Use a stack to store the nodes.
 * 2. Initialize the stack with the leftmost path of the BST.
 * 3. For next(), pop the top node from the stack, push all leftmost nodes of its right subtree to the stack, and return the value of the popped node.
 * 4. For hasNext(), check if the stack is empty.
 * 
 * Time Complexity:
 * - next(): O(1) on average. Each node is pushed and popped from the stack once.
 * - hasNext(): O(1). Simple check to see if the stack is empty.
 * 
 * Space Complexity:
 * - O(h), where h is the height of the tree. In the worst case, the stack will contain all the nodes along the path from the root to the leftmost leaf.
 */
