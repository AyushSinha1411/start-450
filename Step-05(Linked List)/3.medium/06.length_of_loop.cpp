/*
QUESTION:
Given the head of a linked list, determine the length of the loop (if any) in the linked list.

Example:
Input: head = [3,2,0,-4] with pos = 1 (tail connects to the second node)
Output: 3
Explanation: There is a cycle in the linked list, where the tail connects to the second node, and the length of the cycle is 3.

APPROACH:
1. Use two pointers (slow and fast) to traverse the linked list to detect a loop.
2. Move the slow pointer one step at a time and the fast pointer two steps at a time.
3. If the slow pointer and the fast pointer meet, there is a loop in the list.
4. Traverse the loop with one pointer to count the number of nodes in the loop.
5. Return the count of nodes in the loop.

CODE:
*/

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to count the number of nodes in the loop
int findLength(Node* slow, Node* fast) {
    // Initialize the count to 1 (current node)
    int cnt = 1;
    
    // Move fast pointer one step
    fast = fast->next;
    
    // Traverse the loop until fast reaches back to slow
    while (slow != fast) {
        // Increment the count
        cnt++;
        // Move the fast pointer one step
        fast = fast->next;
    }
    
    // Return the count of nodes in the loop
    return cnt;
}

// Function to find the length of the loop in a linked list
int lengthOfLoop(Node* head) {
    // Initialize slow and fast pointers to the head of the linked list
    Node* slow = head;
    Node* fast = head;

    // Step 1: Traverse the list to detect a loop
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow pointer one step
        slow = slow->next;     
        // Move fast pointer two steps
        fast = fast->next->next;

        // Step 2: If the slow and fast pointers meet, there is a loop
        if (slow == fast) {
            // Return the number of nodes in the loop
            return findLength(slow, fast);
        }
    }

    // Step 3: If the fast pointer reaches the end, there is no loop
    return 0; 
}

/*
TIME COMPLEXITY:
- O(n) for traversing the linked list.

SPACE COMPLEXITY:
- O(1) for additional space used by the two pointers.

EXAMPLE USAGE:
Node* head = new Node(3);
head->next = new Node(2);
head->next->next = new Node(0);
head->next->next->next = new Node(-4);
head->next->next->next->next = head->next; // Create a cycle
int result = lengthOfLoop(head);
// The result should be 3 as the length of the loop is 3.
*/
