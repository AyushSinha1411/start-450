/*
QUESTION:
Given an array of strings, find the longest common prefix among all the strings in the array. If there is no common prefix, return an empty string.

Example:
Input: ["flower", "flow", "flight"]
Output: "fl"

APPROACH:
1. Use a divide-and-conquer method to recursively find the longest common prefix.
2. If the array is empty, return an empty string.
3. Divide the array into two halves and recursively find the longest common prefix for each half.
4. Merge the results from the two halves by finding the common prefix between them.
5. Continue this process until the entire array has been processed.

CODE:
*/

#include <string>
#include <vector>
using namespace std;

// Function to find the longest common prefix in an array of strings
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    // Call the recursive function with the full range of the array
    return longestCommonPrefix(strs, 0, strs.size() - 1);
}

// Recursive function to find the longest common prefix in a range of the array
string longestCommonPrefix(vector<string>& strs, int l, int r) {
    if (l == r) {
        // Base case: if the range has only one string, return it
        return strs[l];
    } else {
        // Divide the range into two halves
        int mid = (l + r) / 2;
        // Recursively find the longest common prefix in the left half
        string lcpLeft = longestCommonPrefix(strs, l, mid);
        // Recursively find the longest common prefix in the right half
        string lcpRight = longestCommonPrefix(strs, mid + 1, r);
        // Find the common prefix between the results of the two halves
        return commonPrefix(lcpLeft, lcpRight);
    }
}

// Function to find the common prefix between two strings
string commonPrefix(string left, string right) {
    int minLength = std::min(left.length(), right.length());
    // Compare characters of the two strings one by one
    for (int i = 0; i < minLength; i++) {
        if (left[i] != right[i]) {
            // Return the substring up to the point where they differ
            return left.substr(0, i);
        }
    }
    // If one string is a prefix of the other, return the shorter string
    return left.substr(0, minLength);
}

/*
TIME COMPLEXITY: O(S), where 'S' is the sum of all characters in all strings. In the worst case, we compare each character of all strings.
SPACE COMPLEXITY: O(m * log(n)), where 'm' is the length of the longest string, and 'n' is the number of strings. This is due to the recursion stack.
*/
