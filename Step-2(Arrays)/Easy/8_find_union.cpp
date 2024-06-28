/*
QUESTION:
Find the union of two sorted arrays.

Example:
Input:
arr1 = [1, 2, 4, 5, 6], n = 5
arr2 = [2, 3, 5, 7], m = 4
Output:
The union of the two arrays is: [1, 2, 3, 4, 5, 6, 7]

APPROACH:
1. Initialize two pointers, i and j, to traverse through arr1 and arr2 respectively.
2. Initialize an empty vector Union to store the union of the two arrays.
3. Iterate through both arrays until one of them is exhausted:
   - If the current element of arr1 is less than or equal to the current element of arr2, and it is not a duplicate of the last added element in Union, add it to Union and increment the pointer for arr1.
   - If the current element of arr2 is less than the current element of arr1, and it is not a duplicate of the last added element in Union, add it to Union and increment the pointer for arr2.
4. After the main loop, add any remaining elements from arr1 or arr2 to Union, ensuring no duplicates.
5. Return the Union vector.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the union of two sorted arrays
vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0; // Initialize pointers for arr1 and arr2
    vector<int> Union; // Vector to store the union of the two arrays

    // Traverse both arrays
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) { // If element in arr1 is smaller or equal to element in arr2
            if (Union.size() == 0 || Union.back() != arr1[i]) // Add element to Union if not a duplicate
                Union.push_back(arr1[i]);
            i++; // Move to the next element in arr1
        } else { // If element in arr2 is smaller
            if (Union.size() == 0 || Union.back() != arr2[j]) // Add element to Union if not a duplicate
                Union.push_back(arr2[j]);
            j++; // Move to the next element in arr2
        }
    }
    
    // Add remaining elements from arr1 to Union
    while (i < n) {
        if (Union.back() != arr1[i]) // Add element to Union if not a duplicate
            Union.push_back(arr1[i]);
        i++; // Move to the next element in arr1
    }
    
    // Add remaining elements from arr2 to Union
    while (j < m) {
        if (Union.back() != arr2[j]) // Add element to Union if not a duplicate
            Union.push_back(arr2[j]);
        j++; // Move to the next element in arr2
    }
    
    return Union; // Return the union of the two arrays
}

/*
TIME COMPLEXITY: O(n + m), where n and m are the number of elements in arr1 and arr2 respectively.
SPACE COMPLEXITY: O(n + m), as we store the union of both arrays.
*/
