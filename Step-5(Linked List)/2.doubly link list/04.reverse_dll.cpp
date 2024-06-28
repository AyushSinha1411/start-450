// Function to reverse a doubly linked list using in-place link exchange method
Node* reverseDLL(Node* head) {
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        // No change is needed; return the current head
        return head; 
    }
    
    // Initialize a pointer to the previous node
    Node* prev = NULL;  
    
    // Initialize a pointer to the current node
    Node* current = head;   

    // Traverse the linked list
    while (current != NULL) {
        // Store a reference to the previous node
        prev = current->back; 
        
        // Swap the previous and next pointers
        current->back = current->next; 
        current->next = prev;          
        
        // Move to the next node in the original list
        current = current->back; 
    }
    
    // The final node in the original list becomes the new head after reversal
    return prev->back;
}  

/*
TIME COMPLEXITY: O(N), where N is the number of nodes in the doubly linked list.
SPACE COMPLEXITY: O(1), constant extra space is used.
*/