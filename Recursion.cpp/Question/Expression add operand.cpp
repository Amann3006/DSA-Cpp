#include <bits/stdc++.h>
using namespace std;

// DFS function to build expressions
void dfs(string &num, int target, int start,
         long long current_value, long long last_operand,
         string expression, vector<string> &result) {

    // If reached end of string
    if (start == num.size()) {
        if (current_value == target)
            result.push_back(expression);
        return;
    }

    // Try all partitions
    for (int i = start; i < num.size(); i++) {
        // Avoid numbers with leading zeros
        if (i > start && num[start] == '0')
            return;

        string current_num = num.substr(start, i - start + 1);
        long long value = stoll(current_num);

        // First number → directly take
        if (start == 0) {
            dfs(num, target, i + 1, value, value, current_num, result);
        }
        else {
            // '+'
            dfs(num, target, i + 1,
                current_value + value,
                value,
                expression + "+" + current_num,
                result);

            // '-'
            dfs(num, target, i + 1,
                current_value - value,
                -value,
                expression + "-" + current_num,
                result);

            // '*'
            dfs(num, target, i + 1,
                current_value - last_operand + last_operand * value,
                last_operand * value,
                expression + "*" + current_num,
                result);
        }
    }
}

// Main function to generate expressions
vector<string> addOperators(string num, int target) {
    vector<string> result;
    dfs(num, target, 0, 0, 0, "", result);
    return result;
}

int main() {
    string num = "123";
    int target = 6;

    vector<string> result = addOperators(num, target);

    for (auto &expr : result)
        cout << expr << " ";

    return 0;
}
