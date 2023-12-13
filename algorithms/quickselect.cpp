using namespace std;

#include <iostream>
#include <vector>

// Returns the k-th smallest element in the array.
int quickSelect(vector<int> &v, int k) {
  int pivot = v[0];

  vector<int> smaller, bigger;
  for (int i = 1; i < v.size(); i++) {
    if (v[i] < pivot) {
      smaller.push_back(v[i]);
    } else {
      bigger.push_back(v[i]);
    }
  }

  if (k <= smaller.size()) {
    return quickSelect(smaller, k);
  }

  if (k > smaller.size() + 1) {
    return quickSelect(bigger, k - smaller.size() - 1);
  }

  return pivot;
}

int main() {
  vector<int> v({2, 4, 8, 7, 5, 9, 3});
  cout << quickSelect(v, 2) << '\n';
  cout << quickSelect(v, 3) << '\n';
  cout << quickSelect(v, 4) << '\n';
  cout << quickSelect(v, 5) << '\n';

  return 0;
}
