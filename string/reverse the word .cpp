#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;

    // Extract words from the string (ignores extra spaces)
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the word order
    reverse(words.begin(), words.end());

    // Build the result string
    string result;
    for (int i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i < words.size() - 1) {
            result += " ";
        }
    }

    return result;
}

int main() {
    string input = "   hello   world  this is   C++  ";
    string output = reverseWords(input);

    cout << "Reversed: \"" << output << "\"" << endl;

    return 0;
}
