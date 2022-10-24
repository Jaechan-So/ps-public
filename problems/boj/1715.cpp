#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;

int main() {
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> cards;
  for (int i = 0; i < n; i++) {
    int card;
    cin >> card;
    cards.push(card);
  }

  int sum = 0;
  while (cards.size() > 1) {
    int card1 = cards.top();
    cards.pop();
    int card2 = cards.top();
    cards.pop();
    sum += (card1 + card2);
    cards.push(card1 + card2);
  }

  cout << sum << '\n';
  return 0;
}
