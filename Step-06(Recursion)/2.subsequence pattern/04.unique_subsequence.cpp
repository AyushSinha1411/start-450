/*
QUESTION:
Given two strings, determine which string has more unique subsequences. Return the string with the greater number of unique subsequences. If both have the same number, return the first string.

Example:
Input: str1 = "abc", str2 = "abcd"
Output: "abcd"
Explanation: The string "abc" has 8 unique subsequences, while "abcd" has 16 unique subsequences. Hence, "abcd" is returned.

APPROACH:
1. Use a recursive function to generate all subsequences of a string and store them in an unordered_set to ensure uniqueness.
2. Compare the sizes of the sets of unique subsequences for both strings.
3. Return the string with the greater number of unique subsequences.

CODE:
*/
// Recursive function to generate all unique subsequences of a string
void generateSubsequences(const string& s, int index, string current, unordered_set<string>& subseqSet) {
    if (index == s.length()) {
        subseqSet.insert(current);
        return;
    }

    // Include current character
    generateSubsequences(s, index + 1, current + s[index], subseqSet);

    // Exclude current character
    generateSubsequences(s, index + 1, current, subseqSet);
}

// Function to determine which string has more unique subsequences
string betterString(const string& str1, const string& str2) {
    unordered_set<string> set1, set2;

    generateSubsequences(str1, 0, "", set1);
    generateSubsequences(str2, 0, "", set2);

    return (set2.size() > set1.size()) ? str2 : str1;
}
/*
TIME COMPLEXITY: O(2^N), where N is the length of the string. This is because there are 2^N possible subsequences for a string of length N.
SPACE COMPLEXITY: O(2^N), due to the storage of unique subsequences in the set and the recursion stack.
*/
