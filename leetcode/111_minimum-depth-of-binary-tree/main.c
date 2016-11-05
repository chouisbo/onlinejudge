/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if (NULL == root) return 0;
    if (NULL == root->left) {
        if (NULL == root->right) return 1;
        else return 1+minDepth(root->right);
    } else {
        if (NULL == root->right) return 1+minDepth(root->left);
        else {
            int leftMinDepth  = minDepth(root->left);
            int rightMinDepth = minDepth(root->right);

            int depth = leftMinDepth < rightMinDepth ? leftMinDepth : rightMinDepth;
            return depth +1;
        }
    }
}
