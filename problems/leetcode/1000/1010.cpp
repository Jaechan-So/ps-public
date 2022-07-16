// 1010. Pairs of Songs With Total Durations Divisible by 60
// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

using namespace std;

#include <vector>

class Solution {
public:
  int numPairsDivisibleBy60(vector<int> &time) {
    long long answer = 0;

    long long songCountByTimeRemainder[61] = {
        0,
    };

    for (auto &t : time) {
      int remainder = t % 60;
      songCountByTimeRemainder[remainder]++;
    }

    for (int i = 1; i < 30; i++) {
      answer += songCountByTimeRemainder[i] * songCountByTimeRemainder[60 - i];
    }
    answer +=
        songCountByTimeRemainder[0] * (songCountByTimeRemainder[0] - 1) / 2;
    answer +=
        songCountByTimeRemainder[30] * (songCountByTimeRemainder[30] - 1) / 2;

    return (int)answer;
  }
};
