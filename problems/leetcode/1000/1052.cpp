// 1052. Grumpy Bookstore Owner
// https://leetcode.com/problems/grumpy-bookstore-owner/

using namespace std;

#include <vector>

class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    // 1. Get sum of every grumpy[i] == 0 cell's customers.
    int answer = 0;
    for (int i = 0; i < customers.size(); i++) {
      if (grumpy[i] == 0) {
        answer += customers[i];
      }
    }

    // 2. With using sliding window, get the advantage of each window's minutes.
    int maxUnsatisfiedCustomers = 0;
    for (int i = 0; i < minutes; i++) {
      maxUnsatisfiedCustomers += (grumpy[i] == 1 ? customers[i] : 0);
    }

    int unsatisfiedCustomers = maxUnsatisfiedCustomers;
    for (int i = 1; i <= customers.size() - minutes; i++) {
      unsatisfiedCustomers -= grumpy[i - 1] == 1 ? customers[i - 1] : 0;
      unsatisfiedCustomers +=
          grumpy[i + minutes - 1] == 1 ? customers[i + minutes - 1] : 0;
      maxUnsatisfiedCustomers =
          max(maxUnsatisfiedCustomers, unsatisfiedCustomers);
    }

    // 3. Find 1. + max(2.) .
    return answer + maxUnsatisfiedCustomers;
  }
};
