// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/

using namespace std;

#include <vector>

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> answer(temperatures.size(), 0);
    int hottestTemperature = 0;

    for (int i = temperatures.size() - 1; i >= 0; i--) {
      if (temperatures[i] >= hottestTemperature) {
        hottestTemperature = temperatures[i];
        continue;
      }

      int dayDifference = 1;
      while (temperatures[i] >= temperatures[i + dayDifference]) {
        dayDifference += answer[i + dayDifference];
      }
      answer[i] = dayDifference;
    }

    return answer;
  }
};
