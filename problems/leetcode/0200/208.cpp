// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/description/

#include <string>

using namespace std;

#define ALPHABET_COUNT 26

class Trie {
public:
  Trie *root[ALPHABET_COUNT];
  bool isFinishExists = false;

  Trie() {
    for (int i = 0; i < ALPHABET_COUNT; i++) {
      root[i] = nullptr;
    }
  }

  void insert(string word) {
    int index = 0;
    Trie *node = this;

    while (index < word.size()) {
      int nodeIndex = word[index] - 'a';
      if (!node->root[nodeIndex]) {
        node->root[nodeIndex] = new Trie();
      }
      node = node->root[nodeIndex];
      index++;
    }

    node->isFinishExists = true;
  }

  bool searchInner(string &word, int index, Trie *node) {
    if (index >= word.size()) {
      return node->isFinishExists;
    }

    int nodeIndex = word[index] - 'a';
    if (!node->root[nodeIndex]) {
      return false;
    }

    return searchInner(word, index + 1, node->root[nodeIndex]);
  }

  bool search(string word) { return searchInner(word, 0, this); }

  bool startsWithInner(string &word, int index, Trie *node) {
    if (index >= word.size()) {
      return true;
    }

    int nodeIndex = word[index] - 'a';
    if (!node->root[nodeIndex]) {
      return false;
    }

    return startsWithInner(word, index + 1, node->root[nodeIndex]);
  }

  bool startsWith(string prefix) { return startsWithInner(prefix, 0, this); }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
