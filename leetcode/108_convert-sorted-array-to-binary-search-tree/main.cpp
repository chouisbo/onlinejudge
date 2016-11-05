/*
 *
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 */

#include <iostream>
#include <vector>

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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        return _sortedArrayToBST(nums, 0, nums.size());
    }

    TreeNode* _sortedArrayToBST(vector<int>& nums, size_t start, size_t end) {
        if (end <= start) return NULL;
        size_t pos = start+(end-start)/2;
        TreeNode *node = new TreeNode(nums[pos]); 
        node->left = _sortedArrayToBST(nums, start, pos);
        node->right = _sortedArrayToBST(nums, pos+1, end);
        return node;
    }

    void printBSTTree(TreeNode *root) {
        if (NULL == root) return;
        printBSTTree(root->left);
        cout << root->val << ", ";
        printBSTTree(root->right);
    }

    void destroyBSTTree(TreeNode *root) {
        if (NULL == root) return;
        destroyBSTTree(root->left);
        destroyBSTTree(root->right);
        delete root;
    }
};

int main(void) {
    Solution s;
    vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &x : array) { cout << x << ", "; } cout << endl;
    TreeNode *node = s.sortedArrayToBST(array);
    s.printBSTTree(node); cout << endl;
    s.destroyBSTTree(node);
    return 0;
}

