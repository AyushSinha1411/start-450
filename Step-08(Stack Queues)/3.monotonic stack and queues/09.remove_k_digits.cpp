/*
QUESTION:
Write a function to remove k digits from the input number string num to make it the smallest possible number. The result should not contain any leading zeros.

Example:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

APPROACH:
1. Use a deque to store the digits of the resulting number.
2. Iterate over each digit in the input string num.
3. For each digit, while the deque is not empty, the last element in the deque is greater than the current digit, and we still have digits to remove (k > 0):
   a. Remove the last element from the deque.
   b. Decrease k by 1.
4. Push the current digit onto the deque.
5. After iterating through the string, if there are still digits to remove (k > 0), remove the remaining digits from the back of the deque.
6. Build the result string from the digits in the deque while removing any leading zeros.
7. Return the result string. If the result string is empty, return "0".

CODE:
*/

#include <string>
#include <deque>
using namespace std;

// Function to remove k digits from the input number string to make it the smallest possible number
string removeKdigits(string num, int k) {
    deque<char> stack;

    // Iterate over each digit in the input string
    for (char digit : num) {
        // Remove the last elements from the deque while they are greater than the current digit
        while (!stack.empty() && k > 0 && stack.back() > digit) {
            stack.pop_back();
            k -= 1;
        }
        stack.push_back(digit);
    }

    // Remove the remaining digits if k > 0
    while (k > 0) {
        stack.pop_back();
        k--;
    }

    // Build the result string from the deque while removing leading zeros
    string ret = "";
    bool leadingZero = true;
    for (char digit : stack) {
        if (leadingZero && digit == '0') continue;
        leadingZero = false;
        ret += digit;
    }

    // Return the final string, if it is empty, return "0"
    return ret.empty() ? "0" : ret;
}

/*
TIME COMPLEXITY: O(N), where N is the length of the input string. This is because each digit is pushed and popped from the deque at most once.
SPACE COMPLEXITY: O(N), for the deque to store the digits.
*/
