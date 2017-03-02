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
    vector<int> findMode(TreeNode* root) {
        result.clear();
        if (NULL == root) return result;
        maxCount = 0; currentCount = 0; currentValue = root->val;
        inorder(root);
        return result;
    }

private:
    void inorder(TreeNode* root) {
        if (NULL == root) return;
        inorder(root->left);
        if (root->val != currentValue) {
            currentValue = root->val;
            currentCount = 1;
        } else {
            currentCount++;
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            result.clear();
            result.push_back(currentValue);
        } else if (currentCount == maxCount) {
            result.push_back(currentValue);
        }
        inorder(root->right);
    }

private:
    vector<int> result;
    int maxCount, currentCount, currentValue;

};
