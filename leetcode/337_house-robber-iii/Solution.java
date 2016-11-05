/*
The thief has found himself a new place for his thievery again.
There is only one entrance to this area, called the "root."
Besides the root, each house has one and only one parent house.
After a tour, the smart thief realized that "all houses in this place
forms a binary tree".
It will automatically contact the police if two directly-linked houses
were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without
alerting the police.

Example 1:
     3
    / \
   2   3
    \   \
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.

思路: 树形dp

显然有：

rob_root = max(rob_L + rob_R , no_rob_L + no_nob_R + root.val)
no_rob_root = rob_L + rob_R
递归即可
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

package com.ict.golaxy;

public class Solution {
    public int rob(TreeNode root) {
        return dfs(root)[0];
    }

    private int[] dfs(TreeNode root) {
        int dp[] = {0, 0}; // [#rob_root, #no_rob_root]
        if (root != null) {
            int[] dp_L = dfs(root.left);
            int[] dp_R = dfs(root.right);
            // #no_rob_root = #rob_L + #rob_R
            dp[1] = dp_L[0] + dp_R[0];
            // #rob_root = max(#no_rob_root, #no_rob_L + #no_rob_R + root.val)
            dp[0] = Math.max(dp[1], dp_L[1] + dp_R[1] + root.val);
        }
        return dp;
    }
}
