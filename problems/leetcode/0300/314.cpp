// 314. Binary Tree Vertical Order Traversal
// https://leetcode.com/problems/binary-tree-vertical-order-traversal/

#include <map>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  queue<pair<TreeNode *, int>> q; // pair of value, coordinate
  map<int, vector<int>> coordinates;

public:
  vector<vector<int>> verticalOrder(TreeNode *root) {
    q.push(make_pair(root, 0));

    while (!q.empty()) {
      TreeNode *node = q.front().first;
      int coordinate = q.front().second;
      q.pop();

      if (!node) {
        continue;
      }

      if (coordinates.find(coordinate) != coordinates.end()) {
        coordinates[coordinate].push_back(node->val);
      } else {
        coordinates.insert(make_pair(coordinate, vector<int>({node->val})));
      }

      q.push(make_pair(node->left, coordinate - 1));
      q.push(make_pair(node->right, coordinate + 1));
    }

    vector<vector<int>> answer;
    for (auto &pair : coordinates) {
      answer.push_back(pair.second);
    }

    return answer;
  }
};
