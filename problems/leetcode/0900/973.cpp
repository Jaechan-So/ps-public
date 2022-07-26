// 973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/

using namespace std;

#include <queue>
#include <utility>
#include <vector>

typedef pair<long, int> pli; // (square of distance, index)
typedef long long ll;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    vector<vector<int>> answer;
    int length = points.size();

    priority_queue<pli, vector<pli>, greater<pli>> pq;

    for (int i = 0; i < length; i++) {
      pq.push({squareOf(points[i][0]) + squareOf(points[i][1]), i});
    }

    for (int i = 0; i < k; i++) {
      answer.push_back(points[pq.top().second]);
      pq.pop();
    }

    return answer;
  }

  ll squareOf(int n) { return n * n; }
};
