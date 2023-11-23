// 49. Group Anagrams
// https://leetcode.com/problems/group-anagrams/description/

using namespace std;

#include <string>
#include <vector>

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> dict;

    for (string &str : strs) {
      string sorted(str);
      sort(sorted.begin(), sorted.end());
      dict[sorted].push_back(str);
    }

    vector<vector<string>> groups;
    for (pair<string, vector<string>> p : dict) {
      groups.push_back(p.second);
    }

    return groups;
  }
};
