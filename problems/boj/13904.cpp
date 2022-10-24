#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int n, max_due = 0;
int result[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    assigns;

int main() {
  for (int i = 0; i < 1001; i++) {
    result[i] = 0;
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    int d, w;
    cin >> d >> w;
    max_due = max(max_due, d);
    assigns.push(pair<int, int>(d, w));
  }

  while (!assigns.empty()) {
    pair<int, int> cur = assigns.top();
    assigns.pop();
    int min_index = 1;
    for (int i = 1; i <= cur.first; i++) {
      if (result[i] < result[min_index]) {
        min_index = i;
      }
    }
    result[min_index] = cur.second;
  }

  int sum = 0;
  for (int i = 1; i <= max_due; i++) {
    sum += result[i];
  }

  cout << sum << '\n';
  return 0;
}
