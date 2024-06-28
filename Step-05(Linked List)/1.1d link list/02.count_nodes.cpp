/*
QUESTION:
Write a function to count the number of nodes in a singly linked list.

Example:
Input: 1 -> 2 -> 3 -> 4 -> NULL
Output: 4

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

CODE:
*/

int getCount(Node* head)  
{  
    int count = 0; // Initialize count  
    Node* current = head; // Initialize current  
    while (current != NULL)  
    {  
        count++;  
        current = current->next;  
    }  
    return count;  
}  

/*
TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list.
SPACE COMPLEXITY: O(1), constant extra space is used.
*/
