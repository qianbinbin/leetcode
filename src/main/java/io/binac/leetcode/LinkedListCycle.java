package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Given a linked list, determine if it has a cycle in it.
 * <p>
 * <p>Follow up:
 * <p>Can you solve it without using extra space?
 */
public class LinkedListCycle {
    public static class Solution1 {
        public boolean hasCycle(ListNode head) {
            ListNode slow = head, fast = head;
            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
                if (slow == fast)
                    return true;
            }
            return false;
        }
    }
}
