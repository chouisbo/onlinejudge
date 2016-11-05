/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxBinaryTreeDepth(struct TreeNode* root) {
    if (NULL == root) return 0;
    int lenLeft  = maxBinaryTreeDepth(root->left);
    int lenRight = maxBinaryTreeDepth(root->right);
    return 1+(lenLeft > lenRight ? lenLeft : lenRight);
}

bool isBalanced(struct TreeNode* root) {
    if (NULL == root) return true;
    int lenLeft  = maxBinaryTreeDepth(root->left);
    int lenRight = maxBinaryTreeDepth(root->right);
    if ((lenLeft-lenRight) > 1 || (lenRight-lenLeft) > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}
