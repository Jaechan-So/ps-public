// 1857. Largest Color Value in a Directed Graph
// https://leetcode.com/problems/largest-color-value-in-a-directed-graph/description/

using namespace std;

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool dfs(string &colors, unordered_map<int, vector<int>> &adj,
           unordered_set<int> &visited,
           unordered_map<int, unordered_map<char, int>> &cache, int index) {
    if (visited.find(index) != visited.end()) {
      return false;
    }
    if (cache.find(index) != cache.end()) {
      return true;
    }

    char color = colors[index];
    visited.insert(index);

    for (int next : adj[index]) {
      bool result = dfs(colors, adj, visited, cache, next);
      if (!result) {
        return false;
      }
      for (char ch = 'a'; ch <= 'z'; ch++) {
        cache[index][ch] = max(cache[index][ch], cache[next][ch]);
      }
    }
    cache[index][color]++;

    visited.erase(index);
    return true;
  }

  int largestPathValue(string colors, vector<vector<int>> &edges) {
    int n = colors.size();

    unordered_set<int> indegree;
    unordered_map<int, vector<int>> adj;
    for (vector<int> &e : edges) {
      int start = e[0], end = e[1];

      adj[start].push_back(end);
      indegree.insert(end);
    }

    unordered_set<int> visited;
    unordered_map<int, unordered_map<char, int>> cache;
    int path = -1;

    for (int start = 0; start < n; start++) {
      visited.clear();
      bool result = dfs(colors, adj, visited, cache, start);
      if (!result) {
        return -1;
      }
      for (char ch = 'a'; ch <= 'z'; ch++) {
        path = max(path, cache[start][ch]);
      }
    }

    return path;
  }
};

// 0. edges를 adjacency list로 변환한다.
// 1. DFS를 이용해서 각 vertex를 순회한다. 출발점으로 가능한 indegree == 0인
// vertex만 순회하면 된다.
// 2. 매 DFS 상황에서, 색깔별 count를 포함한 map을 들고 이동한다. DFS를 빠져나갈
// 때 색깔을 제거해주어야 한다.
// 3. 매 DFS 상황에서, 만약 이미 방문한 노드를 또 방문하면 cycle이 존재하는
// 것이므로 return -1. 이미 방문한 노드는 마찬가지로 DFS를 빠져나갈 때
// 제거해준다.
// 4. Path의 끝에 도달하면, O(26)으로 모든 색깔의 max 값을 구한다.
