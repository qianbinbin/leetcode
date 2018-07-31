package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 * <p>
 * <p>Note: A leaf is a node with no children.
 * <p>
 * <p>Example:
 * <p>
 * <p>Given the below binary tree and sum = 22,
 * <blockquote><pre>
 *           5
 *          / \
 *         4   8
 *        /   / \
 *       11  13  4
 *      /  \    / \
 *     7    2  5   1
 * </blockquote></pre>
 * Return:
 * <blockquote><pre>
 *     [
 *        [5,4,11,2],
 *        [5,8,4,5]
 *     ]
 * </blockquote></pre>
 */
public class PathSumII {
    public static class Solution1 {
        private void pathSum(TreeNode root, int sum, List<List<Integer>> result, List<Integer> path) {
            path.add(root.val);
            if (root.left == null && root.right == null) {
                if (sum == root.val)
                    result.add(new ArrayList<>(path));
                path.remove(path.size() - 1);
                return;
            }
            if (root.left != null) pathSum(root.left, sum - root.val, result, path);
            if (root.right != null) pathSum(root.right, sum - root.val, result, path);
            path.remove(path.size() - 1);
        }

        public List<List<Integer>> pathSum(TreeNode root, int sum) {
            if (root == null) return Collections.emptyList();
            List<List<Integer>> result = new ArrayList<>();
            pathSum(root, sum, result, new ArrayList<>());
            return result;
        }
    }
}
