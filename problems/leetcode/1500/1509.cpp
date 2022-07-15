// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/

#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<int> v;

public:
  int minDifference(vector<int> &nums) {
    for (auto &num : nums) {
      pq.push(num);
    }

    while (!pq.empty()) {
      v.push_back(pq.top());
      pq.pop();
    }

    int result;
    int len = v.size();

    if (len > 4) {
      int initialEnd = (len - 1) - 3;
      result = v[initialEnd] - v[0];
      result = min(result, v[initialEnd + 1] - v[1]);
      result = min(result, v[initialEnd + 2] - v[2]);
      result = min(result, v[initialEnd + 3] - v[3]);
    } else {
      result = 0;
    }

    return result;
  }
};
