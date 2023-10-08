// 211. Design Add and Search Words Data Structure
// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

using namespace std;

#include <queue>
#include <string>

class TrieNode {
public:
  bool end = false;
  TrieNode *children[26];

  TrieNode() {
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }
};

class WordDictionary {
public:
  TrieNode *root;

  WordDictionary() { root = new TrieNode(); }

  void addWord(string word) {
    TrieNode *node = root;

    for (char ch : word) {
      int index = ch - 'a';
      if (node->children[index] == nullptr) {
        node->children[index] = new TrieNode();
      }
      node = node->children[index];
    }

    node->end = true;
  }

  bool search(string word) {
    int n = word.size();

    queue<pair<TrieNode *, int>> q; // (node, character index)
    q.push({root, 0});

    while (!q.empty()) {
      TrieNode *node = q.front().first;
      int index = q.front().second;
      q.pop();

      if (index == n) {
        if (node->end) {
          return true;
        }
        continue;
      }

      if (word[index] == '.') {
        for (int i = 0; i < 26; i++) {
          if (node->children[i] != nullptr) {
            q.push({node->children[i], index + 1});
          }
        }
      } else {
        if (node->children[word[index] - 'a'] != nullptr) {
          q.push({node->children[word[index] - 'a'], index + 1});
        }
      }
    }

    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
