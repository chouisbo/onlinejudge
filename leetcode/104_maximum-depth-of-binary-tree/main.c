
#include <stdlib.h>
#include <stdio.h>

/**
 *  Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if (NULL == root) return 0;
    int lenLeft  = maxDepth(root->left);
    int lenRight = maxDepth(root->right);
    return 1+(lenLeft>lenRight?lenLeft:lenRight);
}


int main(int argc, const char *argv[]) {

    return 0;
}

