/*
128. 最长连续序列

给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> my_hash;
      int max_count = 0;
      for (const int& n : nums) my_hash.insert(n);
      for (const int& num : my_hash) {
        if (!my_hash.count(num - 1)) {
          int currNum = num;
          int count = 1;

          while (my_hash.count(currNum + 1)) {
            currNum += 1;
            count++;
          }
          max_count = max(max_count, count);
        }
      }
      return max_count;
    }
};

int main() {
  Solution s;
  vector<int> nums = {100,4,200,1,3,2};
  int res = s.longestConsecutive(nums);
  cout << res;
}