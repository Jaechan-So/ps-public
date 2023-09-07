// 436. Find Right Interval
// https://leetcode.com/problems/find-right-interval/description/

using namespace std;

#include <vector>

class Solution {
public:
  vector<pair<int, int>> intervalsWithIndex;

  int getLowerBoundIndex(int i) {
    int n = intervalsWithIndex.size(), start = 0, end = n;

    while (start < end) {
      int mid = (start + end) / 2;
      if (intervalsWithIndex[mid].first < i) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }

    return end == n ? -1 : intervalsWithIndex[end].second;
  }

  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    int n = intervals.size();

    for (int i = 0; i < n; i++) {
      intervalsWithIndex.push_back({intervals[i][0], i});
    }
    sort(intervalsWithIndex.begin(), intervalsWithIndex.end());

    vector<int> indicies;
    for (vector<int> &i : intervals) {
      indicies.push_back(getLowerBoundIndex(i[1]));
    }

    return indicies;
  }
};

// 각 Interval에 대해서 lower_bound와 유사한 연산을 구현해야 한다.
// { start, index } 쌍으로 이루어진 pair를 이용해서 lower_bound를 구현하면 될 것
// 같다.
