// 1110. Delete Nodes And Return Forest
// https://leetcode.com/problems/delete-nodes-and-return-forest/

using namespace std;

#include <vector>
#include <set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> answer;

        set<int> deleteVals;
        for(auto& val: to_delete) {
            deleteVals.insert(val);
        }

        if(deleteVals.find(root->val) != deleteVals.end()) {
            traverseForRoot(answer, deleteVals, root);
        } else {
            answer.push_back(root);
            traverse(answer, deleteVals, root);
        }

        return answer;
    }

    void traverse(vector<TreeNode*>& answer, set<int>& deleteVals, TreeNode* node) {
        // Don't need to verify current node is one of answer or not.

        if(node->left) {
            if(deleteVals.find(node->left->val) != deleteVals.end()) {
                traverseForRoot(answer, deleteVals, node->left);
                node->left = nullptr;
            } else {
                traverse(answer, deleteVals, node->left);
            }
        }

        if(node->right) {
            if(deleteVals.find(node->right->val) != deleteVals.end()) {
                traverseForRoot(answer, deleteVals, node->right);
                node->right = nullptr;
            } else {
                traverse(answer, deleteVals, node->right);
            }
        }
    }

    void traverseForRoot(vector<TreeNode*>& answer, set<int>& deleteVals, TreeNode* node) {
        // Need to verify current node is one of answer or not.

        if(node->left) {
            if(deleteVals.find(node->left->val) != deleteVals.end()) {
                traverseForRoot(answer, deleteVals, node->left);
                node->left = nullptr;
            } else {
                answer.push_back(node->left);
                traverse(answer, deleteVals, node->left);
            }
        }

        if(node->right) {
            if(deleteVals.find(node->right->val) != deleteVals.end()) {
                traverseForRoot(answer, deleteVals, node->right);
                node->right = nullptr;
            } else {
                answer.push_back(node->right);
                traverse(answer, deleteVals, node->right);
            }
        }
    }
};
