/*
QUESTION:
Find the majority element in an array, which is the element that appears more than n/2 times, where n is the size of the array. If no such element exists, return -1.

Example:
Input:
v = [3, 3, 4, 2, 4, 4, 2, 4, 4]
Output:
The majority element is: 4

APPROACH:
1. Initialize two variables, cnt (count) and el (element). cnt is used to count occurrences, and el stores the potential majority element.
2. Iterate through the array using the Boyer-Moore Voting Algorithm:
   - If cnt is 0, set el to the current element and cnt to 1.
   - If el is equal to the current element, increment cnt.
   - If el is not equal to the current element, decrement cnt.
3. After the first pass, el will be the candidate for the majority element.
4. Verify if el is indeed the majority element by counting its occurrences in the array.
5. If the count is greater than n/2, return el. Otherwise, return -1.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the majority element in an array
int majorityElement(vector<int> v) {
    // Size of the given array
    int n = v.size();
    int cnt = 0; // Initialize count
    int el; // Element to store the potential majority element

    // Applying the Boyer-Moore Voting Algorithm
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        } else if (el == v[i]) {
            cnt++;
        } else {
            cnt--;
        }
    }

    // Verify if the stored element is the majority element
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    // Check if the candidate element appears more than n/2 times
    if (cnt1 > (n / 2)) return el;
    return -1; // Return -1 if no majority element exists
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
