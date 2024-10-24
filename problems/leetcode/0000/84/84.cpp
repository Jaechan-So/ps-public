// 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

using namespace std;

#include <stack>
#include <vector>

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    stack<int> indicies;
    int n = heights.size(), maxArea = 0;

    for (int i = 0; i < n; i++) {
      while (!indicies.empty() && heights[indicies.top()] >= heights[i]) {
        int height = heights[indicies.top()];
        indicies.pop();
        int width = indicies.empty() ? i : i - indicies.top() - 1;
        maxArea = max(maxArea, height * width);
      }
      indicies.push(i);
    }

    while (!indicies.empty()) {
      int height = heights[indicies.top()];
      indicies.pop();
      int width = indicies.empty() ? heights.size()
                                   : heights.size() - indicies.top() - 1;
      maxArea = max(maxArea, height * width);
    }

    return maxArea;
  }
};
