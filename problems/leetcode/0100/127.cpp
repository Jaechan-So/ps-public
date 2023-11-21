// 127. Word Ladder
// https://leetcode.com/problems/word-ladder/description/

using namespace std;

#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef pair<int, string> pis;

class Solution {
public:
  unordered_map<string, unordered_set<string>> adj;
  unordered_map<string, int> dist;

  int getDiffCount(string &s1, string &s2) {
    int n = s1.size(), count = 0;

    for (int i = 0; i < n; i++) {
      count += (s1[i] != s2[i] ? 1 : 0);
    }

    return count;
  }

  bool isConnectable(string &s1, string &s2) {
    return getDiffCount(s1, s2) == 1;
  }

  void buildAdjacencyList(vector<string> &wordList) {
    int n = wordList.size();

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (isConnectable(wordList[i], wordList[j])) {
          adj[wordList[i]].insert(wordList[j]);
          adj[wordList[j]].insert(wordList[i]);
        }
      }
    }
  }

  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    vector<string> totalWordList(wordList);
    totalWordList.push_back(beginWord);
    buildAdjacencyList(totalWordList);

    priority_queue<pis, vector<pis>, greater<pis>> pq;
    pq.push({1, beginWord});

    for (string &word : wordList) {
      dist[word] = INT_MAX;
    }
    dist[beginWord] = 1;

    while (!pq.empty()) {
      int prevDist = pq.top().first;
      string node = pq.top().second;
      pq.pop();

      for (string next : adj[node]) {
        if (prevDist + 1 < dist[next]) {
          dist[next] = prevDist + 1;
          pq.push({dist[next], next});
        }
      }
    }

    return dist[endWord] == INT_MAX ? 0 : dist[endWord];
  }
};

// wordList의 각 word를 그래프의 vertex로 생각.
// edge는 차이가 1개만 나는 word끼리만 연결 가능. (방향 없음)
// 이 때 beginWord부터 endWord까지 최단 거리. (Dijkstra?)
// 즉, word 간 Adjacency List를 구축하면 된다.
