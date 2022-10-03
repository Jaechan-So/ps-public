// 108. Convert Sorted Array to Binary Search Tree
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

using namespace std;

#include <vector>

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
  void generate(TreeNode *root, vector<int> &nums, int left, int right,
                bool isLeft) {
    if (left > right) {
      return;
    }
    int mid = (left + right + 1) / 2;
    TreeNode *curr = new TreeNode(nums[mid]);

    if (isLeft) {
      root->left = curr;
    } else {
      root->right = curr;
    }

    generate(curr, nums, left, mid - 1, true);
    generate(curr, nums, mid + 1, right, false);
  }
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    int n = nums.size();

    TreeNode *root = new TreeNode(nums[n / 2]);
    generate(root, nums, 0, (n / 2) - 1, true);
    generate(root, nums, (n / 2) + 1, n - 1, false);

    return root;
  }
};
