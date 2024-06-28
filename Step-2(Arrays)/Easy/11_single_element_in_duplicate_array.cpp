/*
QUESTION:
Find the single element in an array where every other element appears twice.

Example:
Input:
arr = [2, 2, 1, 4, 4]
Output:
The single element in the array is: 1

APPROACH:
1. Initialize a variable xorr to 0. This variable will store the result of XORing all elements.
2. Iterate through the array and XOR each element with xorr. The XOR of a number with itself is 0, and the XOR of a number with 0 is the number itself. Thus, pairs of identical elements will cancel each other out, leaving only the single element.
3. Return xorr, which will contain the single element.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the single element in an array
int getSingleElement(vector<int>& arr) {
    // Size of the array
    int n = arr.size();

    // XOR all the elements
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i]; // XOR each element with xorr
    }
    return xorr; // Return the single element
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
