/*
QUESTION:
Write a function to insert a new node with value 'k' at the end of a doubly linked list.

CLASS NODE:
- Represents a node in a doubly linked list.
- Contains data and pointers to the previous and next nodes.

METHODS:
1. Constructor with data, next node, and previous node provided.
2. Constructor with only data provided, next and previous initialized to nullptr.

FUNCTIONS:
1. printDLL(Node* head): Prints the doubly linked list starting from the given head.
2. insertAtTail(Node* head, int k): Inserts a new node with value 'k' at the end of the doubly linked list.

CODE:
*/

// Function to insert a new node with value 'k' at the end of the doubly linked list
Node* insertAtTail(Node* head, int k) {
    // Create a new node with data 'k'
    Node* newNode = new Node(k);

    // If the doubly linked list is empty, set 'head' to the new node
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to the end of the doubly linked list
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Connect the new node to the last node in the list
    tail->next = newNode;
    newNode->back = tail;

    return head;
}  

/*
TIME COMPLEXITY: O(N), where N is the number of nodes in the doubly linked list.
SPACE COMPLEXITY: O(1), constant extra space is used.
*/
