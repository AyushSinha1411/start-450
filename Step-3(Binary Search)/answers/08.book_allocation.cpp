/*
QUESTION:
You are given an array 'arr' representing the number of pages in 'n' books, and 'm' students. You have to allocate books to 'm' students such that each student gets at least one book and the maximum number of pages allocated to a student is minimized. Find the maximum possible number of pages allocated to a student.

Example:
Input:
arr = [12, 34, 67, 90], n = 4, m = 2
Output:
113 // The maximum possible number of pages allocated to a student is 113.

APPROACH:
1. Define a helper function 'countStudents' to count the number of students required for a given maximum number of pages.
2. Use binary search to find the minimum maximum number of pages allocated to a student.
3. Initialize low to the maximum number of pages in a single book and high to the sum of all pages in all books.
4. In each iteration of the binary search:
    a. Calculate the mid value.
    b. Count the number of students required for this mid value using the 'countStudents' function.
    c. If the number of students required is greater than 'm', update low to mid + 1; otherwise, update high to mid - 1.
5. Return low, which represents the minimum maximum number of pages allocated to a student.

CODE:
*/

#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); // Size of array
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            // Add pages to current student
            pagesStudent += arr[i];
        } else {
            // Add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    // Book allocation impossible
    if (m > n) return -1;

    // Initialize binary search range
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    // Apply binary search
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate mid value
        // Count the number of students required for this mid value
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1; // Update low
        } else {
            high = mid - 1; // Update high
        }
    }
    return low; // Return the minimum maximum number of pages allocated to a student
}

/*
TIME COMPLEXITY: O(n log d), where n is the size of the arr array and d is the difference between the maximum and minimum possible values of pages allocated to a student.
SPACE COMPLEXITY: O(1), as only a constant amount of extra space is used.
*/
