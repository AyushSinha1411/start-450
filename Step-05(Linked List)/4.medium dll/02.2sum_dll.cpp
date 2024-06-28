/*
QUESTION:
Given a doubly linked list and a target value, find all pairs of nodes whose values sum up to the given target.

APPROACH:
1. Initialize two pointers, ptr1 and ptr2. Move ptr2 to the end of the linked list.
2. Traverse the list with two pointers from both ends towards the middle.
3. For each pair of nodes, if their sum equals the target, add the pair to the result vector.
4. If the sum is less than the target, move ptr1 forward. If the sum is greater than the target, move ptr2 backward.
5. Continue until the pointers meet or pass each other.

CODE:
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for doubly-linked list.
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

// Function to find pairs in the linked list with given sum
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
    Node *ptr1 = head, *ptr2 = head;
    
    // Moving ptr2 to the end of the linked list
    while (ptr2->next) {
        ptr2 = ptr2->next;
    }

    vector<pair<int, int>> res;
    
    // Checking for pairs until ptr1 and ptr2 meet or pass each other
    while (ptr1 != ptr2 && ptr2->next != ptr1) {
        int sum = ptr1->data + ptr2->data;

        // If sum equals target, add the pair to the results vector
        if (sum == target) {
            res.push_back(make_pair(ptr1->data, ptr2->data));
            ptr1 = ptr1->next;
            ptr2 = ptr2->prev;
        }
        // If sum is less than target, move ptr1 to the next node
        else if (sum < target) {
            ptr1 = ptr1->next;
        }
        // If sum is greater than target, move ptr2 to the previous node
        else {
            ptr2 = ptr2->prev;
        }
    }

    return res; // Returning the results vector
}

/*
TIME COMPLEXITY: O(N), where N is the number of nodes in the linked list. This is because we traverse the list with two pointers.
SPACE COMPLEXITY: O(1), as we are using constant extra space (excluding the space for the result vector).
*/
