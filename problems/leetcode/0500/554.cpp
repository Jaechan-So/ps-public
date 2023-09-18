// 554. Brick Wall
// https://leetcode.com/problems/brick-wall/description/

using namespace std;

#include <map>
#include <vector>

class Solution {
public:
  int leastBricks(vector<vector<int>> &wall) {
    unordered_map<long long, int> boundaries;
    int maxPosition = -1;

    for (vector<int> &r : wall) {
      long long position = 0;
      for (int i = 0; i < r.size() - 1; i++) {
        position += r[i];
        boundaries[position]++;
        if (maxPosition == -1 ||
            boundaries[position] > boundaries[maxPosition]) {
          maxPosition = position;
        }
      }
    }

    return wall.size() - boundaries[maxPosition];
  }
};

// 벽돌 간 경계가 포함되는 것이 유리함 (그래야 벽돌을 지나지 않으므로)
// 그냥 각각의 경계 별 횟수를 모두 더해서, 최대값인 곳을 구하면 되지 않을까?
