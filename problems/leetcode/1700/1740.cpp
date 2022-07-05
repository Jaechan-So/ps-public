// 1740. Find Distance in a Binary Tree
// https://leetcode.com/problems/find-distance-in-a-binary-tree/

using namespace std;

#include <map>
#include <queue>

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
    int findDistance(TreeNode* root, int p, int q) {
        map<int, pair<int, int>> childrens; // children node's val -> (parent node's val, height)
        childrens.insert(make_pair(root->val, make_pair(0, 1))); // Just set parent of root as zero

        queue<pair<TreeNode*, int>> nodes;
        nodes.push(make_pair(root, 1));

        while(!nodes.empty()) {
            TreeNode* currentNode = nodes.front().first;
            int currentHeight = nodes.front().second;
            nodes.pop();

            if(currentNode->left != nullptr) {
                childrens.insert(make_pair(currentNode->left->val, make_pair(currentNode->val, currentHeight + 1)));
                nodes.push(make_pair(currentNode->left, currentHeight + 1));
            }
            if(currentNode->right != nullptr) {
                childrens.insert(make_pair(currentNode->right->val, make_pair(currentNode->val, currentHeight + 1)));
                nodes.push(make_pair(currentNode->right, currentHeight + 1));
            }
        }

        int startP = p, startQ = q;
        int heightOfP = childrens[p].second, heightOfQ = childrens[q].second;

        int distance = 0;

        if(heightOfP > heightOfQ) {
            while(heightOfP != heightOfQ) {
                startP = childrens[startP].first;
                heightOfP--;
                distance++;
            }
        } else if(heightOfP < heightOfQ) {
            while(heightOfP != heightOfQ) {
                startQ = childrens[startQ].first;
                heightOfQ--;
                distance++;
            }
        }

        while(startP != startQ) {
            startP = childrens[startP].first;
            startQ = childrens[startQ].first;
            distance += 2;
        }

        return distance;
    }
};
