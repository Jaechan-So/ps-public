// 269. Alien Dictionary
// https://leetcode.com/problems/alien-dictionary/description/

#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool setDependency(string &word1, string &word2,
                     map<char, set<char>> &dependencies) {
    // If one word is the prefix of another word, return its validity based on
    // precedence. Otherwise, find first different characters and return its
    // precedence.
    for (int j = 0; j < min(word1.size(), word2.size()); j++) {
      if (word1[j] != word2[j]) {
        if (dependencies[word1[j]].find(word2[j]) !=
            dependencies[word1[j]].end()) {
          return false;
        }
        dependencies[word2[j]].insert(word1[j]);
        return true;
      }
    }
    return word1.size() <= word2.size();
  }

  string alienOrder(vector<string> &words) {
    if (words.size() == 1) {
      set<char> chars;
      for (char ch : words[0]) {
        chars.insert(ch);
      }
      string orderString(chars.begin(), chars.end());
      return orderString;
    }

    map<char, set<char>> dependencies;
    for (string &word : words) {
      for (char &ch : word) {
        dependencies[ch] = set<char>();
      }
    }

    for (int i = 0; i < words.size() - 1; i++) {
      if (!setDependency(words[i], words[i + 1], dependencies)) {
        return string("");
      }
    }

    string orderString;
    queue<char> orders;

    vector<char> eraseList;

    for (map<char, set<char>>::iterator iter = dependencies.begin();
         iter != dependencies.end(); iter++) {
      if (iter->second.size() == 0) {
        orders.push(iter->first);
        eraseList.push_back(iter->first);
      }
    }

    for (char ch : eraseList) {
      dependencies.erase(ch);
    }
    eraseList.clear();

    while (!orders.empty()) {
      char ch = orders.front();
      orders.pop();
      orderString.push_back(ch);

      for (map<char, set<char>>::iterator iter = dependencies.begin();
           iter != dependencies.end(); iter++) {
        iter->second.erase(ch);
        if (iter->second.size() == 0) {
          orders.push(iter->first);
          eraseList.push_back(iter->first);
        }
      }

      for (char ch : eraseList) {
        dependencies.erase(ch);
      }
      eraseList.clear();
    }

    return dependencies.empty() ? orderString : string("");
  }
};
