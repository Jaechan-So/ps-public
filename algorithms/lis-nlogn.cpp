#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class LisNLogN {
 public:
  static int longest_increasing_subsequence(vector<int>& v) {
    vector<int> current_status;

    for (int i = 0; i < v.size(); i++) {
      int current_element = v[i];
      vector<int>::iterator iter = lower_bound(
          current_status.begin(), current_status.end(), current_element);

      if (iter == current_status.end()) {
        current_status.push_back(current_element);
      } else {
        *iter = current_element;
      }
    }

    return current_status.size();
  }
};

int main() {
  vector<int> v = {10, 20, 40, 5, 6, 7, 8, 9};
  cout << LisNLogN::longest_increasing_subsequence(v) << '\n';
  return 0;
}
