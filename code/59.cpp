/*
59. 螺旋矩阵 II

给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      int k = 1, i = 0, j = -1;
      vector<vector<int>> arr(n, vector<int>(n));
      while (k <= n * n) {
        while (j < n - 1 && !arr[i][j + 1]) arr[i][++j] = k++;
        while (i < n - 1 && !arr[i + 1][j]) arr[++i][j] = k++;
        while (j > 0 && !arr[i][j - 1]) arr[i][--j] = k++;
        while (i > 0 && !arr[i - 1][j]) arr[--i][j] = k++;
      }
      return arr;
    }
};