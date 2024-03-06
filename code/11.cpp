#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
      int MaxArea = 0;
      int leftPt = 0, rightPt = height.size() - 1;
      while (leftPt < rightPt) {
        MaxArea = max(MaxArea, getArea(height[leftPt], height[rightPt], rightPt - leftPt));
        if (height[leftPt] < height[rightPt]) {
          leftPt++;
        } else {
          rightPt--;
        }
      }
      return MaxArea;
    }
    int getArea(int hA, int hB, int width) {
      return width * min(hA, hB);
    }
};