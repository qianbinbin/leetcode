package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
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
 * return its zigzag level order traversal as:
 * <blockquote><pre>
 *     [
 *       [3],
 *       [20,9],
 *       [15,7]
 *     ]
 * </blockquote></pre>
 */
public class BinaryTreeZigzagLevelOrderTraversal {
    public static class Solution1 {
        private void preOrder(TreeNode root, int level, List<List<Integer>> result) {
            if (root == null) return;
            LinkedList<Integer> list;
            if (level == result.size())
                result.add(list = new LinkedList<>());
            else
                list = (LinkedList<Integer>) result.get(level);
            if (level % 2 == 0)
                list.addLast(root.val);
            else
                list.addFirst(root.val);
            preOrder(root.left, level + 1, result);
            preOrder(root.right, level + 1, result);
        }

        public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
            List<List<Integer>> result = new ArrayList<>();
            preOrder(root, 0, result);
            return result;
        }
    }
}
