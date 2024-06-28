/*
QUESTION:
Given a linked list where each node has two pointers, 'next' and 'random', clone the list such that each new node points to the corresponding cloned node's random and next pointers correctly.

Example:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

APPROACH:
1. Insert a copy of each node in between the original nodes.
2. Connect the random pointers of the copied nodes.
3. Retrieve the deep copy of the linked list by separating the copied nodes from the original nodes.

CODE:
*/

struct Node {
    int data;
    Node* next;
    Node* random;
    Node(int x) : data(x), next(NULL), random(NULL) {}
};

// Function to insert a copy of each node in between the original nodes
void insertCopyInBetween(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* nextElement = temp->next;
        // Create a new node with the same data
        Node* copy = new Node(temp->data);  
        
        // Point the copy's next to the original node's next
        copy->next = nextElement;  
        
        // Point the original node's next to the copy
        temp->next = copy;         

        // Move to the next original node
        temp = nextElement;         
    }
}

// Function to connect random pointers of the copied nodes
void connectRandomPointers(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        // Access the copied node
        Node* copyNode = temp->next;    
        
        // If the original node has a random pointer
        if (temp->random) {   
            // Point the copied node's random to the corresponding copied random node
            copyNode->random = temp->random->next; 
        } else {
            // Set the copied node's random to null if the original random is null
            copyNode->random = NULL;   
        }
        
        // Move to the next original node
        temp = temp->next->next;   
    }
}

// Function to retrieve the deep copy of the linked list
Node* getDeepCopyList(Node* head) {
    Node* temp = head;
    // Create a dummy node
    Node* dummyNode = new Node(-1);   
    // Initialize a result pointer
    Node* res = dummyNode;             

    while (temp != NULL) {
        // Creating a new list by pointing to copied nodes
        res->next = temp->next;
        res = res->next;

        // Disconnect and revert back to the initial state of the original linked list
        temp->next = temp->next->next;
        temp = temp->next;
    }
    
    // Return the deep copy of the list starting from the dummy node
    return dummyNode->next;   
}

// Function to clone the linked list
Node* cloneLL(Node* head) {
    // If the original list is empty, return null
    if (!head) return nullptr;   
    
    // Step 1: Insert copy of nodes in between
    insertCopyInBetween(head); 
    // Step 2: Connect random pointers of copied nodes
    connectRandomPointers(head);  
    // Step 3: Retrieve the deep copy of the linked list
    return getDeepCopyList(head); 
}

/*
TIME COMPLEXITY:
- O(n) for all operations as we are traversing the list a constant number of times.

SPACE COMPLEXITY:
- O(1) for the additional space used excluding the space for the cloned nodes themselves.

EXAMPLE USAGE:
Node* head = new Node(1);
head->next = new Node(2);
head->random = head->next;
Node* clonedList = cloneLL(head);
// The cloned list should have the same structure as the original list.
*/
