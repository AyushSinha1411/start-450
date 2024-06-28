/*
QUESTION:
Given a singly linked list containing 0s, 1s, and 2s, sort the list such that all 0s come first, followed by 1s, and then 2s. The sorting should be done by changing the pointers of the nodes.

Example:
Input: head = [1, 2, 0, 1, 2, 0, 0, 1]
Output: head = [0, 0, 0, 1, 1, 1, 2, 2]
Explanation: The list is sorted such that all 0s are at the beginning, followed by 1s, and then 2s.

APPROACH:
1. Create three dummy nodes to point to the beginning of three linked lists for 0s, 1s, and 2s.
2. Traverse the original list and link nodes to the respective lists based on their values.
3. Attach the three lists together to form the sorted list.
4. Return the head of the new sorted list.

CODE:
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to sort a linked list of 0s, 1s, and 2s by changing pointers
Node* sortList(Node* head) {
    // If the list is empty or has only one node, return the head
    if (!head || !(head->next)) 
        return head; 
  
    // Create three dummy nodes to point to the beginning of three linked lists
    Node* zeroD = new Node(0); 
    Node* oneD = new Node(0); 
    Node* twoD = new Node(0); 
  
    // Initialize current pointers for the three lists
    Node *zero = zeroD, *one = oneD, *two = twoD; 
  
    // Traverse the list
    Node* curr = head; 
    while (curr) { 
        if (curr->data == 0) { 
            zero->next = curr; 
            zero = zero->next; 
        } 
        else if (curr->data == 1) { 
            one->next = curr; 
            one = one->next; 
        } 
        else { 
            two->next = curr; 
            two = two->next; 
        } 
        curr = curr->next; 
    } 
  
    // Attach the three lists together
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next); 
    one->next = twoD->next; 
    two->next = NULL; 
  
    // Update the head to the new sorted list
    head = zeroD->next; 
  
    // Delete the dummy nodes
    delete zeroD; 
    delete oneD; 
    delete twoD; 
  
    return head; 
}

/*


TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list.
SPACE COMPLEXITY: O(1), as we are using constant extra space for the dummy nodes.
*/
