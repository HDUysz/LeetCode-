/*
40. 组合总和 II

给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。 
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, res, path, 0, 0, target);
        return res;
    }

    void backTrack(vector<int>& candidates, vector<vector<int>>& res, vector<int> path, int start, int curr_sum, int target) {
        if (curr_sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (curr_sum + candidates[i] > target) break;
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            backTrack(candidates, res, path, i + 1, curr_sum + candidates[i], target);
            path.pop_back();
        }
    }
};
