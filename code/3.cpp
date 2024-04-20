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
        unordered_map<char, int> charIndexMap;
        int window_size = 0;
        for (int start = 0, end = 0; end < s.length(); ++end) {
            char currentChar = s[end];
            // 如果当前字符之前出现过，并且上次出现位置在窗口内，调整窗口的左边界
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
                start = charIndexMap[currentChar] + 1;
            }
            // 更新字符的最后出现位置
            charIndexMap[currentChar] = end;
            // 更新最长子串长度
            window_size = max(window_size, end - start + 1);
        }
        return window_size;
    }
};