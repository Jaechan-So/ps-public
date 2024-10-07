// 759. Employee Free Time
// https://leetcode.com/problems/employee-free-time/description/

using namespace std;

#include <queue>
#include <vector>

// Definition for an Interval.
class Interval {
public:
  int start;
  int end;

  Interval() {}

  Interval(int _start, int _end) {
    start = _start;
    end = _end;
  }
};

class Solution {
public:
  vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (vector<Interval> &employee : schedule) {
      for (Interval &interval : employee) {
        pq.push({interval.start, interval.end});
      }
    }

    vector<pair<int, int>> overlaps;
    int start = pq.top().first, end = pq.top().second;
    pq.pop();
    while (!pq.empty()) {
      int nextStart = pq.top().first, nextEnd = pq.top().second;
      pq.pop();
      if (nextStart <= end) {
        end = max(end, nextEnd);
      } else {
        overlaps.push_back({start, end});
        start = nextStart;
        end = nextEnd;
      }
    }
    overlaps.push_back({start, end});

    vector<Interval> freeTimes;
    for (int i = 1; i < overlaps.size(); i++) {
      freeTimes.push_back(Interval(overlaps[i - 1].second, overlaps[i].first));
    }
    return freeTimes;
  }
};

// 1. 모든 schedule을 Priority Queue에 넣는다.
// 2. Priority Queue에서 하나씩 빼면서 합칠 수 있는 구간이라면 계속 합친다.
// 3. 합쳐진 schedule의 사이 구간들을 반환한다.
