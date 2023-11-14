// 956. Tallest Billboard
// https://leetcode.com/problems/tallest-billboard/description/

using namespace std;

#include <unordered_map>
#include <vector>

class Solution {
public:
  int tallestBillboard(vector<int> &rods) {
    unordered_map<int, int> diffToTaller;
    diffToTaller[0] = 0;

    for (int rod : rods) {
      unordered_map<int, int> newDiffToTaller(diffToTaller);

      for (unordered_map<int, int>::iterator iter = diffToTaller.begin();
           iter != diffToTaller.end(); iter++) {
        int taller = iter->second, smaller = iter->second - iter->first;

        int newTaller = taller + rod, newSmaller = smaller,
            newDiff = newTaller - newSmaller;
        if (newDiffToTaller.find(newDiff) == newDiffToTaller.end() ||
            newDiffToTaller[newDiff] < newTaller) {
          newDiffToTaller[newDiff] = newTaller;
        }

        newTaller = max(taller, smaller + rod),
        newSmaller = min(taller, smaller + rod),
        newDiff = newTaller - newSmaller;
        if (newDiffToTaller.find(newDiff) == newDiffToTaller.end() ||
            newDiffToTaller[newDiff] < newTaller) {
          newDiffToTaller[newDiff] = newTaller;
        }
      }

      diffToTaller = newDiffToTaller;
    }

    return diffToTaller[0];
  }
};

// 의심되는 풀이: Binary Search
// 1 ~ 2500에서 Binary Search를 할 수 있을 것 같음
// 안 되는 이유: 연속성이 보장이 안 됨. 전체 케이스가 크기에 따라 됨 / 안 됨으로
// 2개로 나누어 떨어지지 않음.

// 이 때, rods로부터 나올 수 있는 모든 선택의 경우의 수는 2^20가지
// 또한 각 경우의 수를 Bit 형태로 Encoding이 가능함.
// 이를 이용해서 Mutual Exclusive인지 확인이 가능함.

// Meet in the middle / DP 2가지 방법이 있음.
