// 1235. Maximum Profit in Job Scheduling
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

using namespace std;

#include <map>
#include <vector>

class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    int n = startTime.size();

    vector<vector<int>> jobs;
    for (int i = 0; i < n; i++) {
      jobs.push_back({startTime[i], endTime[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end(), greater<vector<int>>());

    int currentMaxProfit = jobs[0][2];
    map<int, int> maxProfitWithStartTime;
    maxProfitWithStartTime[jobs[0][0]] = currentMaxProfit;

    for (int i = 0; i < n; i++) {
      int et = jobs[i][1], st = jobs[i][0], p = jobs[i][2];

      map<int, int>::iterator iter = maxProfitWithStartTime.lower_bound(et);

      if (iter == maxProfitWithStartTime.end()) {
        currentMaxProfit = max(currentMaxProfit, p);
        maxProfitWithStartTime[st] =
            max(maxProfitWithStartTime[st], currentMaxProfit);
        continue;
      }

      currentMaxProfit = max(currentMaxProfit, p + iter->second);
      maxProfitWithStartTime[st] = currentMaxProfit;
    }

    return currentMaxProfit;
  }
};

// dp[n]을 시간 n에서 시작해서 얻을 수 있는 최대 profit이라고 하자.
// 어차피 startTime에 등장하는 시간의 종류가 정해져 있기 때문에, 큰 startTime을
// 가진 job부터 순회하면서 아래의 동작을 반복한다. job의 startTime, endTime,
// profit에 대해서 dp[startTime] = max(profit + dp[lower_bound(endTime)],
// ...(startTime <= t < endTime 에 존재하는 모든 dp[k]들)) 특정 job을 선택했을
// 때의 profit과, 시간에 따른 profit을 구분해야 한다.
