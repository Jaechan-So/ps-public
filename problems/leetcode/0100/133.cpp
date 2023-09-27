// 133. Clone Graph
// https://leetcode.com/problems/clone-graph/description/

using namespace std;

#include <unordered_map>
#include <vector>

// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  // Value to cloned node pointer.
  unordered_map<int, Node *> valToPointerMap;

  Node *cloneGraph(Node *node) {
    if (!node) {
      return nullptr;
    }
    if (valToPointerMap.find(node->val) != valToPointerMap.end()) {
      return valToPointerMap[node->val];
    }

    Node *cloned = new Node(node->val);
    valToPointerMap[node->val] = cloned;

    for (Node *neighbor : node->neighbors) {
      cloned->neighbors.push_back(cloneGraph(neighbor));
    }
    return cloned;
  }
};
