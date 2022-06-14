package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;

import java.util.Scanner;

/**
 * <p>Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.</p>
 *
 * <p>Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.</p>
 *
 * <p><strong>Clarification:</strong> The input/output format is the same as <a href="/faq/#binary-tree" target="_blank">how LeetCode serializes a binary tree</a>. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/serdeser.jpg" style="width: 442px; height: 324px;">
 * <pre><strong>Input:</strong> root = [1,2,3,null,null,4,5]
 * <strong>Output:</strong> [1,2,3,null,null,4,5]
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
 * 	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
 * 	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
 * </ul>
 */
public class SerializeAndDeserializeBinaryTree {
    public static class Codec {
        private static final int NULL_VALUE = Integer.MIN_VALUE;

        private void serialize(TreeNode root, StringBuilder sb) {
            if (root == null) {
                sb.append(' ').append(NULL_VALUE);
                return;
            }
            sb.append(' ').append(root.val);
            serialize(root.left, sb);
            serialize(root.right, sb);
        }

        // Encodes a tree to a single string.
        public String serialize(TreeNode root) {
            StringBuilder sb = new StringBuilder();
            serialize(root, sb);
            return sb.toString();
        }

        private TreeNode deserialize(Scanner scanner) {
            int val = scanner.nextInt();
            if (val == NULL_VALUE)
                return null;
            return new TreeNode(val, deserialize(scanner), deserialize(scanner));
        }

        // Decodes your encoded data to tree.
        public TreeNode deserialize(String data) {
            return deserialize(new Scanner(data));
        }
    }
}
