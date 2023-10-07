// 310. Minimum Height Trees
// https://leetcode.com/problems/minimum-height-trees/description/

using namespace std;

#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
  unordered_map<int, unordered_map<int, int>> pathLengths;

  int findChildNodePathLengths(int node, int prev) {
    int pathLength = 0;

    for (unordered_map<int, int>::iterator iter = pathLengths[node].begin();
         iter != pathLengths[node].end(); iter++) {
      int nextNode = iter->first;
      if (nextNode == prev) {
        continue;
      }

      int childPathLength = findChildNodePathLengths(nextNode, node);
      iter->second = childPathLength + 1;
      pathLength = max(pathLength, iter->second);
    }

    return pathLength;
  }

  void findNodePathLengths(int node, int prev, int height) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
        pq; // (pathLength, index)
    pq.push({height, prev});

    for (unordered_map<int, int>::iterator iter = pathLengths[node].begin();
         iter != pathLengths[node].end(); iter++) {
      int nextNode = iter->first, pathLength = iter->second;
      if (nextNode == prev) {
        continue;
      }

      pq.push({pathLength, nextNode});
      if (pq.size() > 2) {
        pq.pop();
      }
    }

    int maxNode = pq.top()[1], maxPathLength = pq.top()[0];
    pq.pop();
    int secondMaxPathLength = maxPathLength;
    if (!pq.empty()) {
      secondMaxPathLength = maxPathLength;
      maxNode = pq.top()[1];
      maxPathLength = pq.top()[0];
    }

    for (unordered_map<int, int>::iterator iter = pathLengths[node].begin();
         iter != pathLengths[node].end(); iter++) {
      int nextNode = iter->first, pathLength = iter->second;
      if (nextNode == prev) {
        continue;
      }

      pathLengths[nextNode][node] =
          ((maxNode == nextNode) ? secondMaxPathLength : maxPathLength) + 1;
      findNodePathLengths(nextNode, node, pathLengths[nextNode][node]);
    }
  }

  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    for (vector<int> &e : edges) {
      int v1 = e[0], v2 = e[1];
      pathLengths[v1][v2] = -1;
      pathLengths[v2][v1] = -1;
    }

    findChildNodePathLengths(0, n);
    findNodePathLengths(0, n, 0);

    int height = INT_MAX;
    vector<int> minHeightTreeRoots;
    for (int i = 0; i < n; i++) {
      int localHeight = 0;
      for (pair<int, int> p : pathLengths[i]) {
        int h = p.second;
        localHeight = max(localHeight, h);
      }
      if (localHeight < height) {
        minHeightTreeRoots.clear();
        height = localHeight;
        minHeightTreeRoots.push_back(i);
      } else if (localHeight == height) {
        minHeightTreeRoots.push_back(i);
      }
    }

    return minHeightTreeRoots;
  }
};

// 1. DFS를 돌면서, 자식 노드들에 대한 최대 거리를 찾는다. 부모 노드로부터 온
// 최대 거리는 아직 신뢰할 수 없다. O(V + E)
// 2. 부모 노드로부터 온 최대 거리를 이제 계산할 수 있다. 루트 노드로부터 온
// 거리를 포함하여, 가려는 자식 노드를 제외한 다른 자식노드들까지의 거리들 중
// 최대값이 그 방향의 최대가 된다. O(V + E)
// 3. 이제 각 노드들에서 갈 수 있는 모든 거리를 알고 있기 때문에, 노드를
// 순회하면서 값을 찾아낸다. O(E)
