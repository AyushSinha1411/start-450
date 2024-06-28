/*
QUESTION:
Given the head of a linked list, write a function to segregate the list into odd and even nodes. Odd nodes should appear before even nodes while preserving the original relative order of odd and even nodes.

Example:
Input: head = [1, 2, 3, 4, 5]
Output: head = [1, 3, 5, 2, 4]

APPROACH:
1. Create two dummy nodes to represent the heads of the odd and even lists.
2. Traverse the original list, breaking links and segregating nodes into the odd and even lists.
3. Connect the end of the even list to the beginning of the odd list.
4. Return the new head of the combined list.

CODE:
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* SegregateToOddEven(ListNode* head) {
    // Creating heads of odd and even linked lists
    ListNode* oddHead = new ListNode(-1);
    ListNode* oddTail = oddHead;
    ListNode* evenHead = new ListNode(-1);
    ListNode* evenTail = evenHead;
    ListNode* curr = head;

    while (curr) {
        // Breaking the link of the current node
        ListNode* temp = curr;
        curr = curr->next;
        temp->next = nullptr;

        if (temp->val & 1) { // If odd node, append to odd linked list
            oddTail->next = temp;
            oddTail = temp;
        } else { // If even node, append to even linked list
            evenTail->next = temp;
            evenTail = temp;
        }
    }

    // Appending odd linked list at the end of even linked list
    evenTail->next = oddHead->next; 

    // Returning the head of the segregated list
    return evenHead->next;
}

/*
TIME COMPLEXITY:
- O(n) for traversing the linked list where n is the number of nodes in the list.

SPACE COMPLEXITY:
- O(1) as we are only using extra pointers and not additional memory proportional to input size.

EXAMPLE USAGE:
ListNode* head = new ListNode(1);
head->next = new ListNode(2);
head->next->next = new ListNode(3);
head->next->next->next = new ListNode(4);
head->next->next->next->next = new ListNode(5);
ListNode* segregatedHead = SegregateToOddEven(head);
// The segregated list should be [1, 3, 5, 2, 4].
*/
