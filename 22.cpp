/*
22. 括号生成

数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> res;
      if (n == 0) return res;
      string str;
      backTrack(res, str, 0, 0, n);
      return res;
    }

    void backTrack(vector<string>& res, string& str, int open, int close, int n) {
      if (str.length() == n * 2) {
        res.emplace_back(str);
        return;
      }
      if (open < n) {
        str.push_back('(');
        backTrack(res, str, open + 1, close, n);
        str.pop_back();
      }
      if (close < open) {
        str.push_back(')');
        backTrack(res, str, open, close + 1, n);
        str.pop_back();
      }
    }
};