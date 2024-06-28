/*
QUESTION:
Convert a given Roman numeral string to an integer. The input string is guaranteed to be a valid Roman numeral.

Example:
Input: "MCMXCIV"
Output: 1994

APPROACH:
1. Use an unordered_map to store the values of Roman numeral symbols.
2. Start from the end of the string and initialize the last symbol's value.
3. Iterate from the second last character to the first character of the string.
4. For each character:
   a. Retrieve its value from the map.
   b. Compare it with the last character's value.
   c. If the current character's value is less than the last character's value, subtract it from the total.
   d. If the current character's value is greater than or equal to the last character's value, add it to the total.
   e. Update the last character's value to the current character's value.
5. Return the total value.

CODE:
*/

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    static unordered_map<char, int> values;
    
    int romanToInt(string s) {
        // Initialize the last symbol's value
        char lastSymbol = s[s.size() - 1];
        int lastValue = values[lastSymbol];
        int total = lastValue;

        // Iterate from the second last character to the first character
        for (int i = s.size() - 2; i >= 0; i--) {
            char currentSymbol = s[i];
            int currentValue = values[currentSymbol];
            // If the current value is less than the last value, subtract it
            if (currentValue < lastValue) {
                total -= currentValue;
            } else {
                // If the current value is greater than or equal to the last value, add it
                total += currentValue;
            }
            // Update the last value to the current value
            lastValue = currentValue;
        }
        // Return the total value
        return total;
    }
};

// Initialize the unordered_map with Roman numeral values
unordered_map<char, int> Solution::values = {
    {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
    {'X', 10},   {'V', 5},   {'I', 1}
};

/*
TIME COMPLEXITY: O(n), where 'n' is the length of the input string. Each character is processed exactly once.
SPACE COMPLEXITY: O(1), as the space used by the unordered_map is constant and does not depend on the input size.
*/
