/*
QUESTION:
Given a singly linked list, sort the list in ascending order using the merge sort algorithm.

Example:
Input: head = [4, 2, 1, 3]
Output: head = [1, 2, 3, 4]
Explanation: The list is sorted in ascending order.

APPROACH:
1. Implement the merge sort algorithm by dividing the list into halves and sorting each half recursively.
2. Use a helper function `getMid` to find the middle of the list and split it into two halves.
3. Use a helper function `merge` to merge two sorted lists into one sorted list.
4. The base case for the recursion is when the list is empty or has only one node.

CODE:
*/

// Function to sort the linked list using merge sort
ListNode* sortList(ListNode* head) {
    // Base case: if the list is empty or has only one node, return the head
    if (!head || !head->next) return head;

    // Get the middle of the list
    ListNode* mid = getMid(head);

    // Recursively sort the left half
    ListNode* left = sortList(head);

    // Recursively sort the right half
    ListNode* right = sortList(mid);

    // Merge the two sorted halves
    return merge(left, right);
}

// Helper function to merge two sorted lists
ListNode* merge(ListNode* list1, ListNode* list2) {
    // Dummy head to simplify the merge process
    ListNode dummyHead(0);
    ListNode* ptr = &dummyHead;

    // Merge the two lists
    while (list1 && list2) {
        if (list1->val < list2->val) {
            ptr->next = list1;
            list1 = list1->next;
        } else {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }

    // Append the remaining elements of list1 or list2
    if (list1)
        ptr->next = list1;
    else
        ptr->next = list2;

    return dummyHead.next;
}

// Helper function to find the middle of the list
ListNode* getMid(ListNode* head) {
    ListNode* midPrev = nullptr;
    while (head && head->next) {
        midPrev = (midPrev == nullptr) ? head : midPrev->next;
        head = head->next->next;
    }
    ListNode* mid = midPrev->next;
    midPrev->next = nullptr;
    return mid;
}

/*
TIME COMPLEXITY: O(N log N), where N is the number of nodes in the linked list. This is because we are dividing the list into halves and merging them.
SPACE COMPLEXITY: O(log N) due to the recursion stack space used by the merge sort.
*/
