/*
QUESTION:
Given the head of a linked list, determine if the linked list has a cycle in it.

Example:
Input: head = [3,2,0,-4] with pos = 1 (tail connects to the second node)
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the second node.

APPROACH:
1. Use two pointers (slow and fast) to traverse the linked list.
2. Move the slow pointer one step at a time and the fast pointer two steps at a time.
3. If the slow pointer and the fast pointer meet, there is a cycle in the list.
4. If the fast pointer reaches the end of the list, there is no cycle.

CODE:
*/

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

bool detectCycle(Node* head) {
    // Initialize two pointers, slow and fast, to the head of the linked list
    Node* slow = head;
    Node* fast = head;

    // Traverse the linked list with the slow and fast pointers
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step
        slow = slow->next;
        // Move fast two steps
        fast = fast->next->next;

        // Check if slow and fast pointers meet
        if (slow == fast) {
            return true;  // Loop detected
        }
    }

    // If fast reaches the end of the list, there is no loop
    return false;
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
bool result = detectCycle(head);
// The result should be true as there is a cycle in the list.
*/
