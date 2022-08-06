// 815. Bus Routes
// https://leetcode.com/problems/bus-routes/

using namespace std;

#include <map>
#include <queue>
#include <set>

typedef pair<int, int> pii; // (stop, busCount)

class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int source,
                            int target) {
    map<int, set<int>> availableBuses;

    for (int i = 0; i < routes.size(); i++) {
      for (auto &stop : routes[i]) {
        if (availableBuses.find(stop) == availableBuses.end()) {
          availableBuses[stop] = set<int>({i});
        } else {
          availableBuses[stop].insert(i);
        }
      }
    }

    queue<pii> q;
    q.push({source, 0});

    set<int> visitedStops;
    visitedStops.insert(source);

    while (!q.empty()) {
      pii stopAndBusCount = q.front();
      int stop = stopAndBusCount.first, busCount = stopAndBusCount.second;
      q.pop();

      if (stop == target) {
        return busCount;
      }

      for (auto &busIndex : availableBuses[stop]) {
        for (auto &availableStop : routes[busIndex]) {
          if (visitedStops.find(availableStop) == visitedStops.end()) {
            visitedStops.insert(availableStop);
            q.push({availableStop, busCount + 1});
          }
        }

        routes[busIndex].clear();
      }
    }

    return -1;
  }
};
