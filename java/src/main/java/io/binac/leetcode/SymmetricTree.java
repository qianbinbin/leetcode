package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.LinkedList;
import java.util.Queue;

/**
 * <p>Given the <code>root</code> of a binary tree, <em>check whether it is a mirror of itself</em> (i.e., symmetric around its center).</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg" style="width: 354px; height: 291px;">
 * <pre><strong>Input:</strong> root = [1,2,2,3,4,4,3]
 * <strong>Output:</strong> true
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg" style="width: 308px; height: 258px;">
 * <pre><strong>Input:</strong> root = [1,2,2,null,3,null,3]
 * <strong>Output:</strong> false
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the tree is in the range <code>[1, 1000]</code>.</li>
 * 	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <strong>Follow up:</strong> Could you solve it both recursively and iteratively?
 */
public class SymmetricTree {
    public static class Solution1 {
        private boolean isSymmetric(TreeNode root1, TreeNode root2) {
            if (root1 == null && root2 == null) return true;
            if (root1 == null || root2 == null) return false;
            if (root1.val != root2.val) return false;
            return isSymmetric(root1.left, root2.right) && isSymmetric(root1.right, root2.left);
        }

        public boolean isSymmetric(TreeNode root) {
            return isSymmetric(root.left, root.right);
        }
    }

    public static class Solution2 {
        public boolean isSymmetric(TreeNode root) {
            Queue<TreeNode> queue = new LinkedList<>();
            queue.offer(root.left);
            queue.offer(root.right);
            while (!queue.isEmpty()) {
                TreeNode n1 = queue.poll(), n2 = queue.poll();
                if (n1 == null && n2 == null) continue;
                if (n1 == null || n2 == null) return false;
                if (n1.val != n2.val) return false;
                queue.offer(n1.left);
                queue.offer(n2.right);
                queue.offer(n1.right);
                queue.offer(n2.left);
            }
            return true;
        }
    }
}
