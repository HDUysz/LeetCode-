/*
79. 单词搜索

给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && backTrack(board, visited, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backTrack(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int i, int j, int index) {
        if (index == word.size()) return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) {
            return false;
        }

        visited[i][j] = true;
        if (backTrack(board, visited, word, i + 1, j, index + 1) ||
            backTrack(board, visited, word, i - 1, j, index + 1) ||
            backTrack(board, visited, word, i, j + 1, index + 1) ||
            backTrack(board, visited, word, i, j - 1, index + 1)) {
            return true;
        }

        visited[i][j] = false;
        return false;
    }
};
