// 261. Graph Valid Tree
// https://leetcode.com/problems/graph-valid-tree/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> parents;

  bool validTree(int n, vector<vector<int>> &edges) {
    parents = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    for (auto edge : edges) {
      int vertex1 = edge[0], vertex2 = edge[1];
      int parent1 = findParent(vertex1), parent2 = findParent(vertex2);

      // Graph is not a tree if there is a loop.
      if (parent1 == parent2) {
        return false;
      }

      parents[parent1] = parent2;
    }

    int parent = findParent(0);
    for (int i = 1; i < n; i++) {
      if (findParent(i) != parent) {
        return false;
      }
    }

    return true;
  }

  int findParent(int index) {
    while (index != parents[index]) {
      index = parents[index];
    }
    return index;
  }
};
