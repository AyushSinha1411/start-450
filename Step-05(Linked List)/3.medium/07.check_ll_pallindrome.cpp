/*
QUESTION:
Given a singly linked list, determine if it is a palindrome.

Example:
Input: 1 -> 2 -> 3 -> 2 -> 1
Output: true
Explanation: The linked list is the same forward and backward.

APPROACH:
1. Use two pointers (slow and fast) to find the middle of the linked list.
2. Reverse the second half of the linked list.
3. Compare the first half with the reversed second half.
4. Restore the original linked list by reversing the second half again.
5. Return true if the linked list is a palindrome, otherwise return false.

CODE:
*/

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to reverse a linked list
Node* reverseLinkedList(Node* head) {
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        // No change is needed; return the current head
        return head;
    }

    // Recursive step: Reverse the remaining part of the list and get the new head
    Node* newHead = reverseLinkedList(head->next);

    // Store the next node in 'front' to reverse the link
    Node* front = head->next;

    // Update the 'next' pointer of 'front' to point to the current head, effectively reversing the link direction
    front->next = head;

    // Set the 'next' pointer of the current head to 'null' to break the original link
    head->next = NULL;

    // Return the new head obtained from the recursion
    return newHead;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    // Check if the linked list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        // It's a palindrome by definition
        return true;
    }
    
    // Initialize two pointers, slow and fast, to find the middle of the linked list
    Node* slow = head;
    Node* fast = head;
    
    // Traverse the linked list to find the middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        // Move slow pointer one step at a time
        slow = slow->next;
        // Move fast pointer two steps at a time
        fast = fast->next->next;
    }
    
    // Reverse the second half of the linked list starting from the middle
    Node* newHead = reverseLinkedList(slow->next);
    
    // Pointer to the first half
    Node* first = head;
    
    // Pointer to the reversed second half
    Node* second = newHead;
    
    while (second != NULL) {
        // Compare data values of nodes from both halves
        if (first->data != second->data) {
            // Reverse the second half back to its original state
            reverseLinkedList(newHead);
            // Not a palindrome
            return false;
        }
        // Move the first pointer
        first = first->next;
        // Move the second pointer
        second = second->next;
    }
    
    // Reverse the second half back to its original state
    reverseLinkedList(newHead);
    
    // The linked list is a palindrome
    return true;
}

/*
TIME COMPLEXITY:
- O(n) for traversing the linked list and comparing the elements.

SPACE COMPLEXITY:
- O(1) for additional space used, excluding the space for the nodes themselves.

EXAMPLE USAGE:
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);
head->next->next->next = new Node(2);
head->next->next->next->next = new Node(1);
bool result = isPalindrome(head);
// The result should be true as the list is a palindrome.
*/
