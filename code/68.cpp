/*
68. 文本左右对齐

给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

注意:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
*/

/*
分析:
  1. 首先一个一个选取单词，如果不是最后一行，则计算能否取下一个单词，如果不能，则为当前取的单词添加空格，并压入数组中
  2. 如果是最后一行，则将空格全部放到最后，单词之间不插入额外的空格
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
      vector<string> results;
      // 中间变量，用来记录已经取出的单词，后面还要在该变量中插入空格
      string _midTmp;
      // 中间变量，用来记录已经取出的单词
      vector<string> picked_words;
      // 中间变量，用来记录已经存储的单词的总长度
      int picked_len = 0;
      // 一个一个选取单词
      for (int i = 0; i < words.size(); ++i) {
        // 取出单词，记录长度，并增加总长度，与maxWidth比较，如果超过了，则回退
        picked_words.emplace_back(words[i]);
        // 默认单词后有一个空格
        picked_len += words[i].length() + 1;
        // 如果长度超过了总长度
        if (picked_len - 1 > maxWidth) {
          // 回退
          picked_len -= words[i].length() + 1;
          picked_words.pop_back();
          // 处理已经取出的字符串
          solve(picked_words, _midTmp, picked_len, maxWidth);
          results.emplace_back(_midTmp);
          // 清空已经取出的字符串和中间变量
          _midTmp.clear();
          picked_words.clear();
          picked_len = 0;
          i--;
        }
      }
      // 如果最后还有剩余的，说明是最后一行，由于之前默认单词后有一个空格，因此直接计算需要加在后面的空格
      int residue_space = maxWidth - picked_len + 1;
      for (int j = 0; j < picked_words.size(); j++) {
        _midTmp += picked_words[j];
        if (j != picked_words.size() - 1) _midTmp.push_back(' ');
      }
      for (int k = 0; k < residue_space; k++) {
        _midTmp.push_back(' ');
      }
      results.emplace_back(_midTmp);
      return results;
    }

    void solve(vector<string>& picked_words, string& midTmp, int picked_len, int maxWidth) {
      // 去掉之前记录的空格，重新计算每个单词后的空格数量
      int num = picked_words.size();
      picked_len -= num;
      // 如果只有一个单词，则缺失的空格都在第一个单词之后，如果有一个以上的单词，则空格在第一个单词和最后一个单词之间
      // 计算需要补足的空格数量
      int space_num = maxWidth - picked_len;
      if (num == 1) {
        midTmp += picked_words[0];
        for (int i = 1; i <= space_num; ++i) {
          midTmp.push_back(' ');
        }
      } else {
        vector<int> distribution;
        distribute(space_num, picked_words.size() - 1, distribution);
        int index = 0;
        for (int i = 0; i < picked_words.size(); i++) {
          midTmp += picked_words[i];
          if (index < distribution.size()) {
            for (int j = 1; j <= distribution[index]; j++) {
              midTmp.push_back(' ');
            }
            index++;
          }
        }
      }
    }

    void distribute(int total, int spaces, vector<int>& distribution) {
        distribution.clear(); // 清空原来的内容
        if (spaces == 0) {
            return; // 如果没有空间需要分配，直接返回
        }

        int base = total / spaces; // 基本均分值
        int remainder = total % spaces; // 剩余部分

        for (int i = 0; i < spaces; ++i) {
            distribution.push_back(base + (i < remainder ? 1 : 0));
        }
    }
};