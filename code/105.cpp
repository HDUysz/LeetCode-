/*
105. 从前序与中序遍历序列构造二叉树

给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
*/

#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    unordered_map<int, int> my_hash;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int n = preorder.size();

      for (int i = 0; i < n; i++) {
        my_hash[inorder[i]] = i;
      }

      return mybuild(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* mybuild(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inorLeft, int inorRight) {
      if (preLeft > preRight) {
        return nullptr;
      }

      int preRoot = preLeft;
      int inorRoot = my_hash[preorder[preRoot]];

      TreeNode* root = new TreeNode(preorder[preRoot]);

      int left_subTree_size = inorRoot - inorLeft;

      root->left = mybuild(preorder, inorder, preLeft + 1, preLeft + left_subTree_size, inorLeft, inorRoot - 1);

      root->right = mybuild(preorder, inorder, preLeft + 1 + left_subTree_size, preRight, inorRoot + 1, inorRight);

      return root;
    }
};