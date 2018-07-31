package io.binac.leetcode.util;

import java.util.LinkedList;
import java.util.Queue;

public class Trees {
    private Trees() {
    }

    public static TreeNode asTree(Integer... a) {
        if (a == null || a.length == 0 || a[0] == null)
            return null;

        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode root = new TreeNode(a[0]);
        queue.offer(root);
        TreeNode node;
        for (int i = 1; i < a.length && !queue.isEmpty(); i += 2) {
            node = queue.poll();
            assert node != null;
            node.left = a[i] == null ? null : new TreeNode(a[i]);
            node.right = i + 1 >= a.length || a[i + 1] == null ? null : new TreeNode(a[i + 1]);
            if (node.left != null)
                queue.offer(node.left);
            if (node.right != null)
                queue.offer(node.right);
        }
        return root;
    }

    public static boolean equals(TreeNode root1, TreeNode root2) {
        if (root1 == root2) return true;
        if (root1 == null || root2 == null) return false;
        if (root1.val != root2.val) return false;
        return equals(root1.left, root2.left) && equals(root1.right, root2.right);
    }

    private static void toStringPreOrder(TreeNode root, StringBuilder sb) {
        if (root == null) return;
        sb.append(root.val).append(", ");
        toStringPreOrder(root.left, sb);
        toStringPreOrder(root.right, sb);
    }

    public static String toStringPreOrder(TreeNode root) {
        if (root == null)
            return "null";

        StringBuilder sb = new StringBuilder();
        sb.append('[');
        toStringPreOrder(root, sb);
        sb.delete(sb.length() - 2, sb.length());
        sb.append(']');
        return sb.toString();
    }

    private static void toStringInOrder(TreeNode root, StringBuilder sb) {
        if (root == null) return;
        toStringInOrder(root.left, sb);
        sb.append(root.val).append(", ");
        toStringInOrder(root.right, sb);
    }

    public static String toStringInOrder(TreeNode root) {
        if (root == null)
            return "null";

        StringBuilder sb = new StringBuilder();
        sb.append('[');
        toStringInOrder(root, sb);
        sb.delete(sb.length() - 2, sb.length());
        sb.append(']');
        return sb.toString();
    }

    private static void toStringPostOrder(TreeNode root, StringBuilder sb) {
        if (root == null) return;
        toStringPostOrder(root.left, sb);
        toStringPostOrder(root.right, sb);
        sb.append(root.val).append(", ");
    }

    public static String toStringPostOrder(TreeNode root) {
        if (root == null)
            return "null";

        StringBuilder sb = new StringBuilder();
        sb.append('[');
        toStringPostOrder(root, sb);
        sb.delete(sb.length() - 2, sb.length());
        sb.append(']');
        return sb.toString();
    }
}
