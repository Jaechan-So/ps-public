// 239. Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/description/

using namespace std;

#include <map>
#include <queue>
#include <vector>

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    priority_queue<int> pq;
    map<int, int> numToCount;

    for (int i = 0; i < k; i++) {
      numToCount[nums[i]]++;
      pq.push(nums[i]);
    }

    vector<int> maxElements;
    maxElements.push_back(pq.top());

    for (int i = k; i < nums.size(); i++) {
      numToCount[nums[i - k]]--;

      numToCount[nums[i]]++;
      pq.push(nums[i]);

      while (!pq.empty()) {
        if (numToCount.find(pq.top()) == numToCount.end()) {
          pq.pop();
          continue;
        }

        if (numToCount[pq.top()] == 0) {
          numToCount.erase(pq.top());
          pq.pop();
          continue;
        }

        break;
      }

      maxElements.push_back(pq.top());
    }

    return maxElements;
  }
};
