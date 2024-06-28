/*
QUESTION:
Write a function to calculate the stock span. The stock span is the number of consecutive days leading up to the current day where the stock price was less than or equal to the current day's price.

Example:
Input: prices = [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]
Explanation:
For price 100, the span is 1 (itself).
For price 80, the span is 1 (itself).
For price 60, the span is 1 (itself).
For price 70, the span is 2 (including 60, 70).
For price 60, the span is 1 (itself).
For price 75, the span is 4 (including 70, 60, 80, 100).
For price 85, the span is 6 (including 75, 60, 70, 60, 80, 100).

APPROACH:
1. Use a stack to store pairs of (price, span).
2. For each price, while the stack is not empty and the price at the top of the stack is less than or equal to the current price:
   a. Add the span of the top element to the current span.
   b. Pop the top element from the stack.
3. Push the current price and its span onto the stack.
4. Return the span of the current price.

CODE:
*/

#include <stack>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> stack; // Stack to store pairs of (price, span)
public:
    int next(int price) {
        int span = 1;
        // Calculate the span by popping elements from the stack
        while (!stack.empty() && stack.top().first <= price) {
            span += stack.top().second;
            stack.pop();
        }
        // Push the current price and its span onto the stack
        stack.push({price, span});
        return span;
    }
};

/*
TIME COMPLEXITY: O(N), where N is the number of calls to the next function. This is because each price is pushed and popped from the stack at most once.
SPACE COMPLEXITY: O(N), for the stack used to store the prices and their spans.
*/
