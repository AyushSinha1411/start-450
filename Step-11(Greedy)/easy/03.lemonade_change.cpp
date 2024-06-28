/*
QUESTION:
You are given an array `bills` where `bills[i]` can be either 5, 10, or 20 dollars. You start with an initially empty register. You want to know if you can provide every customer with the correct change.

Example:
Input: bills = [5, 5, 5, 10, 20]
Output: true
Explanation: 
From the input, we can see that you can provide correct change for every customer.

APPROACH:
1. Initialize two counters, `five` and `ten` to keep track of the number of 5 and 10 dollar bills you have.
2. Iterate through each bill in the `bills` array.
3. If the bill is 5, increment the `five` counter.
4. If the bill is 10, decrement the `five` counter and increment the `ten` counter. If you don't have any 5 dollar bills to give as change, return false.
5. If the bill is 20, try to give one 10 dollar bill and one 5 dollar bill as change. If you don't have a 10 dollar bill, try to give three 5 dollar bills as change. If neither is possible, return false.
6. If you manage to provide change for all customers, return true.

CODE:
*/

#include <vector>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int bill : bills) {
        if (bill == 5)
            five++;
        else if (bill == 10) {
            if (five == 0) return false;
            five--;
            ten++;
        } else {
            if (five > 0 && ten > 0) {
                five--;
                ten--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

/*
EXAMPLE USAGE:
int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    bool result = lemonadeChange(bills);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}

TIME COMPLEXITY:
- O(n) where n is the number of bills. We iterate through the `bills` array once.

SPACE COMPLEXITY:
- O(1) since we are using a constant amount of extra space.
*/
