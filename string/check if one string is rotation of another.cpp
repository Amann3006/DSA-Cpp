#include <bits/stdc++.h>
using namespace std;

// 🔹 Method 1: Using rotation loop and substr()
bool rotateStringBrute(string s, string goal) {
    if (s.length() != goal.length()) return false;

    // Try all possible rotations
    for (int i = 0; i < s.length(); i++) {
        string rotated = s.substr(i) + s.substr(0, i);
        if (rotated == goal) {
            return true;
        }
    }
    return false;
}

// 🔹 Method 2: Using string doubling and find()
bool rotateStringEfficient(string s, string goal) {
    if (s.length() != goal.length()) return false;

    string doubledS = s + s;
    return doubledS.find(goal) != string::npos;
}

int main() {
    string s = "rotation";
    string goal = "tionrota";

    cout << "Using substr() method: ";
    cout << (rotateStringBrute(s, goal) ? "true" : "false") << endl;

    cout << "Using find() + doubling method: ";
    cout << (rotateStringEfficient(s, goal) ? "true" : "false") << endl;

    return 0;
}
