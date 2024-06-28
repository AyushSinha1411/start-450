/*
QUESTION:
Given two non-empty singly linked lists representing two non-negative integers, add the two numbers and return the sum as a linked list. The digits are stored in reverse order, and each of their nodes contains a single digit.

APPROACH:
1. Initialize a dummy node to build the result list and a temp pointer to iterate.
2. Use a carry variable to handle sums greater than 9.
3. Traverse both lists, adding corresponding values and the carry.
4. Create new nodes for each digit of the result and link them.
5. Continue until both lists are fully traversed and no carry remains.

CODE:
*/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = 0) : val(x), next(NULL) {}
};

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Initialize dummy node and temp pointer
    ListNode *dummy = new ListNode(); 
    ListNode *temp = dummy; 
    int carry = 0;

    // Traverse both lists and handle carry
    while ((l1 != NULL || l2 != NULL) || carry) {
        int sum = 0; 
        
        // Add value from l1 if available
        if (l1 != NULL) {
            sum += l1->val; 
            l1 = l1->next; 
        }
        
        // Add value from l2 if available
        if (l2 != NULL) {
            sum += l2->val; 
            l2 = l2->next; 
        }
        
        // Add carry
        sum += carry; 
        carry = sum / 10; 
        
        // Create new node for the digit and move temp
        ListNode *node = new ListNode(sum % 10); 
        temp->next = node; 
        temp = temp->next; 
    }

    // Return the result list, excluding dummy node
    return dummy->next; 
}

/*
TIME COMPLEXITY: O(max(N, M)), where N and M are the lengths of the two linked lists. This is because we traverse both lists simultaneously.
SPACE COMPLEXITY: O(max(N, M)), as the space required is for the result linked list, which is at most one node longer than the longer input list due to carry.
*/
