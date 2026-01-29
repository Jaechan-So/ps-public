// 588. Design In-Memory File System
// https://leetcode.com/problems/design-in-memory-file-system/description/

using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

vector<string> parsePath(string path) {
  vector<string> tokens;

  int n = path.size();
  string token;
  for (int i = 1; i < n; i++) {
    if (path[i] == '/') {
      tokens.push_back(token);
      token.clear();
    } else {
      token.push_back(path[i]);
    }
  }
  if (!token.empty()) {
    tokens.push_back(token);
  }

  return tokens;
}

class Entry {
public:
  bool directory = false; // true if directory, false if file
  unordered_map<string, Entry *> children;
  string content;

  Entry(bool _directory) { directory = _directory; }

  bool isDirectory() { return directory; }
};

class FileSystem {
public:
  Entry *root = new Entry(true);

  FileSystem() {}

  vector<string> ls(string path) {
    vector<string> tokens = parsePath(path);

    Entry *entry = root;
    for (string &token : tokens) {
      entry = entry->children[token];
    }

    if (!entry->directory) {
      return vector<string>({tokens.back()});
    }

    vector<string> result;
    for (pair<string, Entry *> p : entry->children) {
      result.push_back(p.first);
    }
    sort(result.begin(), result.end());

    return result;
  }

  void mkdir(string path) {
    vector<string> tokens = parsePath(path);

    Entry *entry = root;
    for (string &token : tokens) {
      if (!entry->children[token]) {
        entry->children[token] = new Entry(true);
      }
      entry = entry->children[token];
    }
  }

  void addContentToFile(string filePath, string content) {
    vector<string> tokens = parsePath(filePath);

    Entry *entry = root;
    for (int i = 0; i < tokens.size() - 1; i++) {
      if (!entry->children[tokens[i]]) {
        entry->children[tokens[i]] = new Entry(true);
      }
      entry = entry->children[tokens[i]];
    }
    if (!entry->children[tokens.back()]) {
      entry->children[tokens.back()] = new Entry(false);
    }
    entry = entry->children[tokens.back()];
    entry->content += content;
  }

  string readContentFromFile(string filePath) {
    vector<string> tokens = parsePath(filePath);

    Entry *entry = root;
    for (string &token : tokens) {
      entry = entry->children[token];
    }

    return entry->content;
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */

// 1. Directory & File 관리
// 2. File은 string 내용 가지고 있음
