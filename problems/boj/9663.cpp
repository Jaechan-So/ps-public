#include <cstdlib>
#include <iostream>

using namespace std;

int n, total = 0;
int board[15];

bool promising(int j) {
  for (int i = 0; i < j; i++) {
    if (board[i] == board[j] || j - i == abs(board[j] - board[i])) {
      return false;
    }
  }
  return true;
}

void solve(int c) {
  if (c == n) {
    total++;
    return;
  }

  for (int i = 0; i < n; i++) {
    board[c] = i;
    if (promising(c)) {
      solve(c + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  solve(0);
  cout << total << '\n';

  return 0;
}
