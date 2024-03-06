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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        return solve(root, k);
    }
    void DFS(TreeNode* node, int level, vector<long long>& res) {
        if (node == NULL) {
            return;
        }
        if (level < res.size()) {
          res[level] += node->val;
        }else {
          res.push_back(node->val);
        }
        DFS(node->left, level + 1, res);
        DFS(node->right, level + 1, res);
    }

    long long solve(TreeNode* root, int k) {
      vector<long long> res;
      DFS(root, 0, res);
      sort(res.begin(), res.end(), greater<long long>());
      return (k <= res.size() ? res[k - 1] : -1);
    }

};

int main() {
  cout << "Hello";
}