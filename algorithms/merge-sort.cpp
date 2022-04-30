#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// TODO: Extend implementation with templates.
class MergeSort {
 public:
  static void merge_sort(vector<int>& v, int start, int end) {
    if (start == end) return;

    int mid = (start + end) / 2;
    merge_sort(v, start, mid);
    merge_sort(v, mid + 1, end);

    merge(v, start, end, mid);
    return;
  }

 private:
  static void merge(vector<int>& v, int start, int end, int mid) {
    int start_current = start;
    int end_current = mid + 1;
    vector<int> temp;

    while (start_current <= mid && end_current <= end) {
      if (v[start_current] <= v[end_current]) {
        temp.push_back(v[start_current]);
        start_current++;
      } else {
        temp.push_back(v[end_current]);
        end_current++;
      }
    }

    if (start_current > mid) {
      for (int i = end_current; i <= end; i++) {
        temp.push_back(v[i]);
      }
    }

    if (end_current > end) {
      for (int i = start_current; i <= mid; i++) {
        temp.push_back(v[i]);
      }
    }

    copy(temp.begin(), temp.end(), v.begin() + start);
  }
};

int main() {
  vector<int> v = {1, 6, 3, 4, 4, 9};
  MergeSort::merge_sort(v, 0, v.size() - 1);

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << '\n';
  }

  return 0;
}
