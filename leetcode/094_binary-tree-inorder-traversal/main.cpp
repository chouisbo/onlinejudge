#include <stack>
#include <vector>
#include <set>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rsVec;
        if (NULL == root) return rsVec;
        stack<TreeNode*> nodeStack;
        set<TreeNode*> visitedNode;

        nodeStack.push(root);
        while (!nodeStack.empty()) {
            TreeNode *curNode = nodeStack.top();
            nodeStack.pop();
            if (visitedNode.find(curNode) != visitedNode.end()) {
                rsVec.push_back(curNode->val);
            } else {
                if (curNode->right != NULL) {
                    nodeStack.push(curNode->right);
                }
                nodeStack.push(curNode);
                visitedNode.insert(curNode);
                if (curNode->left != NULL) {
                    nodeStack.push(curNode->left);
                }
            }
        }
        
        return rsVec;
    }
};
