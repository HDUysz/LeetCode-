/*
84. 柱状图中最大的矩形
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      stack<int> s;
      int n = heights.size();
      vector<int> left(n), right(n, n);
      for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
          right[s.top()] = i;
          s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
      }

      int res = 0;
      for (int i = 0; i < n; i++) {
        res = max(res, (right[i] - left[i] - 1) * heights[i]);
      }
      return res;
    }
};