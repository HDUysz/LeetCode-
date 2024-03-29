/*
17. 电话号码的字母组合

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
      vector<string> res;
      if (digits.length() == 0) return res;
      unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
      };
      string combine;
      backTrack(digits, 0, phoneMap, res, combine);
      return res;
    }

    void backTrack(string digits, int index, unordered_map<char, string> phoneMap, vector<string>& res, string& combine) {
      if (index == digits.length()) {
        res.emplace_back(combine);
        return;
      }
      char digit = digits[index];
      string letter = phoneMap.at(digit);
      for (char c : letter) {
        combine.push_back(c);
        backTrack(digits, index + 1, phoneMap, res, combine);
        combine.pop_back();
      }
    }
};