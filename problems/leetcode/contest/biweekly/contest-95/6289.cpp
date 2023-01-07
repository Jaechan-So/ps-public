// 6289. Find Xor-Beauty of Array
// https://leetcode.com/contest/biweekly-contest-95/problems/find-xor-beauty-of-array/
// Result: Accepted

using namespace std;

#include <vector>

class Solution {
public:
  int xorBeauty(vector<int> &nums) {
    int totalXor = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      totalXor ^= nums[i];
    }

    int answerXor = 0;
    for (int i = 0; i < n; i++) {
      answerXor ^= (totalXor & nums[i]);
    }

    return answerXor;
  }
};

// 전부 다 구할 수 없음. n^3 경우의 수를 모두 찾아야 하기 때문
// 수식을 변형해야 할 것으로 보임. 그럼 O(n)으로 축소가 될 듯?
// (x | y) & z
// (x & z) | (y & z)
// x ^ y === (~x & y) | (x & ~y)
// 전부 bitwise XOR -> 1이 홀수개인 곳만.
// & z가 걸리면 일단 z안에서만 움직임. (z의 1이 0이 되는 선택지만 존재)
// O(1) 시간복잡도 안에 동일한 z에 대한 것만 찾으면 ok
// 그럼 찾은 것들은 전부 xor해서 값을 낼 수 있음.
// 모든 (x | y) 의 xor 값들을 알면 됨. 이건 미리 계산해야 함
// x를 고정하고 생각하면, 개수가 홀수이면 x | (각 원소 xor), 짝수이면 ~x & (각
// 원소 xor) (각 원소 xor) | (각 원소 xor), (각 ~x xor) & (각 원소 xor) (각 원소
// xor)
