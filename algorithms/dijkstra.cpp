using namespace std;

#include <cassert>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

void PrintVectorInt(vector<int> &v) {
  for (int x : v) {
    cout << x << ' ';
  }
  cout << '\n';
}

// Implementation of Dijkstra algorithm.
class Dijkstra {
public:
  // distance_map: vector of vector of int which contains distance_map[i][j]
  // with the distance between i and j.
  // s: Index which we are focused on.
  static vector<int> Solution(vector<vector<int>> &distance_map, int s) {
    int n = distance_map.size();
    vector<int> distances(n, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, s});

    while (!pq.empty()) {
      int dist = pq.top().first, index = pq.top().second;
      pq.pop();

      if (dist >= distances[index]) {
        continue;
      }

      distances[index] = dist;
      for (int i = 0; i < n; i++) {
        if (distance_map[index][i] < 0) {
          continue;
        }

        if (dist + distance_map[index][i] < distances[i]) {
          pq.push({dist + distance_map[index][i], i});
        }
      }
    }

    return distances;
  }
};

int main() {
  // https://blog.naver.com/ndb796/221234424646
  vector<vector<int>> test_data_1({
      {-1, 3, 6, 7},
      {3, -1, 1, -1},
      {6, 1, -1, 1},
      {7, -1, 1, -1},
  });
  vector<int> answer_1 = Dijkstra::Solution(test_data_1, 0);
  PrintVectorInt(answer_1);
  assert(answer_1 == vector<int>({0, 3, 4, 5}));

  return 0;
}
