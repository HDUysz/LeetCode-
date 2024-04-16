/*
283. 移动零

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int n = nums.size();
      int l = 0, r = 0;
      if (n == 0 || n == 1) return;
      while (r < n) {
        if (nums[r] != 0) {
          swap(nums[l], nums[r]);
          l++;
        }
        r++;
      }
    }
};

int main() {
  Solution s;
  vector<int> nums = {0,1,0,3,12};
  s.moveZeroes(nums);
  for (int i : nums) cout << i << " ";
  return 0;
}