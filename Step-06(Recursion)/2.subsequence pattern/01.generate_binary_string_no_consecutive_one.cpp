
/*
 * Question:
 * Generate all binary strings of length `n` without consecutive 1's using recursion.
 *
 * Approach:
 * 1. Use a recursive helper function to generate the strings.
 * 2. Keep track of the previous character to ensure no consecutive 1's are added.
 * 3. If the previous character is '1', the next character must be '0'.
 * 4. If the previous character is '0', the next character can be either '0' or '1'.
 * 5. Base case: if the length of the current string equals `n`, print the string.
 */

// Recursive helper function to generate binary strings
void generateBinaryStringsHelper(int n, string str, char prev) {
    // Base case: if the length of the string is `n`
    if (str.length() == n) {
        cout << str << endl;
        return;
    }

    // If previous character is '1', next character must be '0'
    if (prev == '1') {
        generateBinaryStringsHelper(n, str + "0", '0');
    }
    // If previous character is '0', next character can be '0' or '1'
    else {
        generateBinaryStringsHelper(n, str + "0", '0');
        generateBinaryStringsHelper(n, str + "1", '1');
    }
}

// Main function to generate binary strings
void generateBinaryStrings(int n) {
    // Start the recursive generation with an empty string
    generateBinaryStringsHelper(n, "", '0');
}

int main() {
    int n = 3;
    generateBinaryStrings(n);
    // Example output for n = 3:
    // 000
    // 001
    // 010
    // 100
    // 101
    return 0;
}

/*
 * Time Complexity:
 * The time complexity is O(2^n) because we explore both possibilities (0 and 1) at each position.
 *
 * Space Complexity:
 * The space complexity is O(n) due to the recursion stack and the string being built.
 */
