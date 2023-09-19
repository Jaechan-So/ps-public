// 1679. Max Number of K-Sum Pairs
// https://leetcode.com/problems/max-number-of-k-sum-pairs/description/

using namespace std;

#include <map>
#include <vector>

class Solution {
public:
  int maxOperations(vector<int> &nums, int k) {
    map<int, int> counts;

    for (int n : nums) {
      counts[n]++;
    }

    int operations = 0;
    for (map<int, int>::iterator iter = counts.begin(); iter != counts.end();
         iter++) {
      if (iter->first > (k / 2)) {
        break;
      }

      if (k % 2 == 0 && iter->first == (k / 2)) {
        operations += (iter->second / 2);
      } else {
        operations += min(iter->second, counts[k - iter->first]);
      }
    }

    return operations;
  }
};

// 1. 각각의 수를 count해서 map에 저장
// 2. <= k / 2가 될 때 까지, k - m이 map에 존재하는지 확인하고 min(map[m], map[k
// - m])의 합을 구함 이 때 k % 2 == 0이면, k / 2의 경우에는 그냥 개수를 2로 나눈
// 몫을 더해주어야 함.
