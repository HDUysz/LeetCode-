/*
78. 子集

给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的
子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      // 用来保存临时变量的数组
      vector<int> _arr;
      // 用来记录已经加入的数组的下标
      int start = 0;
      // 结果保存
      vector<vector<int>> results;
      backTrack(nums, results, _arr, 0);
      return results;
    }

    void backTrack(vector<int>& nums, vector<vector<int>>& results, vector<int>& _arr, int start) {
      // 由于不是只有所有数字的任意组合都有可能加入，因此每次递归都加入当前的_arr
      results.emplace_back(_arr);
      if (start >= nums.size()) return;
      // 加入之后，开始循环
      for (int i = start; i < nums.size(); i++) {
        _arr.emplace_back(nums[i]);
        backTrack(nums, results, _arr, i + 1);
        _arr.pop_back();
      }
    }
};

int main() {
  Solution solve;
  vector<int> nums = {1,2,3};
  auto res = solve.subsets(nums);
  for (auto v : res) {
    for (int n : v) {
      cout << n << " ";
    }
    cout << endl;
  }
  return 0;
}