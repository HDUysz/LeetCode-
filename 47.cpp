/*
47. 全排列 II

给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
  vector<int> vis;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> result;
      vector<int> perm;
      vis.resize(nums.size());
      sort(nums.begin(), nums.end());
      backTrack(nums, 0, result, perm);
      return result;
    }

    void backTrack(vector<int>& nums, int start, vector<vector<int>>& result, vector<int>& perm) {
      if (start == nums.size()) {
        result.emplace_back(perm);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
          continue;
        }
        perm.emplace_back(nums[i]);
        vis[i] = 1;
        backTrack(nums, start + 1, result, perm);
        vis[i] = 0;
        perm.pop_back();
      }
    }
};