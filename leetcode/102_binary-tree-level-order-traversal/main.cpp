#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vRs;
        if (NULL == root) return vRs;
        
        vector<int> v;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        v.push_back(root->val);
        vRs.push_back(v);
        int len = v.size();
        v.clear();
        
        while (!nodeQueue.empty()) {
            TreeNode *topNode = nodeQueue.front();
            nodeQueue.pop();
            if (topNode->left != NULL) {
                nodeQueue.push(topNode->left);
                v.push_back(topNode->left->val);
            }
            if (topNode->right != NULL) {
                nodeQueue.push(topNode->right);
                v.push_back(topNode->right->val);
            }
            if (--len == 0) {
                if (v.empty()) break;
                vRs.push_back(v);
                len = v.size();
                v.clear();
            }
        }
        return vRs;
    }
};
