package io.binac.leetcode;

import io.binac.leetcode.util.RandomListNode;

import java.util.*;

/**
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * <p>
 * <p>Return a deep copy of the list.
 */
public class CopyListWithRandomPointer {
    public static class Solution1 {
        private RandomListNode copyRandomList(RandomListNode head, Map<RandomListNode, RandomListNode> visited) {
            RandomListNode copy = visited.get(head);
            if (copy != null) return copy;

            copy = new RandomListNode(head.label);
            visited.put(head, copy);
            if (head.next != null) copy.next = copyRandomList(head.next, visited);
            if (head.random != null) copy.random = copyRandomList(head.random, visited);
            return copy;
        }

        public RandomListNode copyRandomList(RandomListNode head) {
            if (head == null) return null;

            Map<RandomListNode, RandomListNode> visited = new HashMap<>();
            return copyRandomList(head, visited);
        }
    }

    public static class Solution2 {
        public RandomListNode copyRandomList(RandomListNode head) {
            if (head == null) return null;

            Queue<RandomListNode> queue = new LinkedList<>();
            queue.offer(head);

            Map<RandomListNode, RandomListNode> visited = new HashMap<>();
            RandomListNode copy = new RandomListNode(head.label);
            visited.put(head, copy);

            RandomListNode node, copiedNode, n;
            while (!queue.isEmpty()) {
                node = Objects.requireNonNull(queue.poll());
                copiedNode = visited.get(node);
                if (node.next != null) {
                    n = visited.get(node.next);
                    if (n == null) {
                        n = new RandomListNode(node.next.label);
                        visited.put(node.next, n);
                        queue.offer(node.next);
                    }
                    copiedNode.next = n;
                }
                if (node.random != null) {
                    n = visited.get(node.random);
                    if (n == null) {
                        n = new RandomListNode(node.random.label);
                        visited.put(node.random, n);
                        queue.offer(node.random);
                    }
                    copiedNode.random = n;
                }
            }
            return copy;
        }
    }
}
