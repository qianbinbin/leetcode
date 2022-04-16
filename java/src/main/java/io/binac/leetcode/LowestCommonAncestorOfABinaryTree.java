package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.*;

/**
 * <p>Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.</p>
 *
 * <p>According to the <a href="https://en.wikipedia.org/wiki/Lowest_common_ancestor" target="_blank">definition of LCA on Wikipedia</a>: “The lowest common ancestor is defined between two nodes <code>p</code> and <code>q</code> as the lowest node in <code>T</code> that has both <code>p</code> and <code>q</code> as descendants (where we allow <b>a node to be a descendant of itself</b>).”</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png" style="width: 200px; height: 190px;">
 * <pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * <strong>Output:</strong> 3
 * <strong>Explanation:</strong> The LCA of nodes 5 and 1 is 3.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2018/12/14/binarytree.png" style="width: 200px; height: 190px;">
 * <pre><strong>Input:</strong> root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * <strong>Output:</strong> 5
 * <strong>Explanation:</strong> The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> root = [1,2], p = 1, q = 2
 * <strong>Output:</strong> 1
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the tree is in the range <code>[2, 10<sup>5</sup>]</code>.</li>
 * 	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
 * 	<li>All <code>Node.val</code> are <strong>unique</strong>.</li>
 * 	<li><code>p != q</code></li>
 * 	<li><code>p</code> and <code>q</code> will exist in the tree.</li>
 * </ul>
 */
public class LowestCommonAncestorOfABinaryTree {
    public static class Solution1 {
        private boolean lowestCommonAncestor(TreeNode root, TreeNode node, List<TreeNode> path) {
            if (root == null)
                return false;
            path.add(root);
            if (root == node)
                return true;
            if (lowestCommonAncestor(root.left, node, path) || lowestCommonAncestor(root.right, node, path))
                return true;
            path.remove(path.size() - 1);
            return false;
        }

        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            List<TreeNode> path1 = new ArrayList<>(), path2 = new ArrayList<>();
            lowestCommonAncestor(root, p, path1);
            lowestCommonAncestor(root, q, path2);
            int i = 0, e = Math.min(path1.size(), path2.size());
            while (i < e && path1.get(i) == path2.get(i)) ++i;
            return path1.get(i - 1);
        }
    }

    public static class Solution2 {
        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            if (root == null || root == p || root == q)
                return root;
            TreeNode left = lowestCommonAncestor(root.left, p, q), right = lowestCommonAncestor(root.right, p, q);
            if (left != null && right != null)
                return root;
            return left != null ? left : right;
        }
    }

    public static class Solution3 {
        private void findParents(TreeNode root, Map<TreeNode, TreeNode> parents) {
            if (root.left != null) {
                parents.put(root.left, root);
                findParents(root.left, parents);
            }
            if (root.right != null) {
                parents.put(root.right, root);
                findParents(root.right, parents);
            }
        }

        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            Map<TreeNode, TreeNode> parents = new HashMap<>();
            findParents(root, parents);
            Set<TreeNode> ancestors = new HashSet<>();
            for (; p != null; p = parents.get(p))
                ancestors.add(p);
            while (!ancestors.contains(q))
                q = parents.get(q);
            return q;
        }
    }

    public static class Solution4 {
        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            Deque<TreeNode> stack = new ArrayDeque<>();
            TreeNode node = root, ancestor = null;
            int ancestorDepth = -1;
            while (node != null || !stack.isEmpty()) {
                if (node != null) {
                    stack.push(node);
                    if (node == p || node == q) {
                        if (ancestor != null)
                            return ancestor;
                        ancestor = node;
                        ancestorDepth = stack.size();
                    }
                    node = node.left;
                } else {
                    node = stack.pop();
                    if (ancestorDepth > stack.size()) {
                        ancestorDepth = stack.size();
                        ancestor = node;
                    }
                    node = node.right;
                }
            }
            return ancestor;
        }
    }
}
