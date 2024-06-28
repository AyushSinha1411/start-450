/*
QUESTION:
Given a doubly linked list and a value 'x', write a function to delete all occurrences of 'x' from the list.

APPROACH:
1. Implement a helper function `deleteNode` to delete a specified node from the list.
2. Implement the main function `deleteAllOccurOfX` to traverse the list and use `deleteNode` to delete nodes with the specified value 'x'.
3. Update pointers accordingly to maintain the list structure after deletions.

CODE:
*/

#include <iostream>
using namespace std;

// Definition for doubly-linked list.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

// Function to delete a specified node from the linked list
void deleteNode(struct Node** head_ref, struct Node* del) {
    // If the linked list is empty or the node to be deleted is NULL, return
    if (*head_ref == NULL || del == NULL) return;

    // If the node to be deleted is the head node, update the head pointer
    if (*head_ref == del) *head_ref = del->next;

    // If the node to be deleted is not the last node, update the next pointer of the previous node
    if (del->next != NULL) del->next->prev = del->prev;

    // If the node to be deleted is not the first node, update the previous pointer of the next node
    if (del->prev != NULL) del->prev->next = del->next;

    // Free the memory occupied by the deleted node
    delete del;
}

// Function to delete all occurrences of a specific element from the linked list
void deleteAllOccurOfX(struct Node** head_ref, int x) {
    // If the linked list is empty, return
    if ((*head_ref) == NULL) return;

    struct Node* current = *head_ref;
    struct Node* next;

    // Traverse the list until the end
    while (current != NULL) {
        // If a node with value 'x' is found
        if (current->data == x) {
            // Save the next node in the pointer 'next'
            next = current->next;

            // Delete the current node
            deleteNode(head_ref, current);

            // Update current to the next node
            current = next;
        }
        // If the node does not have the value 'x', move to the next node
        else
            current = current->next;
    }
}

/*
TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list. This is because we traverse the list once to delete all occurrences of 'x'.
SPACE COMPLEXITY: O(1), as we are using constant extra space.
*/
