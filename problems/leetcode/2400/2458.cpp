// 2458. Height of Binary Tree After Subtree Removal Queries
// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/

#include <map>
#include <queue>
#include <vector>

using namespace std;

typedef pair<TreeNode *, int> pti;

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
public:
  vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
    map<int, int> valueToHeight;
    getMaxHeight(root, 0, valueToHeight);

    auto compare = [&](pti &pti1, pti &pti2) {
      return valueToHeight[pti1.first->val] < valueToHeight[pti2.first->val];
    };
    priority_queue<pti, vector<pti>, decltype(compare)> pq(compare);
    pq.push({root, 0});

    map<int, int> valueToQueryResult;
    while (!pq.empty()) {
      vector<pti> v;

      while (!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
      }

      if (v.size() == 1) {
        TreeNode *node = v[0].first;
        int depth = v[0].second;
        valueToQueryResult[node->val] = depth - 1;
      } else {
        valueToQueryResult[v[0].first->val] = valueToHeight[v[1].first->val];

        int maxHeight = valueToHeight[v[0].first->val];
        for (int i = 1; i < v.size(); i++) {
          valueToQueryResult[v[i].first->val] = maxHeight;
        }
      }

      for (pti p : v) {
        TreeNode *node = p.first;
        int depth = p.second;
        if (node->left) {
          pq.push({node->left, depth + 1});
        }
        if (node->right) {
          pq.push({node->right, depth + 1});
        }
      }
    }

    vector<int> result;
    for (int &query : queries) {
      result.push_back(valueToQueryResult[query]);
    }
    return result;
  }

  int getMaxHeight(TreeNode *node, int height, map<int, int> &valueToHeight) {
    int maxHeight = height;
    if (node->left) {
      maxHeight =
          max(maxHeight, getMaxHeight(node->left, height + 1, valueToHeight));
    }
    if (node->right) {
      maxHeight =
          max(maxHeight, getMaxHeight(node->right, height + 1, valueToHeight));
    }

    valueToHeight[node->val] = maxHeight;
    return maxHeight;
  }
};
