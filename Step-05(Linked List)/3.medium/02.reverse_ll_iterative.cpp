/*
QUESTION:
Write a function to reverse a singly linked list. The function should take the head of the list as input and return the new head after reversing the list.

Example:
Input: head = [1,2,3,4,5]
Output: head = [5,4,3,2,1]

APPROACH:
1. Initialize a pointer 'temp' at the head of the linked list.
2. Initialize a pointer 'prev' to NULL to represent the previous node.
3. Traverse the list using a while loop until 'temp' becomes NULL.
   - Store the next node in 'front' to preserve the reference.
   - Reverse the direction of the current node's 'next' pointer to point to 'prev'.
   - Move 'prev' to the current node for the next iteration.
   - Move 'temp' to the 'front' node, advancing the traversal.
4. Return 'prev' as the new head of the reversed linked list.

CODE:
*/

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to reverse a linked list
Node* reverseLinkedList(Node *head) {
    // Initialize 'temp' at the head of linked list
    Node* temp = head;  
   
    // Initialize pointer 'prev' to NULL, representing the previous node
    Node* prev = NULL;  
   
    // Traverse the list, continue till 'temp' reaches the end (NULL)
    while (temp != NULL) {  
        // Store the next node in 'front' to preserve the reference
        Node* front = temp->next;  
       
        // Reverse the direction of the current node's 'next' pointer to point to 'prev'
        temp->next = prev;  
       
        // Move 'prev' to the current node for the next iteration
        prev = temp;  
       
        // Move 'temp' to the 'front' node, advancing the traversal
        temp = front; 
    }
   
    // Return the new head of the reversed linked list
    return prev;  
}

/*
TIME COMPLEXITY:
- O(n) for traversing the linked list where n is the number of nodes in the list.

SPACE COMPLEXITY:
- O(1) for additional space used by the pointers.

EXAMPLE USAGE:
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);
head->next->next->next = new Node(4);
head->next->next->next->next = new Node(5);
Node* reversedHead = reverseLinkedList(head);
// The reversed list should be [5,4,3,2,1].
*/
