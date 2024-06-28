/*
QUESTION:
Write a function to simulate the collision of asteroids. Each asteroid moves at the same speed. An asteroid moving right will collide with an asteroid moving left. When two asteroids collide, the smaller one will explode. If they are the same size, both will explode. Given an array representing the size and direction of asteroids, return the state of the asteroids after all collisions.

Example:
Input: asteroids = [5, 10, -5]
Output: [5, 10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

APPROACH:
1. Use a stack to simulate the collision process.
2. Iterate through each asteroid in the input array.
3. If the stack is empty or the current asteroid is moving right (positive), push it onto the stack.
4. If the current asteroid is moving left (negative), handle the collision:
   a. Pop asteroids from the stack while there is a collision and the asteroid in the stack is smaller than the current asteroid.
   b. If an asteroid in the stack is the same size as the current asteroid, both explode.
   c. If an asteroid in the stack is larger, the current asteroid explodes.
5. After processing all asteroids, return the remaining asteroids in the stack.

CODE:
*/

#include <bits/stdc++.h>
using namespace std;

// Function to simulate the collision of asteroids
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int asteroid : asteroids) {
        int flag = 1;
        while (!st.empty() && (st.top() > 0 && asteroid < 0)) {
            // If the top asteroid in the stack is smaller, then it will explode.
            // Hence pop it from the stack, also continue with the next asteroid in the stack.
            if (abs(st.top()) < abs(asteroid)) {
                st.pop();
                continue;
            }
            // If both asteroids are the same size, then both asteroids will explode.
            // Pop the asteroid from the stack; also, we won't push the current asteroid to the stack.
            else if (abs(st.top()) == abs(asteroid)) {
                st.pop();
            }

            // If we reach here, the current asteroid will be destroyed
            // Hence, we should not add it to the stack
            flag = 0;
            break;
        }

        if (flag) {
            st.push(asteroid);
        }
    }

    // Add the asteroids from the stack to the vector in the reverse order.
    vector<int> remainingAsteroids(st.size());
    for (int i = remainingAsteroids.size() - 1; i >= 0; i--) {
        remainingAsteroids[i] = st.top();
        st.pop();
    }

    return remainingAsteroids;
}

/*
TIME COMPLEXITY: O(N), where N is the number of asteroids. This is because each asteroid is pushed and popped from the stack at most once.
SPACE COMPLEXITY: O(N), for the stack to store the remaining asteroids.
*/
