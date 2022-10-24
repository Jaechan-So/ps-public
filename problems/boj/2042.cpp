#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<long long> inputs, segtree;

long long init(int start, int end, int node) {
  if (start == end) {
    segtree[node] = inputs[start];
  } else {
    int mid = (start + end) / 2;
    segtree[node] =
        init(start, mid, node * 2) + init(mid + 1, end, (node * 2) + 1);
  }
  return segtree[node];
}

long long get_sum(int start, int end, int node, int left, int right) {
  if (end < left || right < start) {
    return 0;
  } else {
    if (left <= start && end <= right) {
      return segtree[node];
    } else {
      int mid = (start + end) / 2;
      return get_sum(start, mid, node * 2, left, right) +
             get_sum(mid + 1, end, (node * 2) + 1, left, right);
    }
  }
}

void update(int start, int end, int node, int index, long long diff) {
  segtree[node] += diff;
  if (start == end) {
    return;
  }
  int mid = (start + end) / 2;
  if (index <= mid) {
    update(start, mid, node * 2, index, diff);
  } else {
    update(mid + 1, end, (node * 2) + 1, index, diff);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  inputs.push_back(0);
  for (int i = 0; i < n; i++) {
    int input;
    cin >> input;
    inputs.push_back(input);
  }

  segtree.reserve(4 * n);
  init(1, n, 1);

  for (int i = 0; i < m + k; i++) {
    int mod;

    cin >> mod;
    if (mod == 1) {
      int first;
      long long second;
      cin >> first >> second;
      update(1, n, 1, first, second - inputs[first]);
      inputs[first] = second;
    } else if (mod == 2) {
      int first, second;
      cin >> first >> second;
      cout << get_sum(1, n, 1, first, second) << '\n';
    }
  }

  return 0;
}
