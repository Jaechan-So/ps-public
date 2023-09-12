// 486. Predict the Winner
// https://leetcode.com/problems/predict-the-winner/description/

using namespace std;

#include <vector>

class Solution {
public:
  bool track(vector<int> &nums, int start, int end, int score1, int score2,
             bool isFirstPlayerTurn) {
    if (end - start == 1) {
      return isFirstPlayerTurn ? score1 + nums[start] >= score2
                               : score1 < score2 + nums[start];
    }

    if (end - start == 2) {
      return isFirstPlayerTurn ? score1 + max(nums[start], nums[start + 1]) >=
                                     score2 + min(nums[start], nums[start + 1])
                               : score1 + min(nums[start], nums[start + 1]) <
                                     score2 + max(nums[start], nums[start + 1]);
    }

    bool result = false;
    if (isFirstPlayerTurn) {
      result = !(track(nums, start + 1, end, score1 + nums[start], score2,
                       !isFirstPlayerTurn) &&
                 track(nums, start, end - 1, score1 + nums[end - 1], score2,
                       !isFirstPlayerTurn));
    } else {
      result = !(track(nums, start + 1, end, score1, score2 + nums[start],
                       !isFirstPlayerTurn) &&
                 track(nums, start, end - 1, score1, score2 + nums[end - 1],
                       !isFirstPlayerTurn));
    }

    return result;
  }

  bool predictTheWinner(vector<int> &nums) {
    return track(nums, 0, nums.size(), 0, 0, true);
  }
};

// 1. 원소가 3개인 경우
// [a, b, c]
// a + min(b, c) vs. max(b, c) // c + min(a, b) vs. max(a, b)
// prev1 + a + min(b, c) < prev2 + max(b, c) && prev1 + c + min(a, b) < prev2 +
// max(a, b)이면, 무조건 패배 prev1 + a + min(b, c) >= prev2 + max(b, c) ||
// prev1 + c + min(a, b) >= prev2 + min(a, b)이면, 승리할 방법이 무조건 있기
// 때문에 Optimal이라는 가정 하에 무조건 승리
// 2. 원소가 4개 이상
// 한 쪽을 선택했는데 무조건 승리이면, Optimal이라는 가정 하에 무조건 승리함
// true, true -> false / true, false -> true / false, false -> true
