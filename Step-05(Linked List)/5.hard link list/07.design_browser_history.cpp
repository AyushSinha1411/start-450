/*
Question:
Design a data structure that supports the following functions of a web browser:
1. Browser(homepage): Set the homepage of the browser.
2. Visit(url): Visit the URL from the current page. It clears up all the forward history.
3. Back(steps): Move 'steps' backward in the browser history.
4. Forward(steps): Move 'steps' forward in the browser history.

Example:
Browser browser("leetcode.com");
browser.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browser.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browser.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browser.back(1);                   // You are in "youtube.com", move back to "facebook.com"
browser.back(1);                   // You are in "facebook.com", move back to "google.com"
browser.forward(1);                // You are in "google.com", move forward to "facebook.com"
browser.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browser.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browser.back(2);                   // You are in "linkedin.com", move back to "google.com"
browser.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com".

Approach:
1. Use a doubly linked list to store the history of visited pages.
2. Each node in the linked list represents a webpage.
3. The `Browser` class maintains a pointer to the current page.
4. Implement the methods to navigate through the history using the pointers in the doubly linked list.

Time Complexity:
- Browser(homepage): O(1)
- Visit(url): O(1)
- Back(steps): O(steps)
- Forward(steps): O(steps)

Space Complexity: O(n), where n is the number of pages in the history.
*/

class Node {
public:
    string data;    // Stores the URL of the page
    Node* next;     // Pointer to the next page
    Node* back;     // Pointer to the previous page

    // Constructor to initialize a node with a given URL
    Node(string x) : data(x), next(nullptr), back(nullptr) {}
};

class Browser {
    Node* currentPage;    // Pointer to the current page
public:
    // Constructor to initialize the browser with a homepage
    Browser(string homepage) {
        currentPage = new Node(homepage);
    }

    // Method to visit a new URL
    void visit(string url) {
        Node* newNode = new Node(url);      // Create a new node for the URL
        currentPage->next = newNode;        // Link the current page to the new node
        newNode->back = currentPage;        // Link the new node back to the current page
        currentPage = newNode;              // Move the current page pointer to the new node
    }

    // Method to move back a given number of steps
    string back(int steps) {
        while (steps > 0 && currentPage->back != nullptr) {
            currentPage = currentPage->back;    // Move the current page pointer back
            steps--;
        }
        return currentPage->data;               // Return the URL of the current page
    }

    // Method to move forward a given number of steps
    string forward(int steps) {
        while (steps > 0 && currentPage->next != nullptr) {
            currentPage = currentPage->next;    // Move the current page pointer forward
            steps--;
        }
        return currentPage->data;               // Return the URL of the current page
    }
};
/*
Question:
Design a data structure that supports the following functions of a web browser:
1. Browser(homepage): Set the homepage of the browser.
2. Visit(url): Visit the URL from the current page. It clears up all the forward history.
3. Back(steps): Move 'steps' backward in the browser history.
4. Forward(steps): Move 'steps' forward in the browser history.

Example:
Browser browser("leetcode.com");
browser.visit("google.com");       // You are in "leetcode.com". Visit "google.com"
browser.visit("facebook.com");     // You are in "google.com". Visit "facebook.com"
browser.visit("youtube.com");      // You are in "facebook.com". Visit "youtube.com"
browser.back(1);                   // You are in "youtube.com", move back to "facebook.com"
browser.back(1);                   // You are in "facebook.com", move back to "google.com"
browser.forward(1);                // You are in "google.com", move forward to "facebook.com"
browser.visit("linkedin.com");     // You are in "facebook.com". Visit "linkedin.com"
browser.forward(2);                // You are in "linkedin.com", you cannot move forward any steps.
browser.back(2);                   // You are in "linkedin.com", move back to "google.com"
browser.back(7);                   // You are in "google.com", you can move back only one step to "leetcode.com".

Approach:
1. Use a doubly linked list to store the history of visited pages.
2. Each node in the linked list represents a webpage.
3. The `Browser` class maintains a pointer to the current page.
4. Implement the methods to navigate through the history using the pointers in the doubly linked list.
*/

class Node {
public:
    string data;    // Stores the URL of the page
    Node* next;     // Pointer to the next page
    Node* back;     // Pointer to the previous page

    // Constructor to initialize a node with a given URL
    Node(string x) : data(x), next(nullptr), back(nullptr) {}
};

class Browser {
    Node* currentPage;    // Pointer to the current page
public:
    // Constructor to initialize the browser with a homepage
    Browser(string homepage) {
        currentPage = new Node(homepage);
    }

    // Method to visit a new URL
    void visit(string url) {
        Node* newNode = new Node(url);      // Create a new node for the URL
        currentPage->next = newNode;        // Link the current page to the new node
        newNode->back = currentPage;        // Link the new node back to the current page
        currentPage = newNode;              // Move the current page pointer to the new node
    }

    // Method to move back a given number of steps
    string back(int steps) {
        while (steps > 0 && currentPage->back != nullptr) {
            currentPage = currentPage->back;    // Move the current page pointer back
            steps--;
        }
        return currentPage->data;               // Return the URL of the current page
    }

    // Method to move forward a given number of steps
    string forward(int steps) {
        while (steps > 0 && currentPage->next != nullptr) {
            currentPage = currentPage->next;    // Move the current page pointer forward
            steps--;
        }
        return currentPage->data;               // Return the URL of the current page
    }
};
/*Time Complexity:
- Browser(homepage): O(1)
- Visit(url): O(1)
- Back(steps): O(steps)
- Forward(steps): O(steps)

Space Complexity: O(n), where n is the number of pages in the history.*/
