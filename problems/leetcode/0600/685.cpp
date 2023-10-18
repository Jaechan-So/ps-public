// 685. Redundant Connection II
// https://leetcode.com/problems/redundant-connection-ii/description/

using namespace std;

#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  unordered_map<int, int> head;

  int findHead(int v) {
    if (v != head[v]) {
      head[v] = findHead(head[v]);
    }

    return head[v];
  }

  void merge(int from, int to) {
    int fromHead = findHead(from), toHead = findHead(to);

    for (unordered_map<int, int>::iterator iter = head.begin();
         iter != head.end(); iter++) {
      if (iter->second == toHead) {
        iter->second = fromHead;
      }
    }
  }

  vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
    int e = edges.size(), n = 0, multipleParentIndex = -1;
    unordered_map<int, int> parentCount;

    for (int i = 0; i < e; i++) {
      int from = edges[i][0], to = edges[i][1];
      parentCount[to]++;
      if (parentCount[to] > 1) {
        multipleParentIndex = to;
      }
      n = max(n, max(from, to));
    }

    for (int i = 1; i <= n; i++) {
      head[i] = i;
    }

    unordered_set<int> cyclicVertices;
    for (int i = 0; i < e; i++) {
      int from = edges[i][0], to = edges[i][1];
      int fromHead = findHead(from), toHead = findHead(to);

      if (toHead != to) {
        continue;
      }

      if (fromHead == toHead) {
        for (int j = 1; j <= n; j++) {
          if (findHead(j) == fromHead) {
            cyclicVertices.insert(j);
          }
        }
        break;
      }

      merge(from, to);
    }

    if (cyclicVertices.empty()) {
      for (int i = e - 1; i >= 0; i--) {
        int to = edges[i][1];
        if (parentCount[to] == 2) {
          return edges[i];
        }
      }
    }

    for (int i = e - 1; i >= 0; i--) {
      int from = edges[i][0], to = edges[i][1];
      if (cyclicVertices.find(from) != cyclicVertices.end() &&
          cyclicVertices.find(to) != cyclicVertices.end() &&
          (multipleParentIndex == -1 || to == multipleParentIndex)) {
        return edges[i];
      }
    }

    return {};
  }
};

// 1. 기본적으로 추가되기 전 트리는 parent 개수가 1, 1, ..., 1, 0개이다.
// 2. 여기서 하나를 추가하는 경우 2, 1, ..., 1, 0개가 되거나 1, ..., 1개가 된다.

// i. 1, ..., 1개 케이스인 경우, edge를 순서대로 추가하다가 Cycle을 만든 edge를
// 반환하면 된다. ii. 2, ..., 1, 0개 케이스인 경우, 만약 edge를 추가했을 때 이미
// parent가 자기 자신이 아닌 경우를 처음 만났을 때, (즉 이미 화살표가 가리키는
// 노드가 parent를 이미 가지고 있었던 경우) 추가되어 있던 edge가 Cycle에
// 포함되어 있는 edge라면 그 edge를 반환하고, 아니라면 이번에 추가하려 했던
// edge를 반환한다.

// Cycle O -> Cycle 안에 있는 모든 vertex 번호를 조사하고, edge를 역순으로
// 조사하면서 양 끝이 둘 다 Cycle에 속해 있으면 반환. Cycle X -> edge를 역순으로
// 조사하면서 화살표가 가리키는 to가 parentCount == 2라면 반환.
