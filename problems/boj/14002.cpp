#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000];
int length[1000];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    arr[i] = input;
  }

  for (int i = 0; i < n; i++) {
    length[i] = 1;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) {
        length[i] = max(length[i], length[j] + 1);
      }
    }
  }

  stack<int> path;
  int index = max_element(length, length + n) - length;
  path.push(index);
  while (length[index] > 1) {
    int current_length = length[index];
    int current_index = index;
    while (current_length - 1 != length[index] ||
           arr[current_index] <= arr[index]) {
      index--;
    }
    path.push(index);
  }

  cout << path.size() << '\n';
  while (!path.empty()) {
    int elem = path.top();
    path.pop();
    cout << arr[elem] << ' ';
  }
  cout << '\n';

  return 0;
}
