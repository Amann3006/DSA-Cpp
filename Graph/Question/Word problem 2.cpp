#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
unordered_map<string, vector<string>> parent;
string beginWord;

void dfs(string word, vector<string>& path) {

    if (word == beginWord) {
        reverse(path.begin(), path.end());
        ans.push_back(path);
        reverse(path.begin(), path.end());
        return;
    }

    for (auto prev : parent[word]) {

        path.push_back(prev);

        dfs(prev, path);

        path.pop_back();
    }
}

vector<vector<string>> findLadders(
    string beginWord,
    string endWord,
    vector<string>& wordList
) {

    unordered_set<string> st(wordList.begin(), wordList.end());

    // If endWord is not present, impossible
    if (st.find(endWord) == st.end()) {
        return {};
    }

    queue<string> q;
    q.push(beginWord);

    unordered_map<string, int> dist;
    dist[beginWord] = 0;

    parent.clear();

    int shortest = -1;

    while (!q.empty()) {

        string word = q.front();
        q.pop();

        int d = dist[word];

        // No need to go beyond shortest level
        if (shortest != -1 && d >= shortest) {
            continue;
        }

        for (int i = 0; i < word.size(); i++) {

            string temp = word;

            for (char ch = 'a'; ch <= 'z'; ch++) {

                if (ch == word[i])
                    continue;

                temp[i] = ch;

                if (st.find(temp) == st.end())
                    continue;

                // First time visiting this word
                if (dist.find(temp) == dist.end()) {

                    dist[temp] = d + 1;

                    parent[temp].push_back(word);

                    q.push(temp);

                    if (temp == endWord) {
                        shortest = d + 1;
                    }
                }

                // Another shortest way to reach temp
                else if (dist[temp] == d + 1) {

                    parent[temp].push_back(word);
                }
            }
        }
    }

    if (dist.find(endWord) == dist.end()) {
        return {};
    }

    vector<string> path;

    path.push_back(endWord);

    ans.clear();

    ::beginWord = beginWord;

    dfs(endWord, path);

    return ans;
}

int main() {

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };

    vector<vector<string>> result =
        findLadders(beginWord, endWord, wordList);

    for (auto path : result) {

        cout << "[";

        for (int i = 0; i < path.size(); i++) {

            cout << "\"" << path[i] << "\"";

            if (i != path.size() - 1)
                cout << ",";
        }

        cout << "]\n";
    }

    return 0;
}