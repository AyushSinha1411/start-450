/*
QUESTION:
Write a function to search for a key in a singly linked list and return true if found, otherwise false.

Example:
Input: 1 -> 2 -> 3 -> 4 -> NULL, x = 3
Output: true

CLASS NODE:
- Represents a node in a singly linked list.
- Contains data and a pointer to the next node.

METHODS:
1. Constructor with data and next node provided.
2. Constructor with only data provided, next initialized to nullptr.

FUNCTIONS:
1. printLL(Node* head): Prints the linked list starting from the given head.
2. deleteTail(Node* head): Deletes the tail node of the linked list and returns the new head.
3. getCount(Node* head): Counts the number of nodes in the linked list.
4. search(Node* head, int x): Searches for a key in the linked list and returns true if found, otherwise false.

CODE:
*/

bool search(Node* head, int x) 
{ 
    Node* current = head; 
    while (current != NULL) 
    { 
        if (current->key == x) 
            return true; 
        current = current->next; 
    } 
    return false; 
}  

/*
TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list.
SPACE COMPLEXITY: O(1), constant extra space is used.
*/
