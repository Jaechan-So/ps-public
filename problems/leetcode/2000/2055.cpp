// 2055. Plates Between Candles
// https://leetcode.com/problems/plates-between-candles/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  vector<int> platesBetweenCandles(string s, vector<vector<int>> &queries) {
    vector<int> answer;
    int length = s.size();

    // Getting first met leftmost candle position by DP
    // Getting first met rightmost candle position by DP
    // Getting number of plates between above two position by Prefix Sum

    vector<int> firstMetCandlePositionForward(length, -1);
    for (int i = 0; i < length; i++) {
      if (s[i] == '|') {
        int index = i;
        while (index >= 0 && firstMetCandlePositionForward[index] == -1) {
          firstMetCandlePositionForward[index] = i;
          index--;
        }
      }
    }

    vector<int> firstMetCandlePositionBackward(length, -1);
    for (int i = length - 1; i >= 0; i--) {
      if (s[i] == '|') {
        int index = i;
        while (index < length && firstMetCandlePositionBackward[index] == -1) {
          firstMetCandlePositionBackward[index] = i;
          index++;
        }
      }
    }

    vector<int> plateCountPrefixSum(length + 1, 0);
    for (int i = 0; i < length; i++) {
      plateCountPrefixSum[i + 1] =
          plateCountPrefixSum[i] + (s[i] == '*' ? 1 : 0);
    }

    for (int i = 0; i < queries.size(); i++) {
      int left = queries[i][0], right = queries[i][1];

      int leftMostCandlePosition = firstMetCandlePositionForward[left];
      int rightMostCandlePosition = firstMetCandlePositionBackward[right];

      if (leftMostCandlePosition == -1 || rightMostCandlePosition == -1) {
        answer.push_back(0);
      } else if (right < leftMostCandlePosition ||
                 leftMostCandlePosition < left) {
        answer.push_back(0);
      } else {
        answer.push_back(plateCountPrefixSum[rightMostCandlePosition + 1] -
                         plateCountPrefixSum[leftMostCandlePosition]);
      }
    }

    return answer;
  }
};
