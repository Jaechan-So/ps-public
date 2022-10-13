// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/

using namespace std;

#include <queue>
#include <vector>

typedef pair<int, int> pii; // temperature, index

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> answer(temperatures.size(), 0);

    pq.push({temperatures[0], 0});
    for (int i = 1; i < temperatures.size(); i++) {
      while (!pq.empty() && pq.top().first < temperatures[i]) {
        answer[pq.top().second] = i - pq.top().second;
        pq.pop();
      }

      pq.push({temperatures[i], i});
    }

    return answer;
  }
};
