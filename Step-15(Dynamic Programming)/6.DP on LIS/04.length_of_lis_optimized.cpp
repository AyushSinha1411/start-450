/*
EXAMPLE:
Input: arr = {10, 9, 2, 5, 3, 7, 101, 18}
Output: 4
Explanation: The LIS is {2, 3, 7, 101}, so the length is 4.

QUESTION:
Given an integer array `arr`, find the length of the longest increasing subsequence (LIS).

APPROACH:
1. Use a temporary vector `temp` to store the elements of the longest increasing subsequence.
2. Initialize the first element of `arr` in `temp`.
3. Iterate through the array starting from the second element.
4. If the current element is greater than the last element of `temp`, append it to `temp` and increment the length.
5. If the current element is not greater, find the position where it can replace an element in `temp` to maintain the increasing order using `lower_bound`.
6. Return the length of `temp`, which is the length of the LIS.

CODE:
*/

// Function to find the length of the longest increasing subsequence
int longestIncreasingSubsequence(int arr[], int n) {
    // Create a temporary vector to store the increasing subsequence
    vector<int> temp;
    temp.push_back(arr[0]);

    int len = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > temp.back()) {
            // If arr[i] is greater than the last element of temp, extend the subsequence
            temp.push_back(arr[i]);
            len++;
        } else {
            // If arr[i] is not greater, replace the element in temp with arr[i]
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    return len;
}

/*
TIME COMPLEXITY:
- O(n log n), where n is the number of elements in the array. Each element is processed in O(log n) time using binary search (`lower_bound`).

SPACE COMPLEXITY:
- O(n), for the temporary vector `temp` used to store the increasing subsequence.

EXAMPLE USAGE:
int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
int n = sizeof(arr) / sizeof(arr[0]);
int result = longestIncreasingSubsequence(arr, n);
cout << "Length of LIS: " << result << endl; // Output: Length of LIS: 4
*/
