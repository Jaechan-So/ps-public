// 378. Kth Smallest Element in a Sorted Matrix
// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

using namespace std;

#include <queue>
#include <vector>

typedef pair<int, pair<int, int>> piii; // (value, (x, y))

class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    pq.push({matrix[0][0], {0, 0}});

    int remaining = k, answer = -1;
    while (remaining) {
      piii p = pq.top();
      pq.pop();
      int value = p.first, x = p.second.first, y = p.second.second;

      if (remaining == 1) {
        answer = value;
        break;
      }

      if (x < matrix.size() - 1 && matrix[x + 1][y] != -1) {
        pq.push({matrix[x + 1][y], {x + 1, y}});
        matrix[x + 1][y] = -1;
      }
      if (y < matrix.size() - 1 && matrix[x][y + 1] != -1) {
        pq.push({matrix[x][y + 1], {x, y + 1}});
        matrix[x][y + 1] = -1;
      }

      remaining--;
    }

    return answer;
  }
};
