// 1481. Least Number of Unique Integers after K Removals
// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/

using namespace std;

#include <queue>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    unordered_map<int, int> counts;

    for (int elem : arr) {
      counts[elem]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (pair<int, int> p : counts) {
      pq.push(p.second);
    }

    int unique = pq.size(), removed = 0;
    while (!pq.empty()) {
      if (k - pq.top() < 0) {
        return unique - removed;
      }
      k -= pq.top();
      pq.pop();
      removed++;
    }

    return unique - removed;
  }
};

// 1. Frequency Map을 만들고, 순회하면서 k보다 작거나 같아질 때까지 빈도를 뺀다.
// -> O(n), O(n)
