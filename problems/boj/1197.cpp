#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int v, e, answer = 0;
int parents[10001];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
               greater<pair<int, pair<int, int>>>>
    edges;

int findParent(int x) {
  while (x != parents[x]) {
    x = parents[x];
  }
  return x;
}

bool isParentSame(int x, int y) {
  int parent_x = findParent(x);
  int parent_y = findParent(y);
  return (parent_x == parent_y);
}

void unionParents(int x, int y) {
  int parent_x = findParent(x);
  int parent_y = findParent(y);
  parents[parent_x] = parent_y;
}

int main() {
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    edges.push(make_pair(weight, make_pair(from, to)));
  }

  for (int i = 1; i <= v; i++) {
    parents[i] = i;
  }

  int completed_vertices = 0;
  while (completed_vertices < v - 1) {
    pair<int, pair<int, int>> edge = edges.top();
    int weight = edge.first;
    int from = edge.second.first;
    int to = edge.second.second;
    edges.pop();

    if (!isParentSame(from, to)) {
      unionParents(from, to);
      answer += weight;
      completed_vertices += 1;
    }
  }

  cout << answer << '\n';
  return 0;
}
