// 692. Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words/

using namespace std;

#include <map>
#include <queue>
#include <string>
#include <vector>

typedef pair<int, string> pis; // (count, string)

class Solution {
public:
  struct comp {
    bool operator()(const pis &pis1, const pis &pis2) {
      if (pis1.first != pis2.first) {
        return pis1.first < pis2.first;
      }

      return pis2.second < pis1.second;
    }
  };

  vector<string> topKFrequent(vector<string> &words, int k) {
    map<string, int> wordCount;

    for (auto &word : words) {
      wordCount[word]++;
    }

    priority_queue<pis, vector<pis>, comp> pq;
    for (auto &p : wordCount) {
      string word = p.first;
      int count = p.second;

      pq.push({count, word});
    }

    vector<string> answer;
    for (int i = 0; i < k; i++) {
      answer.push_back(pq.top().second);
      pq.pop();
    }

    return answer;
  }
};
