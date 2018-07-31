package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: 3
 *     Output:
 *     [
 *       [1,null,3,2],
 *       [3,2,null,1],
 *       [3,1,null,null,2],
 *       [2,1,3],
 *       [1,null,2,null,3]
 *     ]
 *     Explanation:
 *     The above output corresponds to the 5 unique BST's shown below:
 *
 *        1         3     3      2      1
 *         \       /     /      / \      \
 *          3     2     1      1   3      2
 *         /     /       \                 \
 *        2     1         2                 3
 * </blockquote></pre>
 */
public class UniqueBinarySearchTreesII {
    public static class Solution1 {
        private TreeNode cloneTree(TreeNode root) {
            if (root == null)
                return null;
            TreeNode result = new TreeNode(root.val);
            result.left = cloneTree(root.left);
            result.right = cloneTree(root.right);
            return result;
        }

        private List<TreeNode> generateTrees(int start, int end) {
            if (start == end)
                return Collections.singletonList(null);
            List<TreeNode> result = new ArrayList<>();
            for (int i = start; i < end; ++i) {
                List<TreeNode> lefts = generateTrees(start, i);
                List<TreeNode> rights = generateTrees(i + 1, end);
                for (TreeNode left : lefts) {
                    for (TreeNode right : rights) {
                        TreeNode root = new TreeNode(i);
                        root.left = cloneTree(left);
                        root.right = cloneTree(right);
                        result.add(root);
                    }
                }
            }
            return result;
        }

        public List<TreeNode> generateTrees(int n) {
            // if (n < 1) throw new IllegalArgumentException("n must be positive");
            if (n < 1) return Collections.emptyList();
            return generateTrees(1, n + 1);
        }
    }
}
