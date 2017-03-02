#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        TreeNode *prev = NULL;
        midorder(root, prev, diff);
        return diff;
    }
private:
    void midorder(TreeNode* root, TreeNode * &prev, int &diff) {
        if (NULL == root) return;
        midorder(root->left, prev, diff);
        if (prev != NULL) {
            diff = min(diff, root->val - prev->val);
        }
        prev = root;
        midorder(root->right, prev, diff);
    }
};

int main(void) {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(7);
    Solution s;
    cout << s.getMinimumDifference(root) << endl;
    return 0;
}




