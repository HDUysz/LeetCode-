/*
34. 在排序数组中查找元素的第一个和最后一个位置
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, first = -1, second = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] < target) i = mid + 1;
            else j = mid - 1;
        }
        if (i < nums.size() && nums[i] == target) first = i;
        i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] <= target) i = mid + 1;
            else j = mid - 1;
        }
        if (j >= 0 && nums[j] == target) second = j;
        return {first, second};
    }
};
