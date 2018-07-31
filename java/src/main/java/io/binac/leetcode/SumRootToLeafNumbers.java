package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

/**
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 * <p>
 * <p>An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * <p>
 * <p>Find the total sum of all root-to-leaf numbers.
 * <p>
 * <p>Note: A leaf is a node with no children.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: [1,2,3]
 *         1
 *        / \
 *       2   3
 *     Output: 25
 *     Explanation:
 *     The root-to-leaf path 1->2 represents the number 12.
 *     The root-to-leaf path 1->3 represents the number 13.
 *     Therefore, sum = 12 + 13 = 25.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [4,9,0,5,1]
 *         4
 *        / \
 *       9   0
 *      / \
 *     5   1
 *     Output: 1026
 *     Explanation:
 *     The root-to-leaf path 4->9->5 represents the number 495.
 *     The root-to-leaf path 4->9->1 represents the number 491.
 *     The root-to-leaf path 4->0 represents the number 40.
 *     Therefore, sum = 495 + 491 + 40 = 1026.
 * </blockquote></pre>
 */
public class SumRootToLeafNumbers {
    public static class Solution1 {
        private void sumNumbers(TreeNode root, int[] result, int path) {
            path = path * 10 + root.val;
            if (root.left == null && root.right == null) {
                result[0] += path;
                return;
            }
            if (root.left != null) sumNumbers(root.left, result, path);
            if (root.right != null) sumNumbers(root.right, result, path);
        }

        public int sumNumbers(TreeNode root) {
            if (root == null) return 0;

            int result[] = new int[1];
            sumNumbers(root, result, 0);
            return result[0];
        }
    }
}
