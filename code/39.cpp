/*
39. 组合总和

给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, res, path, 0, 0, target);
        return res;
    }

    void backTrack(vector<int>& candidates, vector<vector<int>>& res, vector<int> path, int start, int curr_sum,  int target) {
        if (curr_sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (curr_sum + candidates[i] > target) break;
            path.push_back(candidates[i]);
            backTrack(candidates, res, path, i, curr_sum + candidates[i], target);
            path.pop_back();
        }
    }
};