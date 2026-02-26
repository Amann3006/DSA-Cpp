#include <bits/stdc++.h>
using namespace std;

/* Function to determine the state of
   asteroids after all collisions */
vector<int> asteroidCollision(vector<int> &asteroids) {

    vector<int> st;   // acts like a stack

    for (int i = 0; i < asteroids.size(); i++) {

        // If asteroid is moving right, push it
        if (asteroids[i] > 0) {
            st.push_back(asteroids[i]);
        }
        else {
            // asteroid is moving left
            while (!st.empty() && st.back() > 0 &&
                   st.back() < abs(asteroids[i])) {
                st.pop_back();   // destroy smaller right-moving asteroid
            }

            // If both asteroids are equal in size
            if (!st.empty() && st.back() == abs(asteroids[i])) {
                st.pop_back();   // destroy both
            }
            // If stack is empty or top is left-moving
            else if (st.empty() || st.back() < 0) {
                st.push_back(asteroids[i]);
            }
        }
    }

    return st;
}

int main() {
    vector<int> arr = {10, 20, -10};

    vector<int> ans = asteroidCollision(arr);

    cout << "The state of asteroids after collisions is: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
