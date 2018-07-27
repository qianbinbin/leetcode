package io.binac.leetcode;

import io.binac.leetcode.util.RandomListNode;

import java.util.HashMap;
import java.util.Map;

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
}
