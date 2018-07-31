package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.*;

/**
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * <p>
 * <p>For example:
 * <p>Given binary tree [3,9,20,null,null,15,7],
 * <blockquote><pre>
 *         3
 *        / \
 *       9  20
 *         /  \
 *        15   7
 * </blockquote></pre>
 * return its bottom-up level order traversal as:
 * <blockquote><pre>
 *     [
 *       [15,7],
 *       [9,20],
 *       [3]
 *     ]
 * </blockquote></pre>
 */
public class BinaryTreeLevelOrderTraversalII {
    public static class Solution1 {
        private void preOrder(TreeNode root, int level, List<List<Integer>> result) {
            if (root == null) return;
            List<Integer> list;
            if (level == result.size())
                result.add(list = new ArrayList<>());
            else
                list = result.get(level);
            list.add(root.val);
            preOrder(root.left, level + 1, result);
            preOrder(root.right, level + 1, result);
        }

        public List<List<Integer>> levelOrderBottom(TreeNode root) {
            List<List<Integer>> result = new ArrayList<>();
            preOrder(root, 0, result);
            Collections.reverse(result);
            return result;
        }
    }

    public static class Solution2 {
        public List<List<Integer>> levelOrderBottom(TreeNode root) {
            if (root == null) return Collections.emptyList();

            LinkedList<List<Integer>> result = new LinkedList<>();
            Queue<TreeNode> queue = new LinkedList<>();
            queue.offer(root);
            while (!queue.isEmpty()) {
                List<Integer> level = new ArrayList<>();
                final int size = queue.size();
                for (int i = 0; i < size; ++i) {
                    TreeNode n = Objects.requireNonNull(queue.poll());
                    level.add(n.val);
                    if (n.left != null) queue.offer(n.left);
                    if (n.right != null) queue.offer(n.right);
                }
                result.addFirst(level);
            }
            return result;
        }
    }
}
