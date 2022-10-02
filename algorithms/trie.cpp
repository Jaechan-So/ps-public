using namespace std;

#include <iostream>
#include <string>
#include <vector>

const int NUMBER_OF_ALPHABETS = 'z' - 'a' + 1;

struct TrieNode {
  char _value;
  bool _active;
  TrieNode *children[NUMBER_OF_ALPHABETS];

  TrieNode(char value, bool active) {
    _value = value;
    _active = active;
    fill(children, children + NUMBER_OF_ALPHABETS, nullptr);
  }

  ~TrieNode() {
    for (int i = 0; i < NUMBER_OF_ALPHABETS; i++) {
      if (children[i]) {
        delete children[i];
      }
    }
  }
};

class Trie {
private:
  TrieNode *_root;

public:
  Trie() {
    _root = new TrieNode('-', false); // Placeholder
  }

  void insert(string &s) {
    assert(s.size());
    TrieNode *node = _root;

    for (int i = 0; i < s.size(); i++) {
      if (node->children[s[i] - 'a']) {
        node = node->children[s[i] - 'a'];
      } else {
        TrieNode *newNode = new TrieNode(s[i], false);
        node->children[s[i] - 'a'] = newNode;
        node = newNode;
      }
    }

    node->_active = true;
  }

  bool isExist(string &s) {
    assert(s.size());
    TrieNode *node = _root;

    for (int i = 0; i < s.size(); i++) {
      if (!(node->children[s[i] - 'a']) ||
          (i == s.size() - 1 && !(node->children[s[i] - 'a']->_active))) {
        return false;
      }

      node = node->children[s[i] - 'a'];
    }

    return true;
  }
};

int main() {
  Trie *trie = new Trie();

  vector<string> strings({string("asdf"), string("asdasdasd"), string("asd")});
  for (auto s : strings) {
    trie->insert(s);
  }

  vector<string> queryStrings(
      {string("asdf"), string("asdff"), string("asd"), string("asdasdasd")});
  vector<bool> expected({true, false, true, true});
  for (int i = 0; i < queryStrings.size(); i++) {
    assert(trie->isExist(queryStrings[i]) == expected[i]);
  }

  return 0;
}
