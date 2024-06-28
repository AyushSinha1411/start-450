/*
QUESTION:
Given an array of integers, rearrange the array such that positive and negative numbers are arranged alternatively. If there are more positive or negative numbers, place them at the end of the array.

Example:
Input:
A = [-1, 2, -3, 4, 5, -6, 7, 8]
Output:
The rearranged array is: [2, -1, 4, -3, 5, -6, 7, 8]

APPROACH:
1. Define two vectors, one for storing positive numbers (pos) and the other for negative numbers (neg).
2. Segregate the array into positives and negatives by iterating through it and pushing positive numbers to the pos vector and negative numbers to the neg vector.
3. If the size of the pos vector is less than the size of the neg vector:
   - Fill the array alternatively with elements from pos and neg vectors until the number of positives and negatives are equal.
   - Fill the remaining negative numbers at the end of the array.
4. If the size of the neg vector is less than the size of the pos vector, follow a similar process but fill the remaining positive numbers at the end of the array.
5. Return the rearranged array.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to rearrange the array by sign
vector<int> RearrangebySign(vector<int> A, int n) {
    // Define vectors to store positive and negative elements
    vector<int> pos; // Vector for positive elements
    vector<int> neg; // Vector for negative elements
  
    // Segregate the array into positives and negatives
    for(int i = 0; i < n; i++) {
        if(A[i] > 0)
            pos.push_back(A[i]); // Push positive elements to pos vector
        else
            neg.push_back(A[i]); // Push negative elements to neg vector
    }
  
    // If positives are lesser than negatives
    if(pos.size() < neg.size()) {
        // Fill array alternatively until the number of positives and negatives are equal
        for(int i = 0; i < pos.size(); i++) {
            A[2 * i] = pos[i]; // Fill positive elements at even indices
            A[2 * i + 1] = neg[i]; // Fill negative elements at odd indices
        }
        // Fill the remaining negatives at the end of the array
        int index = pos.size() * 2; // Calculate the starting index for remaining negatives
        for(int i = pos.size(); i < neg.size(); i++) {
            A[index] = neg[i]; // Fill remaining negative elements
            index++;
        }
    }
    // If negatives are lesser than positives
    else {
        // Fill array alternatively until the number of positives and negatives are equal
        for(int i = 0; i < neg.size(); i++) {
            A[2 * i] = pos[i]; // Fill positive elements at even indices
            A[2 * i + 1] = neg[i]; // Fill negative elements at odd indices
        }
        // Fill the remaining positives at the end of the array
        int index = neg.size() * 2; // Calculate the starting index for remaining positives
        for(int i = neg.size(); i < pos.size(); i++) {
            A[index] = pos[i]; // Fill remaining positive elements
            index++;
        }
    }
    return A; // Return the rearranged array
}

/*
TIME COMPLEXITY: O(N), where N is the number of elements in the array.
SPACE COMPLEXITY: O(N), as extra space is used for storing positive and negative elements.
*/
