package io.binac.leetcode;

/**
 * <p>You are given a <strong>perfect binary tree</strong> where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:</p>
 *
 * <pre>struct Node {
 *   int val;
 *   Node *left;
 *   Node *right;
 *   Node *next;
 * }
 * </pre>
 *
 * <p>Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to <code>NULL</code>.</p>
 *
 * <p>Initially, all next pointers are set to <code>NULL</code>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2019/02/14/116_sample.png" style="width: 500px; height: 171px;">
 * <pre><strong>Input:</strong> root = [1,2,3,4,5,6,7]
 * <strong>Output:</strong> [1,#,2,3,#,4,5,6,7,#]
 * <strong>Explanation: </strong>Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> root = []
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li>The number of nodes in the tree is in the range <code>[0, 2<sup>12</sup> - 1]</code>.</li>
 * 	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Follow-up:</strong></p>
 *
 * <ul>
 * 	<li>You may only use constant extra space.</li>
 * 	<li>The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.</li>
 * </ul>
 */
public class PopulatingNextRightPointersInEachNode {
    public static class Node {
        public int val;
        public Node left;
        public Node right;
        public Node next;

        public Node() {
        }

        public Node(int _val) {
            val = _val;
        }

        public Node(int _val, Node _left, Node _right, Node _next) {
            val = _val;
            left = _left;
            right = _right;
            next = _next;
        }
    }

    public static class Solution1 {
        public Node connect(Node root) {
            if (root == null) return null;
            Node dummy = new Node(), tail;
            Node node = root;
            while (node.left != null) {
                tail = dummy;
                while (node != null) {
                    tail = tail.next = node.left;
                    tail = tail.next = node.right;
                    node = node.next;
                }
                node = dummy.next;
            }
            return root;
        }
    }

    public static class Solution2 {
        public Node connect(Node root) {
            if (root == null || root.left == null)
                return root;
            root.left.next = root.right;
            if (root.next != null)
                root.right.next = root.next.left;
            connect(root.left);
            connect(root.right);
            return root;
        }
    }
}
