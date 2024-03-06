/*
16. 最接近的三数之和

给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum = nums[0] + nums[1] + nums[2];
        int minDiff = abs(closestSum - target);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                int currentDiff = abs(currentSum - target);
                if (currentDiff < minDiff) {
                    closestSum = currentSum;
                    minDiff = currentDiff;
                }
                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    return currentSum;
                }
                while (left < right && left > i + 1 && nums[left] == nums[left - 1]) left++;
                while (left < right && right < nums.size() - 1 && nums[right] == nums[right + 1]) right--;
            }
        }
        return closestSum;
    }
};
