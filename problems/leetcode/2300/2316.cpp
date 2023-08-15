// 2316. Count Unreachable Pairs of Nodes in an Undirected Graph
// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/

using namespace std;

#include <map>
#include <numeric>
#include <vector>

class Solution {
public:
  int getHead(vector<int> &heads, int i) {
    int head = i;

    while (heads[head] != head) {
      head = heads[head];
    }

    return head;
  }

  long long countPairs(int n, vector<vector<int>> &edges) {
    vector<int> heads(n, 0);
    for (int i = 0; i < n; i++) {
      heads[i] = i;
    }

    for (vector<int> &edge : edges) {
      int a = edge[0], b = edge[1], aHead = getHead(heads, a),
          bHead = getHead(heads, b);
      heads[bHead] = aHead;
    }

    for (int i = 0; i < n; i++) {
      int finalHead = getHead(heads, heads[i]);
      heads[i] = finalHead;
    }

    map<int, int> headAndCounts;
    for (int i = 0; i < n; i++) {
      headAndCounts[heads[i]]++;
    }

    vector<int> counts;
    for (map<int, int>::iterator iter = headAndCounts.begin();
         iter != headAndCounts.end(); iter++) {
      counts.push_back(iter->second);
    }
    int k = counts.size();

    // 2 * (sum of pairs) = (a_1 + a_2 + ... + a_n)^2 - ((a_1)^2 + (a_2)^2 + ...
    // + (a_n)^2)
    long long sum = accumulate(counts.begin(), counts.end(), 0);
    long long squareOfSum = pow(sum, 2);

    long long sumOfSquare = 0;
    for (int i = 0; i < k; i++) {
      sumOfSquare += pow(counts[i], 2);
    }

    return (squareOfSum - sumOfSquare) / 2;
  }
};
