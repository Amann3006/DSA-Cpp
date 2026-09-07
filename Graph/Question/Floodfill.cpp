#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int r;
    int c;

    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool validity(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    vector<vector<int>> floodFill(
        vector<vector<int>>& image,
        int sr,
        int sc,
        int color
    ) {
        queue<pair<int, int>> q;

        r = image.size();
        c = image[0].size();

        int ele = image[sr][sc];

        if (ele == color)
            return image;

        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty()) {
            int curr_qs = q.size();

            while (curr_qs--) {
                int i = q.front().first;
                int j = q.front().second;

                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ni = i + row[k];
                    int nj = j + col[k];

                    if (validity(ni, nj) &&
                        image[ni][nj] == ele) {

                        image[ni][nj] = color;
                        q.push({ni, nj});
                    }
                }
            }
        }

        return image;
    }
};

int main() {

    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    int sr = 1;
    int sc = 1;
    int color = 2;

    Solution obj;

    vector<vector<int>> ans =
        obj.floodFill(image, sr, sc, color);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}