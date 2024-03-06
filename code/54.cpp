#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> _check(m, vector<bool>(n, false));
        int x = 0, y = -1;
        vector<int> res;
        int k = 1;
        while (k <= m * n) {
            while (y < n - 1 && !_check[x][y + 1]) {
                res.emplace_back(matrix[x][++y]);
                _check[x][y] = true;
                k++;
            }
            while (x < m - 1 && !_check[x + 1][y]) {
                res.emplace_back(matrix[++x][y]);
                _check[x][y] = true;
                k++;
            }
            while (y > 0 && !_check[x][y - 1]) {
                res.emplace_back(matrix[x][--y]);
                _check[x][y] = true;
                k++;
            }
            while (x > 0 && !_check[x - 1][y]) {
                res.emplace_back(matrix[--x][y]);
                _check[x][y] = true;
                k++;
            }
        }
        return res;
    }
};

int main() {
    Solution solve;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = solve.spiralOrder(matrix);
    cout << "答案是:" << endl;
    for (int n : res) {
        cout << n << " ";
    }
    return 0;
}
