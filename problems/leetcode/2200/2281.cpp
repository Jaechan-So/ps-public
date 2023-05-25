// 2281. Sum of Total Strength of Wizards
//  https://leetcode.com/problems/sum-of-total-strength-of-wizards/description/

typedef long long ll;

using namespace std;

#include <vector>

class Solution {
public:
  int totalStrength(vector<int> &strength) {
    vector<int> leftIndicies = getFirstSmallLeftIndicies(strength),
                rightIndicies = getFirstSmallOrEqualRightIndicies(strength);
    vector<ll> prePreSum = getPrePreSum(strength);

    ll totalStrength = 0;
    for (int i = 0; i < strength.size(); i++) {
      int leftCount = i - leftIndicies[i], rightCount = rightIndicies[i] - i;
      ll leftValue =
          leftCount * getMod(prePreSum[i + rightCount + 1] - prePreSum[i + 1]);
      ll rightValue =
          rightCount * getMod(prePreSum[i + 1] - prePreSum[i - leftCount + 1]);
      totalStrength =
          getMod(getMod(totalStrength) +
                 getMod(getMod(strength[i]) * getMod(leftValue - rightValue)));
    }

    return (int)getMod(totalStrength + 1000000007);
  }

  vector<int> getFirstSmallLeftIndicies(vector<int> &strength) {
    vector<int> v, indicies(strength.size(), -1);

    for (int i = strength.size() - 1; i >= 0; i--) {
      while (!v.empty() && strength[i] < strength[v.back()]) {
        indicies[v.back()] = i;
        v.pop_back();
      }
      v.push_back(i);
    }

    return indicies;
  }

  vector<int> getFirstSmallOrEqualRightIndicies(vector<int> &strength) {
    vector<int> v, indicies(strength.size(), strength.size());

    for (int i = 0; i < strength.size(); i++) {
      while (!v.empty() && strength[i] <= strength[v.back()]) {
        indicies[v.back()] = i;
        v.pop_back();
      }
      v.push_back(i);
    }

    return indicies;
  }

  vector<ll> getPrePreSum(vector<int> &strength) {
    vector<ll> preSum(strength.size() + 1, 0);
    for (int i = 1; i <= strength.size(); i++) {
      preSum[i] = getMod(preSum[i - 1] + (ll)strength[i - 1]);
    }

    vector<ll> prePreSum(preSum.size() + 1, 0);
    for (int i = 2; i <= preSum.size(); i++) {
      prePreSum[i] = getMod(prePreSum[i - 1] + preSum[i - 1]);
    }

    return prePreSum;
  }

  ll getMod(ll l) { return l % 1000000007; }
};
