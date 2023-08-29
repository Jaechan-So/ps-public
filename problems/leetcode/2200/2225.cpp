// 2225. Find Players With Zero or One Losses
// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

using namespace std;

#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches) {
    unordered_map<int, unordered_set<int>> loses;
    unordered_set<int> players;
    for (vector<int> &m : matches) {
      int winner = m[0], loser = m[1];
      players.insert(winner);
      players.insert(loser);
      loses[loser].insert(winner);
    }

    vector<vector<int>> answer(2, vector<int>());
    for (int p : players) {
      if (loses.find(p) == loses.end()) {
        answer[0].push_back(p);
      } else if (loses[p].size() == 1) {
        answer[1].push_back(p);
      }
    }
    sort(answer[0].begin(), answer[0].end());
    sort(answer[1].begin(), answer[1].end());

    return answer;
  }
};
