// 546. Remove Boxes
// https://leetcode.com/problems/remove-boxes/description/

using namespace std;

#include <vector>

class Solution {
public:
  int n;
  vector<vector<vector<int>>> memo;

  int getMaxPoints(vector<int> &boxes, int left, int right, int sequences) {
    if (left > right) {
      return 0;
    }

    if (memo[left][right][sequences] != -1) {
      return memo[left][right][sequences];
    }

    int points = (sequences + 1) * (sequences + 1) +
                 getMaxPoints(boxes, left + 1, right, 0);
    for (int i = left + 1; i <= right; i++) {
      if (boxes[i] == boxes[left]) {
        points = max(points, getMaxPoints(boxes, left + 1, i - 1, 0) +
                                 getMaxPoints(boxes, i, right, sequences + 1));
      }
    }

    memo[left][right][sequences] = points;
    return memo[left][right][sequences];
  }

  int removeBoxes(vector<int> &boxes) {
    n = boxes.size();
    memo = vector<vector<vector<int>>>(
        n, vector<vector<int>>(n, vector<int>(n, -1)));
    return getMaxPoints(boxes, 0, n - 1, 0);
  }
};

// Naive
// O(n!)

// DP
// Divide and Conquer -> 연속되는 것끼리 점수를 얻기 때문에 불가능. (먼저
// 터뜨려야 할 수도 있음) dp[i][j]: i번째 인덱스까지 상자를 제거했을 때, 색깔
// j를 가장 길게 남기는 경우와 그 때 점수 dp[i][j] = max_(c = 1 to 100)(c ==
// boxes[i] ? dp[i - 1][c] 점수 + (개수 ^ 2) : dp[i - 1][c] 점수 + 1)
