// 2183. Count Array Pairs Divisible by K
// https://leetcode.com/problems/count-array-pairs-divisible-by-k/description/

using namespace std;

#include <vector>

class Solution {
public:
  // Tiny Tip
  // The number that has maximum number of divisior, which is between 1 and 1e5
  // is 60480, with 240 divisiors. Source: ChatGPT

  vector<int> divisorsOfK;

  void saveAllDivisorsOfK(int k) {
    for (int i = 1; i <= k; i++) {
      if (k % i == 0) {
        divisorsOfK.push_back(i);
      }
    }
    divisorsOfK.push_back(k);
  }

  long long countPairs(vector<int> &nums, int k) {
    saveAllDivisorsOfK(k);

    unordered_map<int, int> gcdToCount;
    for (int num : nums) {
      for (int i = divisorsOfK.size() - 1; i >= 0; i--) {
        if (num % divisorsOfK[i] == 0) {
          gcdToCount[divisorsOfK[i]]++;
          break;
        }
      }
    }

    long long count = 0;
    for (unordered_map<int, int>::iterator iter1 = gcdToCount.begin();
         iter1 != gcdToCount.end(); iter1++) {
      for (unordered_map<int, int>::iterator iter2 = gcdToCount.begin();
           iter2 != gcdToCount.end(); iter2++) {
        long long gcd1 = iter1->first, gcd2 = iter2->first,
                  mulOfGcd = gcd1 * gcd2;
        int count1 = iter1->second, count2 = iter2->second;

        if (mulOfGcd % k == 0) {
          long long incr = gcd1 == gcd2 ? count1 - 1 : count2;
          count += ((long long)count1 * incr);
        }
      }
    }

    return count / 2;
  }
};

// 예를 들어 k = 36이라고 하고, 어떤 수가 소인수분해했을 때 12를 가지고 있다라고
// 하면, 최소 3을 가지고 있는 모든 수의 개수를 찾으면 되긴 한다. 이를 위해서는
// 소인수분해했을 때의 멱집합에 대한 정보를 모두 유지해야 하는데, 그것을 저장할
// 수 없을 것으로 보인다. (메모리 초과) k를 소인수분해했을 때, 나올 수 있는
// 멱집합에 대해서 각각을 조사해둔다. 그리고 반대쪽에 있는 걸 매칭해서 곱해주고,
// 총 합에 추가한다. 만약 k의 배수이면 모든 수가 다 되니까, 그냥 n - 1을 더하면
// 된다. 마지막에 2로 나눠줘야 함(Pair를 2번 세었으니까)
