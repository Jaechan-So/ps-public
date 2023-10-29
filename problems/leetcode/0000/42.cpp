// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/description/

using namespace std;

#include <vector>

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();

    vector<int> maxFromLeft(n, -1), maxFromRight(n, -1);
    maxFromLeft[0] = 0;
    maxFromRight[n - 1] = n - 1;
    for (int i = 1; i < n; i++) {
      maxFromLeft[i] =
          height[i] >= height[maxFromLeft[i - 1]] ? i : maxFromLeft[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
      maxFromRight[i] =
          height[i] >= height[maxFromRight[i + 1]] ? i : maxFromRight[i + 1];
    }

    int peekIndex = maxFromRight[0], sum = 0;

    int right = peekIndex;
    while (right > 0) {
      int nextRight = maxFromLeft[right - 1];
      for (int i = nextRight + 1; i < right; i++) {
        sum += (min(height[right], height[nextRight]) - height[i]);
      }
      right = nextRight;
    }
    int left = peekIndex;
    while (left < n - 1) {
      int nextLeft = maxFromRight[left + 1];
      for (int i = left + 1; i < nextLeft; i++) {
        sum += (min(height[left], height[nextLeft]) - height[i]);
      }
      left = nextLeft;
    }

    return sum;
  }
};

// Divide and Conquer?
// 주어진 범위 안에서, 가장 큰 곳을 찾는다. 가장 큰 곳이 여러 개라면, 이전에
// 나눠진 범위 쪽으로 더 가깝게 고른다. 그렇게 되면 중앙에서 양 쪽으로
// 뻗어나가는 꼴이 된다. 해당 범위를 기준으로 계속 한다. 자르면 그 쪽 사이드가
// 가장 큰 것은 보장된다. 이를 진행하기 위해서는, 0 ~ i까지 가장 큰 곳의 위치와,
// i ~ n - 1까지 가장 큰 곳의 위치를 미리 알고 있어야 하는데 이는 O(n) 내에 구할
// 수 있다.
