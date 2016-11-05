/*
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
 * How would you optimize the kthSmallest routine?
 *
 * Hint:
 *
 * Try to utilize the property of a BST.
 * What if you could modify the BST node's structure?
 * The optimal runtime complexity is O(height of BST).
 *
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * [solution](http://bookshadow.com/weblog/2015/07/02/leetcode-kth-smallest-element-bst/)
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct OptTreeNode {
    int val;
    int leftCount;
    OptTreeNode *left;
    OptTreeNode *right;
    OptTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallestOpt(OptTreeNode* root, int k) {
        return 0;
    }

    int kthSmallest(TreeNode* root, int k) {
        int rs;
        midTranverseBST(root, k, rs);
        return rs;
    }

    void midTranverseBST(TreeNode *node, int &k, int &v) {
        if (NULL == node) return;
        midTranverseBST(node->left, k, v);
        if (0 == --k) { v = node->val; return; }
        midTranverseBST(node->right, k, v);
    }

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
    for (int i = 1; i <= 9; i++) {
        cout << s.kthSmallest(node, i) << endl;
    }
    s.destroyBSTTree(node);
    return 0;
}

