/*
121. 买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<int> left(n);
      left[0] = prices[0];
      for (int i = 1; i < n; i++) {
        left[i] = min(prices[i - 1], left[i - 1]);
      }
      for (int i = 0; i < n; i++) {
        left[i] = prices[i] - left[i];
      }

      return *max_element(left.begin(), left.end());
    }
};

int main() {
  Solution s;
  vector<int> prices = {7,1,5,3,6,4};
  cout << s.maxProfit(prices);
}