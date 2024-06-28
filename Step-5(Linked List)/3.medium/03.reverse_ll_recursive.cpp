/*
QUESTION:
Write a function to reverse a singly linked list using recursion. The function should take the head of the list as input and return the new head after reversing the list.

Example:
Input: head = [1,2,3,4,5]
Output: head = [5,4,3,2,1]

APPROACH:
1. Base Case: If the linked list is empty or has only one node, return the head as it is already reversed.
2. Recursive Step:
   - Reverse the linked list starting from the second node (head->next).
   - Save a reference to the node following the current 'head' node.
   - Make the 'front' node point to the current 'head' node in the reversed order.
   - Break the link from the current 'head' node to the 'front' node to avoid cycles.
3. Return the 'newHead,' which is the new head of the reversed linked list.

CODE:
*/

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to reverse a linked list using recursion
Node* reverseLinkedList(Node* head) {
    // Base case:
    // If the linked list is empty or has only one node,
    // return the head as it is already reversed.
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Recursive step:
    // Reverse the linked list starting from the second node (head->next).
    Node* newHead = reverseLinkedList(head->next);
    
    // Save a reference to the node following the current 'head' node.
    Node* front = head->next;
    
    // Make the 'front' node point to the current 'head' node in the reversed order.
    front->next = head;
    
    // Break the link from the current 'head' node to the 'front' node to avoid cycles.
    head->next = NULL;
    
    // Return the 'newHead,' which is the new head of the reversed linked list.
    return newHead;
}

/*
TIME COMPLEXITY:
- O(n) for traversing the linked list where n is the number of nodes in the list.

SPACE COMPLEXITY:
- O(n) for the recursive call stack.

EXAMPLE USAGE:
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);
head->next->next->next = new Node(4);
head->next->next->next->next = new Node(5);
Node* reversedHead = reverseLinkedList(head);
// The reversed list should be [5,4,3,2,1].
*/
