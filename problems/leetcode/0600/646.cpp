// 646. Maximum Length of Pair Chain
// https://leetcode.com/problems/maximum-length-of-pair-chain/description/

using namespace std;

#include <queue>
#include <vector>

class Solution {
public:
  int findLongestChain(vector<vector<int>> &pairs) {
    auto compare = [](vector<int> &v1, vector<int> &v2) {
      return v1[1] > v2[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(
        compare);
    for (vector<int> &p : pairs) {
      pq.push(p);
    }

    int length = 0, lastEndValue = INT_MIN;
    while (!pq.empty()) {
      if (lastEndValue < pq.top()[0]) {
        lastEndValue = pq.top()[1];
        length++;
      }
      pq.pop();
    }

    return length;
  }
};
