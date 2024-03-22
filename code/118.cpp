/*
118. 杨辉三角

给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> ans(numRows);
      for (int i = 0; i < numRows; i++) {
        ans[i].resize(i + 1);
        ans[i][0] = 1;
        ans[i][i] = 1;
        for (int j = 1; j < i; j++) {
          ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
      }
      return ans;
    }
};

int main() {
  Solution s;
  int numRows = 5;
  auto ans = s.generate(numRows);
  for (auto v : ans) {
    for (int n : v) {
      cout << n << " ";
    }
    cout << endl;
  }
}