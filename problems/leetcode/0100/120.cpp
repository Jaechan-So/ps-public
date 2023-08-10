// 120. Triangle
// https://leetcode.com/problems/triangle/description/

using namespace std;

#include <vector>

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    vector<long long> prev(1, triangle[0][0]);

    for (int i = 1; i < triangle.size(); i++) {
      vector<long long> next(i + 1, 0);

      for (int j = 0; j <= i; j++) {
        long long pathSum = LLONG_MAX;
        if (j >= 1) {
          pathSum = min(pathSum, prev[j - 1]);
        }
        if (j < i) {
          pathSum = min(pathSum, prev[j]);
        }
        next[j] = pathSum + triangle[i][j];
      }

      prev = next;
    }

    return *min_element(prev.begin(), prev.end());
  }
};
