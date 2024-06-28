/*
QUESTION:
Write a function to delete the tail node of a doubly linked list.

CLASS NODE:
- Represents a node in a doubly linked list.
- Contains data and pointers to the previous and next nodes.

METHODS:
1. Constructor with data, next node, and previous node provided.
2. Constructor with only data provided, next and previous initialized to nullptr.

FUNCTIONS:
1. printDLL(Node* head): Prints the doubly linked list starting from the given head.
2. insertAtTail(Node* head, int k): Inserts a new node with value 'k' at the end of the doubly linked list.
3. deleteTail(Node* head): Deletes the tail node of the doubly linked list.

CODE:
*/

// Function to delete the tail of the doubly linked list
Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
     // If the list is empty or has only one node, return null
        return nullptr;  
    }
    
    Node* tail = head;
    while (tail->next != nullptr) {
     // Traverse to the last node (tail)
        tail = tail->next; 
    }
    
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    
    // Free memory of the deleted node
    delete tail;  
    
    return head;
}  

/*
TIME COMPLEXITY: O(N), where N is the number of nodes in the doubly linked list.
SPACE COMPLEXITY: O(1), constant extra space is used.
*/
