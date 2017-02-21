#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (NULL == root) return 0;
        vector<int> psum;
        return _pathSum(root, sum, psum);
    }

private:
    int _pathSum(TreeNode* root, int sum, vector<int> &psum) {
        if (NULL == root) return 0;
        psum.push_back(0);
        for (auto & x : psum) x += root->val;
        int rs = count(psum.begin(), psum.end(), sum);
        if (root->left != NULL) {
            rs += _pathSum(root->left, sum, psum);
        }
        if (root->right != NULL) {
            rs += _pathSum(root->right, sum, psum);
        }
        for (auto & x : psum) x -= root->val;
        psum.pop_back();
        return rs;
    }
};

