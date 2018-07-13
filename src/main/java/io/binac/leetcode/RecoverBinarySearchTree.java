package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * <p>
 * <p>Recover the tree without changing its structure.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input: [1,3,null,null,2]
 *
 *        1
 *       /
 *      3
 *       \
 *        2
 *
 *     Output: [3,1,null,null,2]
 *
 *        3
 *       /
 *      1
 *       \
 *        2
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input: [3,1,4,null,null,2]
 *
 *        3
 *       / \
 *      1   4
 *         /
 *        2
 *
 *     Output: [2,1,4,null,null,3]
 *
 *        2
 *       / \
 *      1   4
 *         /
 *        3
 * </blockquote></pre>
 * Follow up:
 * <p>
 * <p>A solution using O(n) space is pretty straight forward.
 * <p>Could you devise a constant space solution?
 */
public class RecoverBinarySearchTree {
    public static class Solution1 {
        private void inOrder(TreeNode root, List<TreeNode> result) {
            if (root == null) return;
            inOrder(root.left, result);
            result.add(root);
            inOrder(root.right, result);
        }

        public void recoverTree(TreeNode root) {
            List<TreeNode> nodes = new ArrayList<>();
            inOrder(root, nodes);
            int i = 0, j = nodes.size() - 1;
            while (i < nodes.size() - 1 && nodes.get(i).val < nodes.get(i + 1).val) ++i;
            while (j > 0 && nodes.get(j).val > nodes.get(j - 1).val) --j;
            if (i < nodes.size() - 1 && j > 0) {
                int tmp = nodes.get(i).val;
                nodes.get(i).val = nodes.get(j).val;
                nodes.get(j).val = tmp;
            }
        }
    }
}
