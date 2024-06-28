/*
QUESTION:
Find the second smallest and second largest elements in an array of integers.

Example:
Input:
arr = [1, 2, 4, 7, 7, 5], n = 6
Output:
Second smallest is 2
Second largest is 5

APPROACH:
To find the second smallest and second largest elements in the array:

1. Initialize two variables for the smallest and second smallest elements with maximum possible value.
2. Iterate through the array:
   - If the current element is smaller than the smallest, update the smallest and second smallest.
   - Else if the current element is smaller than the second smallest and not equal to the smallest, update the second smallest.
3. Similarly, initialize two variables for the largest and second largest elements with minimum possible value.
4. Iterate through the array:
   - If the current element is larger than the largest, update the largest and second largest.
   - Else if the current element is larger than the second largest and not equal to the largest, update the second largest.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the second smallest element in an array
int secondSmallest(int arr[], int n) {
    if (n < 2)
        return -1;
    
    int small = INT_MAX;
    int second_small = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] < small) {
            second_small = small;
            small = arr[i];
        } else if (arr[i] < second_small && arr[i] != small) {
            second_small = arr[i];
        }
    }
    
    return second_small;
}

// Function to find the second largest element in an array
int secondLargest(int arr[], int n) {
    if (n < 2)
        return -1;
    
    int large = INT_MIN;
    int second_large = INT_MIN;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > large) {
            second_large = large;
            large = arr[i];
        } else if (arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }
    
    return second_large;
}

int main() {
    int arr[] = {1, 2, 4, 7, 7, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int sS = secondSmallest(arr, n);
    int sL = secondLargest(arr, n);
    
    cout << "Second smallest is " << sS << endl;
    cout << "Second largest is " << sL << endl;
    
    return 0;
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(1), as no extra space is used.
*/
