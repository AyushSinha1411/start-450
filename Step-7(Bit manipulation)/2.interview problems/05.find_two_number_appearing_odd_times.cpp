/*
QUESTION:
Write a function to find two numbers that occur an odd number of times in an array. The array contains exactly two numbers that occur an odd number of times, while all other numbers occur an even number of times.

Example:
Input: Arr = [4, 2, 4, 5, 2, 3, 3, 1], N = 8
Output: [1, 5]
Explanation: The numbers 1 and 5 occur an odd number of times in the array.

APPROACH:
1. XOR all the elements of the array. The result will be the XOR of the two odd occurring numbers.
2. Find a set bit in the XOR result. This bit will be different in the two odd occurring numbers.
3. Divide the array elements into two sets based on this set bit.
4. XOR the elements in each set. The result will be the two odd occurring numbers.
5. Return the two numbers.

CODE:
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find two odd occurring numbers in an array
vector<long long int> twoOddNum(long long int Arr[], long long int N) {
    long long int xor2 = Arr[0]; // Will hold XOR of two odd occurring elements
    long long int set_bit_no; // Will have only single set bit of xor2
    long long int x = 0, y = 0;

    // Get the xor of all elements in Arr[]. The xor will basically be xor of two odd occurring elements
    for (long long int i = 1; i < N; i++) {
        xor2 = xor2 ^ Arr[i];
    }

    // Get one set bit in the xor2. We get rightmost set bit in the following line as it is easy to get
    set_bit_no = xor2 & ~(xor2 - 1);

    // Now divide elements in two sets:
    // 1) The elements having the corresponding bit as 1.
    // 2) The elements having the corresponding bit as 0.
    for (long long int i = 0; i < N; i++) {
        // XOR of first set is finally going to hold one odd occurring number x
        if (Arr[i] & set_bit_no)
            x = x ^ Arr[i];
        // XOR of second set is finally going to hold the other odd occurring number y
        else
            y = y ^ Arr[i];
    }

    // Creating a vector to store the two odd occurring numbers.
    vector<long long int> v;
    v.push_back(max(x, y)); // Inserting maximum odd occurring number into vector
    v.push_back(min(x, y)); // Inserting minimum odd occurring number into vector
    return v;
}

/*
TIME COMPLEXITY: O(N), where N is the size of the array. This is because we iterate through the array elements twice.
SPACE COMPLEXITY: O(1), as no additional space is required beyond the input parameters and the vector to store the result.
*/