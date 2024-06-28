/*
QUESTION:
Remove duplicates from a sorted array and return the new length of the array.

Example:
Input:
arr = [1, 1, 2, 2, 2, 3, 3], n = 7
Output:
The array after removing duplicate elements is 1 2 3

APPROACH:
To remove duplicates from a sorted array:
1. Use two pointers to track the position of unique elements.
2. Iterate through the array with the second pointer.
3. When a new unique element is found, move it to the next position in the result using the first pointer.
4. Return the length of the new array with unique elements.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to remove duplicates from a sorted array
int removeDuplicates(int arr[], int n) {
    int i = 0; // Initialize the first pointer
    for (int j = 1; j < n; j++) { // Iterate with the second pointer
        if (arr[i] != arr[j]) { // If a new unique element is found
            i++; // Move the first pointer
            arr[i] = arr[j]; // Update the position with the new unique element
        }
    }
    return i + 1; // Return the new length of the array with unique elements
}

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = removeDuplicates(arr, n); // Get the new length after removing duplicates
    cout << "The array after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++) { // Print the new array
        cout << arr[i] << " ";
    }
    return 0;
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
