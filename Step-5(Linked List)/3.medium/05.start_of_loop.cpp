/*
QUESTION:
Given the head of a linked list, write a function to detect and return the first node of the cycle (loop) in the list, if one exists. If no cycle exists, return NULL.

Example:
Input: head = [3, 2, 0, -4] with a cycle at node with value 2.
Output: Node with value 2.

APPROACH:
1. Use two pointers, slow and fast. Initialize both to the head of the list.
2. Move slow one step at a time and fast two steps at a time.
3. If there is a cycle, the slow and fast pointers will eventually meet.
4. Once they meet, reset the slow pointer to the head and move both pointers one step at a time until they meet again. This node is the start of the cycle.
5. If the fast pointer reaches the end of the list (NULL), there is no cycle.

CODE:
*/

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to find the first node of the loop in a linked list
Node* firstNode(Node* head) {
    // Initialize slow and fast pointers to the head of the list
    Node* slow = head;  
    Node* fast = head;  

    // Phase 1: Detect the loop
    while (fast != NULL && fast->next != NULL) {
        // Move slow one step
        slow = slow->next;        
        // Move fast two steps
        fast = fast->next->next;  

        // If slow and fast meet, a loop is detected
        if (slow == fast) {
            // Reset the slow pointer to the head of the list
            slow = head; 

            // Phase 2: Find the first node of the loop
            while (slow != fast) {
                // Move slow and fast one step at a time
                slow = slow->next;  
                fast = fast->next;  
            }
            
            // When slow and fast meet again, it's the first node of the loop
            return slow;  
        }
    }
    
    // If no loop is found, return NULL
    return NULL; 
}

/*
TIME COMPLEXITY:
- O(n) where n is the number of nodes in the linked list.

SPACE COMPLEXITY:
- O(1) as only a constant amount of extra space is used.

EXAMPLE USAGE:
Node* head = new Node(3);
head->next = new Node(2);
head->next->next = new Node(0);
head->next->next->next = new Node(-4);
head->next->next->next->next = head->next;  // Create a loop

Node* loopStart = firstNode(head);
// The loop starts at the node with value 2.
*/
