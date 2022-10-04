// 2101. Detonate the Maximum Bombs
// https://leetcode.com/problems/detonate-the-maximum-bombs/

using namespace std;

#include <cmath>
#include <vector>

class Solution {
public:
  vector<vector<int>> connections;

  int maximumDetonation(vector<vector<int>> &bombs) {
    connections = vector<vector<int>>(bombs.size(), vector<int>());

    for (int i = 0; i < bombs.size(); i++) {
      int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];

      for (int j = i + 1; j < bombs.size(); j++) {
        int xj = bombs[j][0], yj = bombs[j][1], rj = bombs[j][2];

        long long distanceSquare = pow(xj - xi, 2) + pow(yj - yi, 2);
        if (distanceSquare <= pow(ri, 2)) {
          connections[i].push_back(j);
        }
        if (distanceSquare <= pow(rj, 2)) {
          connections[j].push_back(i);
        }
      }
    }

    int maximumDetonationCount = 0;
    for (int i = 0; i < bombs.size(); i++) {
      vector<int> detonationCounts(bombs.size(), 0);
      vector<bool> visited(bombs.size(), false);
      maximumDetonationCount =
          max(maximumDetonationCount, dfs(detonationCounts, visited, i));
    }

    return maximumDetonationCount;
  }

  int dfs(vector<int> &detonationCounts, vector<bool> &visited, int index) {
    if (visited[index]) {
      return 0;
    }

    if (detonationCounts[index] != 0) {
      return detonationCounts[index];
    }

    visited[index] = true;
    int detonationCount = 1;
    for (auto nextBomb : connections[index]) {
      detonationCount += dfs(detonationCounts, visited, nextBomb);
    }

    detonationCounts[index] = detonationCount;
    return detonationCount;
  }
};
