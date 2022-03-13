package io.binac.leetcode;

import java.util.*;

/**
 * <p>A linked list of length <code>n</code> is given such that each node contains an additional random pointer, which could point to any node in the list, or <code>null</code>.</p>
 *
 * <p>Construct a <a href="https://en.wikipedia.org/wiki/Object_copying#Deep_copy" target="_blank"><strong>deep copy</strong></a> of the list. The deep copy should consist of exactly <code>n</code> <strong>brand new</strong> nodes, where each new node has its value set to the value of its corresponding original node. Both the <code>next</code> and <code>random</code> pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. <strong>None of the pointers in the new list should point to nodes in the original list</strong>.</p>
 *
 * <p>For example, if there are two nodes <code>X</code> and <code>Y</code> in the original list, where <code>X.random --&gt; Y</code>, then for the corresponding two nodes <code>x</code> and <code>y</code> in the copied list, <code>x.random --&gt; y</code>.</p>
 *
 * <p>Return <em>the head of the copied linked list</em>.</p>
 *
 * <p>The linked list is represented in the input/output as a list of <code>n</code> nodes. Each node is represented as a pair of <code>[val, random_index]</code> where:</p>
 *
 * <ul>
 * 	<li><code>val</code>: an integer representing <code>Node.val</code></li>
 * 	<li><code>random_index</code>: the index of the node (range from <code>0</code> to <code>n-1</code>) that the <code>random</code> pointer points to, or <code>null</code> if it does not point to any node.</li>
 * </ul>
 *
 * <p>Your code will <strong>only</strong> be given the <code>head</code> of the original linked list.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/e1.png" style="width: 700px; height: 142px;">
 * <pre><strong>Input:</strong> head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * <strong>Output:</strong> [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/e2.png" style="width: 700px; height: 114px;">
 * <pre><strong>Input:</strong> head = [[1,1],[2,1]]
 * <strong>Output:</strong> [[1,1],[2,1]]
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/12/18/e3.png" style="width: 700px; height: 122px;"></strong></p>
 *
 * <pre><strong>Input:</strong> head = [[3,null],[3,0],[3,null]]
 * <strong>Output:</strong> [[3,null],[3,0],[3,null]]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>0 &lt;= n &lt;= 1000</code></li>
 * 	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
 * 	<li><code>Node.random</code> is <code>null</code> or is pointing to some node in the linked list.</li>
 * </ul>
 */
public class CopyListWithRandomPointer {
    public static class Node {
        int val;
        Node next;
        Node random;

        public Node(int val) {
            this.val = val;
            this.next = null;
            this.random = null;
        }
    }

    public static class Solution1 {
        private Node copyRandomList(Node head, Map<Node, Node> visited) {
            Node copy = visited.get(head);
            if (copy != null) return copy;

            copy = new Node(head.val);
            visited.put(head, copy);
            if (head.next != null) copy.next = copyRandomList(head.next, visited);
            if (head.random != null) copy.random = copyRandomList(head.random, visited);
            return copy;
        }

        public Node copyRandomList(Node head) {
            if (head == null) return null;

            return copyRandomList(head, new HashMap<>());
        }
    }

    public static class Solution2 {
        public Node copyRandomList(Node head) {
            if (head == null) return null;

            Queue<Node> queue = new ArrayDeque<>();
            queue.offer(head);

            Map<Node, Node> visited = new HashMap<>();
            visited.put(head, new Node(head.val));

            while (!queue.isEmpty()) {
                Node node = Objects.requireNonNull(queue.poll()), copy = visited.get(node);
                if (node.next != null) {
                    copy.next = visited.computeIfAbsent(node.next, k -> {
                        queue.offer(node.next);
                        return new Node(k.val);
                    });
                }
                if (node.random != null) {
                    copy.random = visited.computeIfAbsent(node.random, k -> {
                        queue.offer(node.random);
                        return new Node(k.val);
                    });
                }
            }
            return visited.get(head);
        }
    }

    public static class Solution3 {
        public Node copyRandomList(Node head) {
            if (head == null) return null;

            Node node = head, copy;
            while (node != null) {
                copy = new Node(node.val);
                copy.next = node.next;
                node.next = copy;
                node = copy.next;
            }
            node = head;
            while (node != null) {
                copy = node.next;
                if (node.random != null)
                    copy.random = node.random.next;
                node = copy.next;
            }
            Node result = head.next;
            node = head;
            while (node != null) {
                copy = node.next;
                node.next = copy.next;
                node = node.next;
                copy.next = node == null ? null : node.next;
            }
            return result;
        }
    }
}
