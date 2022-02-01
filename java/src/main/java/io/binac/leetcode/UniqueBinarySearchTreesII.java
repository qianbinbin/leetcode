package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * <p>Given an integer <code>n</code>, return <em>all the structurally unique <strong>BST'</strong>s (binary search trees), which has exactly </em><code>n</code><em> nodes of unique values from</em> <code>1</code> <em>to</em> <code>n</code>. Return the answer in <strong>any order</strong>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/uniquebstn3.jpg" style="width: 600px; height: 148px;">
 * <pre><strong>Input:</strong> n = 3
 * <strong>Output:</strong> [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> n = 1
 * <strong>Output:</strong> [[1]]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= n &lt;= 8</code></li>
 * </ul>
 */
public class UniqueBinarySearchTreesII {
    public static class Solution1 {
        private TreeNode cloneTree(TreeNode root) {
            if (root == null)
                return null;
            return new TreeNode(root.val, cloneTree(root.left), cloneTree(root.right));
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
                        result.add(new TreeNode(i, cloneTree(left), cloneTree(right)));
                    }
                }
            }
            return result;
        }

        public List<TreeNode> generateTrees(int n) {
            return generateTrees(1, n + 1);
        }
    }
}
