package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

/**
 * <p>Given the <code>root</code> of a binary tree, imagine yourself standing on the <strong>right side</strong> of it, return <em>the values of the nodes you can see ordered from top to bottom</em>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/02/14/tree.jpg" style="width: 401px; height: 301px;">
 * <pre><strong>Input:</strong> root = [1,2,3,null,5,null,4]
 * <strong>Output:</strong> [1,3,4]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> root = [1,null,3]
 * <strong>Output:</strong> [1,3]
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
 * 	<li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li>
 * 	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
 * </ul>
 */
public class BinaryTreeRightSideView {
    public static class Solution1 {
        public List<Integer> rightSideView(TreeNode root) {
            List<Integer> result = new ArrayList<>();
            if (root == null)
                return result;
            Deque<TreeNode> deque = new ArrayDeque<>();
            deque.offerLast(root);
            while (!deque.isEmpty()) {
                result.add(deque.getLast().val);
                for (int i = deque.size(); i > 0; --i) {
                    TreeNode node = deque.removeFirst();
                    if (node.left != null) deque.offerLast(node.left);
                    if (node.right != null) deque.offerLast(node.right);
                }
            }
            return result;
        }
    }

    public static class Solution2 {
        private void rightSideView(TreeNode root, int level, List<Integer> result) {
            if (root == null)
                return;
            if (level == result.size())
                result.add(root.val);
            rightSideView(root.right, level + 1, result);
            rightSideView(root.left, level + 1, result);
        }

        public List<Integer> rightSideView(TreeNode root) {
            List<Integer> result = new ArrayList<>();
            rightSideView(root, 0, result);
            return result;
        }
    }
}
