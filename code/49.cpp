/*
49. 字母异位词分组

给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> _hash;
      vector<vector<string>> res;

      for (int i = 0; i < strs.size(); i++) {
        string sortedStr = strs[i];
        sort(sortedStr.begin(), sortedStr.end());
        _hash[sortedStr].emplace_back(strs[i]);
      }

      for (auto v : _hash) {
        res.emplace_back(v.second);
      }
      return res;
    }
};