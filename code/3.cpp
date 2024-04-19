/*
3. 无重复字符的最长子串

给定一个字符串 s ，请你找出其中不含有重复字符的 最长
子串的长度。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int j = 0;
      int i = 0;
      vector<int> sub_str(26);
      while (j < s.size()) {
        sub_str[s[j] - 'a']++;
        if (sub_str[s[j] - 'a'] == 1) {
          j++;
        } else {
          sub_str[s[i] - 'a']--;
          sub_str[s[j] - 'a']--;
          i++;
          j++;
        }
      }
      return j - i + 1;
    }
};