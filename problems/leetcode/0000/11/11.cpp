// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water/description/

using namespace std;

#include <vector>

class Solution {
public:
  int maxArea(vector<int> &height) {
    int n = height.size(), start = 0, end = n - 1, maxArea = 0;

    while (start < end) {
      maxArea = max(maxArea, min(height[start], height[end]) * (end - start));

      if (height[start] <= height[end]) {
        start++;
      } else {
        end--;
      }
    }

    return maxArea;
  }
};
