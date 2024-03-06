/*
46. 全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> result;
      backTrack(nums, 0, result);
      return result;
    }
    void backTrack(vector<int>& nums, int start, vector<vector<int>>& result) {
      if (start == nums.size()) {
        result.push_back(nums);
        return;
      }
      for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        backTrack(nums, start + 1, result);
        swap(nums[start], nums[i]);
      }
    }
};