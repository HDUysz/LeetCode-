/*
75. 颜色分类

给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库内置的 sort 函数的情况下解决这个问题。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int p0 = 0, p1 = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
          swap(nums[p1], nums[i]);
          p1++;
        } else if (nums[i] == 0) {
          swap(nums[p0], nums[i]);
          if (p0 < p1) {
            swap(nums[i], nums[p1]);
          }
          p0++;
          p1++;
        }
      }
    }
};