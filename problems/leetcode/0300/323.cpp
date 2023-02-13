// 323. Number of Connected Components in an Undirected Graph
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/

using namespace std;

#include <set>
#include <vector>

class Solution {
public:
  int countComponents(int n, vector<vector<int>> &edges) {
    vector<int> parents(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    for (vector<int> &edge : edges) {
      int vertex1 = edge[0], vertex2 = edge[1];

      int parent2 = getParent(parents, vertex2);
      parents[parent2] = getParent(parents, vertex1);
    }

    set<int> distinctParents;
    for (int i = 0; i < n; i++) {
      int parent = getParent(parents, i);
      if (distinctParents.find(parent) == distinctParents.end()) {
        distinctParents.insert(parent);
      }
    }

    return distinctParents.size();
  }

  int getParent(vector<int> &parents, int i) {
    while (i != parents[i]) {
      i = parents[i];
    }
    return i;
  }
};
