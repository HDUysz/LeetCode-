/*
57. 插入区间

给你一个 无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
示例 1：

输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      intervals.emplace_back(newInterval);
      sort(intervals.begin(), intervals.end(), compare);
      vector<vector<int>> merged;
      merged.push_back(intervals[0]);

      for (int i = 1; i < intervals.size(); ++i) {
          if (merged.back()[1] >= intervals[i][0]) {
              merged.back()[1] = max(merged.back()[1], intervals[i][1]);
          } else {
              merged.push_back(intervals[i]);
          }
      }

      return merged;
    }
    
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
};

/*
官方题解
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) {
            if (interval[0] > right) {
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;                    
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                ans.push_back(interval);
            }
            else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
*/

