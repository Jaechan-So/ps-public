#include <iostream>
#include <vector>

using namespace std;

class LisNSquare {
public:
  static int longest_increasing_subsequence(vector<int> &v) {
    vector<int> results;

    results.push_back(1);
    for (int i = 1; i < v.size(); i++) {
      int dp = 0;
      for (int j = 0; j < i; j++) {
        dp = max(dp, v[j] < v[i] ? results[j] + 1 : 1);
      }
      results.push_back(dp);
    }

    return *max_element(results.begin(), results.end());
  }
};

int main() {
  vector<int> v = {10, 20, 40, 5, 6, 7, 8, 9};
  cout << LisNSquare::longest_increasing_subsequence(v) << '\n';
  return 0;
}
