package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
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
 * return its level order traversal as:
 * <blockquote><pre>
 *     [
 *       [3],
 *       [9,20],
 *       [15,7]
 *     ]
 * </blockquote></pre>
 */
public class BinaryTreeLevelOrderTraversal {
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

        public List<List<Integer>> levelOrder(TreeNode root) {
            List<List<Integer>> result = new ArrayList<>();
            preOrder(root, 0, result);
            return result;
        }
    }
}
