/*
53. 最大子数组和

给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组
是数组中的一个连续部分。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      vector<int> dp;
      int n = nums.size();
      dp.resize(n);
      dp[0] = nums[0];
      for (int i = 1; i < n; i++) {
        dp[i] = max(nums[i] + dp[i - 1], nums[i]);
      }
      int _max = -1e9;
      for (int num : dp) {
        _max = max(_max, num);
      }
      return _max;
    }
};

int main() {
  Solution solve;
  vector<int> nums = {5,4,-1,7,8};
  int res = solve.maxSubArray(nums);
  cout << "结果是:" << res;
}