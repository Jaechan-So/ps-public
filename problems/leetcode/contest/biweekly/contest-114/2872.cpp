// 2872. Maximum Number of K-Divisible Components
// https://leetcode.com/contest/biweekly-contest-114/problems/maximum-number-of-k-divisible-components/
// Result: Accepted

using namespace std;

#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  unordered_set<int> visited;
  int cuttingEdges = 0;
  unordered_map<int, vector<int>> adj;

  long long dfs(int n, vector<int> &values, int k, int i) {
    visited.insert(i);

    long long sum = values[i];
    for (int child : adj[i]) {
      if (visited.find(child) != visited.end()) {
        continue;
      }
      long long childSum = dfs(n, values, k, child);
      if (childSum % k == 0) {
        cuttingEdges++;
      }
      sum += childSum;
    }

    visited.erase(i);

    return sum;
  }

  int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                              vector<int> &values, int k) {
    for (vector<int> &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }
    dfs(n, values, k, 0);

    return cuttingEdges + 1;
  }
};

// 1. 트리 구조를 순회하면서, 자식 트리가 k로 나누어떨어지는지 확인한다. 나누어
// 떨어지면, 자른 뒤 잘라진 트리 내에서 반복하면 된다.
// 2. 사실상, DFS를 돌면서 cutting edge이면 자르고, cutting edge 개수 + 1 하면
// 된다.
