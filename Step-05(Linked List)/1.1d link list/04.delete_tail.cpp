/*
QUESTION:
Write a function that takes a singly linked list as input, deletes the tail node of the list, and returns the new head.

Example:
Input: 1 -> 2 -> 3 -> 4 -> NULL
Output: 1 -> 2 -> 3 -> NULL

CLASS NODE:
- Represents a node in a singly linked list.
- Contains data and a pointer to the next node.

METHODS:
1. Constructor with data and next node provided.
2. Constructor with only data provided, next initialized to nullptr.

FUNCTIONS:
1. printLL(Node* head): Prints the linked list starting from the given head.
2. deleteTail(Node* head): Deletes the tail node of the linked list and returns the new head.

CODE:
*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;         // Data of the node
    Node* next;       // Pointer to the next node in the list
    
    // Constructor for a node with both data and next node provided
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    
    // Constructor for a node with only data provided, next initialized to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list starting from the given head
// TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list.
// SPACE COMPLEXITY: O(1), constant extra space is used.
void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Function to delete the tail node of a linked list and return the new head
// TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list.
// SPACE COMPLEXITY: O(1), constant extra space is used.
Node* deleteTail(Node* head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL)
        return NULL;
    
    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    
    // Traverse to the second last node in the list
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    // Delete the last node
    delete temp->next;
    
    // Set the next of the second last node to nullptr, effectively removing the last node
    temp->next = nullptr;
    
    // Return the head of the modified list
    return head;
}

/*
TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list.
SPACE COMPLEXITY: O(1), constant extra space is used.
*/
