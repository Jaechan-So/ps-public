#include <algorithm>
#include <iostream>

using namespace std;

int h, w;
int blocks[501];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> h >> w;
  for (int i = 1; i <= w; i++) {
    int block;
    cin >> block;
    blocks[i] = block;
  }

  int current = 1, answer = 0;
  while (current <= w) {
    int max_index = current + 1;
    for (int i = current + 1; i <= w; i++) {
      if (blocks[max_index] < blocks[i]) {
        max_index = i;
      }
      if (blocks[current] <= blocks[i]) {
        break;
      }
    }

    int wall = min(blocks[current], blocks[max_index]);
    for (int i = current + 1; i < max_index; i++) {
      answer += (wall - blocks[i]);
    }

    current = max_index;
  }

  cout << answer << '\n';
  return 0;
}
