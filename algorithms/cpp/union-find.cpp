using namespace std;

#include <vector>

class UnionFind {
  int n = 0;
  vector<int> parent, rank;

  UnionFind(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 1;
    }
  }

  int find(int v) {
    if (v == parent[v]) {
      return v;
    }
    parent[v] = find(parent[v]);
    return parent[v];
  }

  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) {
      return;
    }

    if (rank[u] > rank[v]) {
      swap(u, v);
    }
    parent[u] = v;
    if (rank[u] == rank[v]) {
      rank[v]++;
    }
  }
};
