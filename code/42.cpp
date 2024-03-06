/*
42. 接雨水

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
  int trap(vector<int>& height) {
    int sum = 0;
    int n = height.size();
    vector<int> max_left(n), max_right(n);
    for (int i = 1; i < n - 1; i++) {
      max_left[i] = max(max_left[i - 1], height[i - 1]);
    }
    for (int j = n - 2; j >= 0; j--) {
      max_right[j] = max(max_right[j + 1], height[j + 1]);
    }
    for (int i = 1; i < n - 1; i++) {
      int _min = min(max_left[i], max_right[i]);
      if (_min > height[i]) {
        sum += _min - height[i];
      }
    }
    return sum;
  }
};