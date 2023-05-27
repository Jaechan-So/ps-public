// 402. Remove K Digits
// https://leetcode.com/problems/remove-k-digits/description/

using namespace std;

#include <string>

class Solution {
public:
  string removeKdigits(string num, int k) {
    int removeCount = 0;
    string digitRemovedNum;

    for (char ch : num) {
      while (removeCount < k && !digitRemovedNum.empty() &&
             ch < digitRemovedNum.back()) {
        digitRemovedNum.pop_back();
        removeCount++;
      }
      if (!(digitRemovedNum.empty() && ch == '0')) {
        digitRemovedNum.push_back(ch);
      }
    }

    while (!digitRemovedNum.empty() && removeCount < k) {
      digitRemovedNum.pop_back();
      removeCount++;
    }
    if (digitRemovedNum.empty()) {
      digitRemovedNum.push_back('0');
    }
    return digitRemovedNum;
  }
};

// 1. 오름차순으로 Monotonic Stack을 쌓는다.
// 2. 만약 개수가 모자라면 뒤에서부터 모자란 개수만큼 채워 넣는다.
// (오름차순이므로, 뒤에걸 채워 넣는게 더 유리함)
// 2. 가 아니라, 그냥 빼는 횟수를 세면서 k가 넘으면 그냥 쌓는다.
