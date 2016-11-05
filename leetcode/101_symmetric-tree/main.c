/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (NULL == root) return NULL;
    struct TreeNode *left  = invertTree(root->right);
    struct TreeNode *right = invertTree(root->left);
    root->left  = left;
    root->right = right;
    return root;
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (NULL == p) {
        if (q != NULL) {
            return false;
        } else {
            return true;
        }
    } else {
        if (NULL == q) return false;
    }
    if (p->val != q->val) return false;

    if (!isSameTree(p->left, q->left)) return false;
    if (!isSameTree(p->right, q->right)) return false;

    return true;
}

bool isSymmetric(struct TreeNode* root) {
    if (NULL == root) return true;
    invertTree(root->right);
    bool rs = isSameTree(root->left, root->right);
    invertTree(root->right);
    return rs;
}

