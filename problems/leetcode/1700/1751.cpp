// 1751. Maximum Number of Events That Can Be Attended II
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/

using namespace std;

#include <unordered_map>
#include <vector>

struct EventComparator {
  bool operator()(const vector<int> &e1, const vector<int> &e2) {
    return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] < e2[1]);
  }
};

class Solution {
public:
  unordered_map<int, unordered_map<int, int>> cache;

  int lowerBound(vector<vector<int>> &events, int startTime) {
    if (startTime > events[events.size() - 1][0]) {
      return events.size();
    }

    int n = events.size(), start = 0, end = n - 1;

    while (start < end) {
      int mid = (start + end) / 2;

      if (events[mid][0] < startTime) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }

    return end;
  }

  int dfs(vector<vector<int>> &events, int k, int index) {
    if (k == 0 || index == events.size()) {
      return 0;
    }

    if (cache.find(k) != cache.end() &&
        cache[k].find(index) != cache[k].end()) {
      return cache[k][index];
    }

    int maxVal = INT_MIN;

    // 1. Select current event
    int nextIndex = lowerBound(events, events[index][1] + 1);
    maxVal = max(maxVal, events[index][2] + dfs(events, k - 1, nextIndex));

    // 2. Do not select current event
    maxVal = max(maxVal, dfs(events, k, index + 1));

    cache[k][index] = maxVal;
    return maxVal;
  }

  int maxValue(vector<vector<int>> &events, int k) {
    vector<vector<int>> sortedEvents(events);
    sort(sortedEvents.begin(), sortedEvents.end(), EventComparator());

    return dfs(sortedEvents, k, 0);
  }
};

// dp[i][j]: 시간 i보다 작거나 같은 범위에서 j개의 이벤트에 참여했을 때, 최대
// value 이벤트가 시작하는 순서대로 정렬이 되어 있다고 가정할 때, [s, e, v]가
// 있다면 dp[e][j] = dp[s보다 작은 어떤 값, j - 1] + v.

// 이벤트가 끝나는 순서대로 정렬되어 있으면, 이전 이벤트까지 확인했다면 적어도
// 이번 이벤트가 끝나는 것보다 일찍 끝나는 이벤트들은 모두 고려했을 것 dp[i]:
// i개만큼의 이벤트에 참여했을 때, 1 ~ t 시간 범위 내에서의 value의
// 최댓값들이라고 하자.

// events[i]를 추가했을 때, 새로 추가되는 것은 ([s, e, v])
// (s 이전까지의 값) + v가 (e 이전까지)로 새로 추가된다.
