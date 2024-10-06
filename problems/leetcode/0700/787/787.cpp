// 787. Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/

using namespace std;

#include <map>
#include <queue>
#include <vector>

typedef pair<int, pair<int, int>> piii;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k) {
    map<int, vector<pair<int, int>>> flightPrices;
    for (auto &flight : flights) {
      int from = flight[0], to = flight[1], price = flight[2];
      flightPrices[from].push_back({to, price});
    }

    int currentStops[100];
    fill_n(currentStops, n, INT_MAX);

    priority_queue<piii, vector<piii>, greater<piii>>
        pq; // { price, { city, stops } }
    pq.push({0, {src, 0}});

    while (!pq.empty()) {
      int price = pq.top().first, city = pq.top().second.first,
          stops = pq.top().second.second;
      pq.pop();

      if (city == dst) {
        return price;
      }

      if (currentStops[city] < stops) {
        continue;
      }

      currentStops[city] = stops;

      if (stops > k) {
        continue;
      }

      for (auto &flight : flightPrices[city]) {
        pq.push({price + flight.second, {flight.first, stops + 1}});
      }
    }

    return -1;
  }
};
