// 2192. All Ancestors of a Node in a Directed Acyclic Graph
// https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/

using namespace std;

#include <map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  void dfs(unordered_map<int, unordered_set<int>> &ancestors,
           vector<vector<int>> &adj, int num) {
    if (ancestors.find(num) != ancestors.end()) {
      return;
    }

    unordered_set<int> currentAncestors;
    for (int i : adj[num]) {
      dfs(ancestors, adj, i);
      for (int j : ancestors[i]) {
        currentAncestors.insert(j);
      }
      currentAncestors.insert(i);
    }
    ancestors[num] = currentAncestors;
  }

  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n, vector<int>());
    for (vector<int> &e : edges) {
      int from = e[0], to = e[1];
      adj[to].push_back(from);
    }

    unordered_map<int, unordered_set<int>> ancestors;
    vector<vector<int>> answer(n, vector<int>());
    for (int i = 0; i < n; i++) {
      dfs(ancestors, adj, i);
      for (unordered_set<int>::iterator iter = ancestors[i].begin();
           iter != ancestors[i].end(); iter++) {
        answer[i].push_back(*iter);
      }
      sort(answer[i].begin(), answer[i].end());
    }

    return answer;
  }
};
