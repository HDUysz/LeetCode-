/*
560. 和为 K 的子数组

给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

子数组是数组中元素的连续非空序列。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int pre = 0;
      unordered_map<int, int> m;
      m[0] = 1;
      int count = 0;
      for (const int & n : nums) {
        pre += n;

        if (m.find(pre - k) != m.end()) {
          count += m[pre - k];
        }

        m[pre]++;
      }
      return count;
    }
};