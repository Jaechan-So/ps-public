// 2034. Stock Price Fluctuation
// https://leetcode.com/problems/stock-price-fluctuation/

using namespace std;

#include <map>
#include <queue>

typedef pair<int, int> pii; // (price, timestamp)

class StockPrice {
public:
  int latestTimestamp = 0;
  int latestPrice = 0;
  map<int, int> records; // (timestamp, price)

  priority_queue<pii, vector<pii>, less<pii>> maxQueue;
  priority_queue<pii, vector<pii>, greater<pii>> minQueue;

  StockPrice() {}

  void update(int timestamp, int price) {
    if (latestTimestamp < timestamp) {
      latestTimestamp = timestamp;
    }
    if (latestTimestamp == timestamp) {
      latestPrice = price;
    }

    records[timestamp] = price;

    maxQueue.push({price, timestamp});
    minQueue.push({price, timestamp});
  }

  int current() { return latestPrice; }

  int maximum() {
    while (records[maxQueue.top().second] != maxQueue.top().first) {
      maxQueue.pop();
    }

    return maxQueue.top().first;
  }

  int minimum() {
    while (records[minQueue.top().second] != minQueue.top().first) {
      minQueue.pop();
    }

    return minQueue.top().first;
  }
};
