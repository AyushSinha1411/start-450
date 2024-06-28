/*
QUESTION:
Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

Example:
Input: head = [1,2,3,4,5]
Output: Node with value 3
Explanation: The middle node of the list is the node with value 3.

APPROACH:
1. Initialize two pointers, slow and fast, both pointing to the head of the linked list.
2. Traverse the linked list using the Tortoise and Hare algorithm:
   - Move the slow pointer one step at a time.
   - Move the fast pointer two steps at a time.
3. When the fast pointer reaches the end of the list, the slow pointer will be at the middle node.
4. Return the slow pointer.

CODE:
*/

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to find the middle node of a linked list
Node* findMiddle(Node* head) {
    // Initialize the slow pointer to the head
    Node* slow = head; 
    // Initialize the fast pointer to the head
    Node* fast = head; 

    // Traverse the linked list using the Tortoise and Hare algorithm
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step
        slow = slow->next; 
        // Move fast two steps
        fast = fast->next->next; 
    }
    
    // Return the slow pointer, which is now at the middle node
    return slow; 
}

/*
TIME COMPLEXITY:
- O(n) for traversing the linked list where n is the number of nodes in the list.

SPACE COMPLEXITY:
- O(1) for additional space used by the two pointers.

EXAMPLE USAGE:
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);
head->next->next->next = new Node(4);
head->next->next->next->next = new Node(5);
Node* middle = findMiddle(head);
// The middle node should be the node with value 3.
*/
