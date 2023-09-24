// 2867. Count Valid Paths in a Tree
// https://leetcode.com/contest/weekly-contest-364/problems/count-valid-paths-in-a-tree/
// Result: Wrong Answer

using namespace std;

#include <unordered_set>
#include <vector>

class Solution {
public:
  long long answer = 0;
  unordered_set<int> visited;

  bool isPrime(int n) {
    if (n == 1) {
      return false;
    }

    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }

  void dfs(vector<vector<int>> &adj, int i, int prevDepth, int prevPrevDepth,
           int currentDepth) {
    visited.insert(i);
    bool prime = isPrime(i);

    if (prime) {
      answer += (currentDepth - prevDepth - 1);
      for (int child : adj[i]) {
        if (visited.find(child) == visited.end()) {
          dfs(adj, child, currentDepth, prevDepth, currentDepth + 1);
        }
      }
    } else {
      if (prevDepth != 0) {
        answer += (prevDepth - prevPrevDepth);
      }
      for (int child : adj[i]) {
        if (visited.find(child) == visited.end()) {
          dfs(adj, child, prevDepth, prevPrevDepth, currentDepth + 1);
        }
      }
    }

    visited.erase(i);
  }

  long long countPaths(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n + 1, vector<int>());
    for (vector<int> &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    dfs(adj, 1, 0, 0, 1);
    return answer;
  }
};
