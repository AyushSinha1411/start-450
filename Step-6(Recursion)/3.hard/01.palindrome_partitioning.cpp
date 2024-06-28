/*
QUESTION:
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Explanation: All possible palindrome partitions of "aab" are returned.

APPROACH:
1. Use a recursive helper function to generate all possible palindrome partitions.
2. At each step, check if the substring from the current index to the next index is a palindrome.
3. If it is a palindrome, include it in the current path and recurse to the next index.
4. Add the path to the result when the end of the string is reached.

CODE:
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if a substring is a palindrome
bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

// Recursive helper function to generate all possible palindrome partitions
void partitionHelper(int index, string s, vector<string>& path, vector<vector<string>>& res) {
    if (index == s.size()) {
        res.push_back(path); // Add the current partition to the result
        return;
    }
    for (int i = index; i < s.size(); ++i) {
        if (isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));
            partitionHelper(i + 1, s, path, res);
            path.pop_back();
        }
    }
}

// Function to return all possible palindrome partitioning of s
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    partitionHelper(0, s, path, res);
    return res;
}

/*
TIME COMPLEXITY: O(2^N * N), where N is the length of the string. This is because there are 2^N possible partitions and each partition takes O(N) time to process.
SPACE COMPLEXITY: O(N), due to the recursion stack for processing each character in the string.
*/
