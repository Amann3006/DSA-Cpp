#include <bits/stdc++.h>
using namespace std;

// DFS function to search for the word
bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
    // If all characters matched
    if (idx == word.size()) return true;

    // Boundary + character match check
    if (i < 0 || j < 0 || i >= board.size() ||
        j >= board[0].size() || board[i][j] != word[idx]) {
        return false;
    }

    // Mark current cell as visited
    char temp = board[i][j];
    board[i][j] = '#';

    // Explore 4 directions
    bool found = dfs(board, word, i + 1, j, idx + 1) ||
                 dfs(board, word, i - 1, j, idx + 1) ||
                 dfs(board, word, i, j + 1, idx + 1) ||
                 dfs(board, word, i, j - 1, idx + 1);

    // Restore (Backtracking)
    board[i][j] = temp;

    return found;
}

// Function to check if the word exists
bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dfs(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    cout << boolalpha << exist(board, "ABCCED") << endl; // true
    cout << boolalpha << exist(board, "SEE") << endl;    // true
    cout << boolalpha << exist(board, "ABCB") << endl;   // false
}
