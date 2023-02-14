// 503. Next Greater Element II
// https://leetcode.com/problems/next-greater-element-ii/description/

using namespace std;

#include <queue>
#include <vector>

typedef pair<int, int> pii;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    int maxElement = *max_element(nums.begin(), nums.end());

    vector<int> greaterElements(nums.size(), -1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({nums[0], 0});

    int i = 1;
    while (i < nums.size()) {
      while (!pq.empty() && pq.top().first < nums[i]) {
        if (greaterElements[pq.top().second] == -1) {
          greaterElements[pq.top().second] = nums[i];
        }
        pq.pop();
      }
      pq.push({nums[i], i});
      i++;
    }

    i = 0;
    while (i < nums.size()) {
      while (!pq.empty() && pq.top().first < nums[i]) {
        if (greaterElements[pq.top().second] == -1) {
          greaterElements[pq.top().second] = nums[i];
        }
        pq.pop();
      }
      pq.push({nums[i], i});
      i++;
    }

    return greaterElements;
  }
};
