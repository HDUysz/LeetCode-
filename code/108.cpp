/*
108. 将有序数组转换为二叉搜索树

给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 
平衡二叉搜索树。
*/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums, int left, int right) {
      if (left > right) {
        return nullptr;
      }

      int mid = (left + right) / 2;

      TreeNode* root = new TreeNode(nums[mid]);

      root->left = build(nums, left, mid - 1);
      root->right = build(nums, mid + 1, right);

      return root;
    }
};