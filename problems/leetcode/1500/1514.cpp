// 1514. Path with Maximum Probability
// https://leetcode.com/problems/path-with-maximum-probability/description/

using namespace std;

#include <map>
#include <queue>
#include <vector>

class Solution {
public:
  double maxProbability(int n, vector<vector<int>> &edges,
                        vector<double> &succProb, int start_node,
                        int end_node) {
    vector<map<int, double>> adj(n);
    for (int i = 0; i < edges.size(); i++) {
      int v1 = edges[i][0], v2 = edges[i][1];
      double prob = succProb[i];
      adj[v1][v2] = prob;
      adj[v2][v1] = prob;
    }

    vector<double> probabilities(n, 0);
    probabilities[start_node] = 1;

    priority_queue<pair<double, int>, vector<pair<double, int>>,
                   less<pair<double, int>>>
        pq;
    pq.push({1, start_node});

    while (!pq.empty()) {
      double prob = pq.top().first;
      int index = pq.top().second;
      pq.pop();

      for (map<int, double>::iterator iter = adj[index].begin();
           iter != adj[index].end(); iter++) {
        int dest = iter->first;
        double nextProb = iter->second;
        if ((prob * nextProb) > probabilities[dest]) {
          double newProb = prob * nextProb;
          probabilities[dest] = newProb;
          pq.push({newProb, dest});
        }
      }
    }

    return probabilities[end_node];
  }
};
