#include <stack>
#include <string>
#include <utility>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> rs;
        if (NULL == root) return rs;
        stack<pair<TreeNode *, string>> nodeStack;
        string val = to_string(root->val);
        if (NULL == root->left && NULL == root->right) {
            rs.push_back(val);
            return rs;
        }
        if (root->right != NULL) nodeStack.push(make_pair(root->right, val));
        if (root->left  != NULL) nodeStack.push(make_pair(root->left,  val));
        while (!nodeStack.empty()) {
            pair<TreeNode *, string> cNode = nodeStack.top();
            nodeStack.pop();
            string path = cNode.second;
            path.append("->").append(to_string(cNode.first->val));
            if (NULL == cNode.first->left && NULL == cNode.first->right) {
            rs.push_back(path);
            }
            if (cNode.first->right != NULL) nodeStack.push(make_pair(cNode.first->right, path));
            if (cNode.first->left  != NULL) nodeStack.push(make_pair(cNode.first->left,  path));
        }
        return rs;
    }                                                                                                                           
};
