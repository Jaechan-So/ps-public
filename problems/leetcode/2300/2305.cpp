// 2305. Fair Distribution of Cookies
// https://leetcode.com/problems/fair-distribution-of-cookies/description/

using namespace std;

#include <vector>

class Solution {
public:
  void findMinUnfairness(vector<int> &cookies, int i,
                         vector<int> &childWithCookies, int k,
                         int &unfairness) {
    if (i == cookies.size()) {
      int currentUnfairness =
          *max_element(childWithCookies.begin(), childWithCookies.end());
      if (currentUnfairness < unfairness) {
        unfairness = currentUnfairness;
      }
      return;
    }

    for (int j = 0; j < k; j++) {
      childWithCookies[j] += cookies[i];
      findMinUnfairness(cookies, i + 1, childWithCookies, k, unfairness);
      childWithCookies[j] -= cookies[i];
    }
  }

  int distributeCookies(vector<int> &cookies, int k) {
    vector<int> childWithCookies(k, 0);

    int unfairness = INT_MAX;
    findMinUnfairness(cookies, 0, childWithCookies, k, unfairness);
    return unfairness;
  }
};
