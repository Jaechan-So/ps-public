// 1639. Number of Ways to Form a Target String Given a Dictionary
// https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/description/

using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  const int mod = 1e9 + 7;

  int dfs(vector<unordered_map<char, int>> &distribution, string &target, int s,
          int t, vector<vector<int>> &cache, int index1, int index2) {
    if (index2 == t) {
      return 1;
    }

    if (cache[index1][index2] != -1) {
      return cache[index1][index2];
    }

    int count = 0;
    for (int i = index1; i <= s - t + index2; i++) {
      if (distribution[i][target[index2]] > 0) {
        count += (((long long)distribution[i][target[index2]] *
                   (long long)dfs(distribution, target, s, t, cache, i + 1,
                                  index2 + 1)) %
                  mod);
        count %= mod;
      }
    }

    cache[index1][index2] = count;
    return count;
  }

  int numWays(vector<string> &words, string target) {
    int n = words.size(), s = words[0].size(), t = target.size();
    if (s < t) {
      return 0;
    }

    vector<unordered_map<char, int>> distribution(s);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < s; j++) {
        distribution[j][words[i][j]]++;
      }
    }

    vector<vector<int>> cache(s, vector<int>(t, -1));
    return dfs(distribution, target, s, t, cache, 0, 0);
  }
};

// DFS로 모든 경우의 수를 찾는다.
