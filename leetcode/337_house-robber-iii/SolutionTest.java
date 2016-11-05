package com.ict.golaxy;

import com.ict.golaxy.Solution;
import com.ict.golaxy.TreeNode;
import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

    @Test
    public void test01() {
        /*
             3
            / \
           4   5
          / \   \
         1   3   1
        Maximum amount of money the thief can rob = 4 + 5 = 9.
        */
        TreeNode root = new TreeNode(3);
        TreeNode node1 = new TreeNode(4);
        TreeNode node2 = new TreeNode(5);
        TreeNode node3 = new TreeNode(1);
        TreeNode node4 = new TreeNode(3);
        TreeNode node5 = new TreeNode(1);
        root.left = node1; root.right = node2;
        node1.left = node3; node1.right = node4;
        node2.right = node5;

        Solution s = new Solution();
        Assert.assertEquals(9, s.rob(root));
    }

}
