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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> rs;
        if (NULL == root) return rs;
        
        stack<TreeNode *> nst;
        set<TreeNode *> visited;
        set<TreeNode *> expanded;
        
        nst.push(root);
        
        while(! nst.empty()) {
            TreeNode *node = nst.top();
            visited.insert(node);
            if (expanded.find(node) != expanded.end()) {
                rs.push_back(node->val);
                nst.pop();
            } else {
                expanded.insert(node);
                if (node->right != NULL && visited.find(node->right) == visited.end()) {
                    nst.push(node->right);
                }
                if (node->left != NULL && visited.find(node->left) == visited.end()) {
                    nst.push(node->left);
                }
            }
        }
        
        return rs;
    }
};
