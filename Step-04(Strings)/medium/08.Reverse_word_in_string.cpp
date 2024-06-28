/*
QUESTION:
Given a string s, reverse the order of words in the string. A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space. The returned string should only have a single space separating the words and no leading or trailing spaces.

Example:
Input: "  hello world  "
Output: "world hello"

APPROACH:
1. Trim leading and trailing spaces from the input string.
2. Use a deque to store the words in reverse order.
3. Iterate through the string to extract words and push them to the front of the deque.
4. Construct the result string by concatenating the words from the deque, separated by a single space.

CODE:
*/

#include <string>
#include <deque>
using namespace std;

string reverseWords(string s) {
    int left = 0, right = s.size() - 1;

    // Trim leading spaces
    while (left <= right && s[left] == ' ') {
        ++left;
    }
    
    // Trim trailing spaces
    while (left <= right && s[right] == ' ') {
        --right;
    }

    deque<string> d;
    string word;

    // Extract words and push them to the front of the deque
    while (left <= right) {
        if (s[left] == ' ' && !word.empty()) {
            d.push_front(word);
            word.clear();
        } else if (s[left] != ' ') {
            word += s[left];
        }
        ++left;
    }
    d.push_front(word); // Add the last word

    // Construct the result string from the deque
    string result;
    while (!d.empty()) {
        result += d.front();
        d.pop_front();
        if (!d.empty()) {
            result += " ";
        }
    }
    return result;
}

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the input string. Each character is processed a constant number of times.
SPACE COMPLEXITY: O(n), where 'n' is the length of the input string. The deque and the result string use additional space proportional to the input size.
*/
