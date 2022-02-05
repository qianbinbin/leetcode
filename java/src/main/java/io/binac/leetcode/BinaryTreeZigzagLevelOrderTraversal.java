package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.*;

/**
 * <p>Given the <code>root</code> of a binary tree, return <em>the zigzag level order traversal of its nodes' values</em>. (i.e., from left to right, then right to left for the next level and alternate between).</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;">
 * <pre><strong>Input:</strong> root = [3,9,20,null,null,15,7]
 * <strong>Output:</strong> [[3],[20,9],[15,7]]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> root = [1]
 * <strong>Output:</strong> [[1]]
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> root = []
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
 * 	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
 * </ul>
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

    public static class Solution2 {
        public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
            List<List<Integer>> result = new ArrayList<>();
            if (root == null) return result;

            Queue<TreeNode> queue = new ArrayDeque<>();
            queue.offer(root);
            boolean order = true;
            while (!queue.isEmpty()) {
                LinkedList<Integer> level = new LinkedList<>();
                int size = queue.size();
                for (int i = 0; i < size; ++i) {
                    TreeNode n = Objects.requireNonNull(queue.poll());
                    if (order) level.addLast(n.val);
                    else level.addFirst(n.val);
                    if (n.left != null) queue.offer(n.left);
                    if (n.right != null) queue.offer(n.right);
                }
                result.add(level);
                order = !order;
            }
            return result;
        }
    }
}
