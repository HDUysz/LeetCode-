/*
119. 杨辉三角 II

给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/


#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<vector<int>> ans(rowIndex);
      for (int i = 0; i < rowIndex; i++) {
        ans[i].resize(i + 1);
        ans[i][0] = 1;
        ans[i][i] = 1;
        for (int j = 1; j < i; j++) {
          ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
      }
      return ans[rowIndex];
    }
};