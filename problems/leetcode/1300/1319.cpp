// 1319. Number of Operations to Make Network Connected
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

using namespace std;

#include <numeric>
#include <set>
#include <vector>

class Solution {
public:
  int getTopHead(vector<int> &heads, int i) {
    int j = i;
    while (heads[j] != j) {
      j = heads[j];
    }
    return j;
  }

  int makeConnected(int n, vector<vector<int>> &connections) {
    if (connections.size() < n - 1) {
      return -1;
    }

    vector<int> heads(n, -1);
    iota(heads.begin(), heads.end(), 0);

    for (vector<int> &conn : connections) {
      int a = conn[0], b = conn[1], aHead = getTopHead(heads, a),
          bHead = getTopHead(heads, b);
      heads[bHead] = aHead;
    }

    for (int i = 0; i < n; i++) {
      if (i != heads[i]) {
        heads[i] = getTopHead(heads, i);
      }
    }

    set<int> topHeads;
    for (int i : heads) {
      topHeads.insert(i);
    }

    return topHeads.size() - 1;
  }
};

// 최소 n - 1개의 edge가 있어야 모든 원소가 연결이 가능하므로, 그 경우가 아니면
// -1 반환. Union Find를 이용해서 연결되어 있는 묶음의 개수를 파악한다. (묶음의
// 개수 - 1)개 만큼만 옮겨주면 된다. 최소 n - 1개의 edge가 있어야 모든 원소가
// 연결이 가능한 것과 동일한 논리.
