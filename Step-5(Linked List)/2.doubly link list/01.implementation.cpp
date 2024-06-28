/*
QUESTION:
Define a Node class for a doubly linked list and implement a function to convert an array to a doubly linked list.

CLASS NODE:
- Represents a node in a doubly linked list.
- Contains data and pointers to the previous and next nodes.

METHODS:
1. Constructor for a Node with data, next node, and previous node provided.
2. Constructor for a Node with data and no references to the next and previous nodes (end of the list).

FUNCTIONS:
1. convertArr2DLL(vector<int> arr): Converts an array to a doubly linked list.

CODE:
*/

// Define a Node class for a doubly linked list
class Node {
public:
    // Data stored in the node
    int data;   
    // Pointer to the next node in the list (forward direction)
    Node* next;     
    // Pointer to the previous node in the list (backward direction)
    Node* back;     

    // Constructor for a Node with data, next node, and previous node provided
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data and no references to the next and previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    // Initialize 'prev' to the head node
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the previous node to point to the new node
        prev->next = temp; 
        // Move 'prev' to the newly created node for the next iteration
        prev = temp;       
    }
    // Return the head of the doubly linked list
    return head;  
}  

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(N), as N nodes are created for the doubly linked list.
*/
