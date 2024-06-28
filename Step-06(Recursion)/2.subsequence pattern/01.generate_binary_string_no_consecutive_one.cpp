/*
QUESTION:
Write a function to generate all binary strings of length `num` such that no two consecutive 1s are present.

Example:
Input: num = 3
Output: "000", "001", "010", "100", "101"
Explanation: All binary strings of length 3 without consecutive 1s are generated.

APPROACH:
1. Use a recursive function to generate binary strings.
2. If the current string has reached the desired length, print the string.
3. If the last character of the current string is '1', append '0' to the string and continue recursion.
4. If the last character of the current string is '0', append both '0' and '1' to the string and continue recursion.

CODE:
*/

#include <iostream>
#include <string>
using namespace std;

// Function to generate all binary strings of length 'num' with no consecutive 1s
void All_Binary_Strings(string str, int num) {
    int len = str.length();
    
    // Base case: if the current string has reached the desired length
    if (len == num) {
        cout << str << " ";
        return;
    }

    // If the last character is '1', append '0' and continue recursion
    if (str[len - 1] == '1') {
        All_Binary_Strings(str + '0', num);
    } 
    // If the last character is '0', append both '0' and '1' and continue recursion
    else {
        All_Binary_Strings(str + '0', num);
        All_Binary_Strings(str + '1', num);
    }
}

/*
TIME COMPLEXITY: O(2^N), where N is the length of the binary string. This is because each position can either be '0' or '1', leading to 2^N combinations.
SPACE COMPLEXITY: O(N), due to the recursion stack for processing each character in the string.
*/
