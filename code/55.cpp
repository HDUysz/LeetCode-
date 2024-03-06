/*
55. 跳跃游戏

给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
      int max_dis = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (i <= max_dis) max_dis = max(max_dis, nums[i] + i);
        if (nums.size() - 1 <= max_dis) return true;
      }
      return false;
    }
};

int main() {
  Solution solve;
  vector<int> nums = {0};
  int flag = solve.canJump(nums);
  cout << flag;
  return 0;
}