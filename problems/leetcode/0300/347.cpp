// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> answer;
    priority_queue<pair<int, int>> pq; // pair of (frequency, number)
    map<int, int> frequencies;         // number for key, frequency for value

    for (auto &num : nums) {
      if (frequencies.find(num) != frequencies.end()) {
        frequencies[num]++;
      } else {
        frequencies[num] = 1;
      }
    }

    for (auto &pair : frequencies) {
      int num = pair.first;
      int frequency = pair.second;
      pq.push(make_pair(frequency, num));
    }

    for (int i = 0; i < k; i++) {
      pair<int, int> p = pq.top();
      int num = p.second;
      pq.pop();
      answer.push_back(num);
    }

    return answer;
  }
};
