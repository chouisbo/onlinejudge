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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rs;
        if (NULL == root) return rs;
        stack<TreeNode *> nst;
        nst.push(root);
        set<TreeNode *> visited; while (! nst.empty()) { TreeNode *node = nst.top();
            nst.pop();
            rs.push_back(node->val);
            visited.insert(node);
            if (node->right != NULL && visited.find(node->right) == visited.end()) {
                nst.push(node->right);
            }
            if (node->left != NULL && visited.find(node->left) == visited.end()) {
                nst.push(node->left);
            }
        }
        return rs;
    }
};
