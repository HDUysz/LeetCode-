/*
106. 从中序与后序遍历序列构造二叉树

给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
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
    int post_index;
    unordered_map<int, int> my_hash;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      int n = inorder.size();
      post_index = n - 1;
      for (int i = 0; i < n; i++) {
        my_hash[inorder[i]] = i;
      }

      return mybuild(inorder, postorder, 0, n - 1);
    }

    TreeNode* mybuild(vector<int>& inorder, vector<int>& postorder, int inorLeft, int inorRight) {
      if (inorLeft > inorRight) {
        return nullptr;
      }

      int postRoot = postorder[post_index];
      TreeNode* root = new TreeNode(postRoot);

      int inorRoot = my_hash[postRoot];
      post_index--;
      root->right = mybuild(inorder, postorder, inorRoot + 1, inorRight);
      root->left = mybuild(inorder, postorder, inorLeft, inorRoot - 1);

      return root;

    }
};