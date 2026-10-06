
#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginword, string endword,
                 vector<string>& wordList) {

    queue<pair<string, int>> q;
    q.push({beginword, 1});

    unordered_set<string> st(wordList.begin(), wordList.end());

    if (st.find(endword) == st.end())
        return 0;

    st.erase(beginword);

    while (!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == endword)
            return steps;

        for (int i = 0; i < word.size(); i++) {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;

                if (st.find(word) != st.end()) {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }

            word[i] = original;
        }
    }

    return 0;
}

int main() {
    string beginword = "hit";
    string endword = "cog";

    vector<string> wordList = {
        "hot", "dot", "dog", "lot", "log", "cog"
    };

    cout << ladderLength(beginword, endword, wordList) << endl;

    return 0;
}