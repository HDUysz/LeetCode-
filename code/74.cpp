/*
74. 搜索二维矩阵

给你一个满足下述两条属性的 m x n 整数矩阵：

每行中的整数从左到右按非严格递增顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = binarySearchRow(matrix, target, m);
        if (row < 0) return false;
        return binarySearchCol(matrix[row], target);
    }

    int binarySearchRow(vector<vector<int>>& matrix, int target, int m) {
        int low = 0, high = m - 1;
        if (matrix[0][0] > target) return -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] == target) return mid;
            else if (matrix[mid][0] < target && (mid == m - 1 || matrix[mid + 1][0] > target))
                return mid;
            else if (matrix[mid][0] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    bool binarySearchCol(vector<int>& row, int target) {
        int l = 0, r = row.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (row[mid] == target) return true;
            else if (row[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};

int main() {
  Solution solve;
  vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
  int flag = solve.searchMatrix(matrix, 11);
  cout << flag;
  return 0;
}