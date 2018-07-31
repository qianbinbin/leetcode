package io.binac.leetcode;

import io.binac.leetcode.util.ListNode;

/**
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * <p>
 * <p>Note: Do not modify the linked list.
 * <p>
 * <p>Follow up:
 * <p>Can you solve it without using extra space?
 */
public class LinkedListCycleII {
    public static class Solution {
        public ListNode detectCycle(ListNode head) {
            ListNode slow = head, fast = head;
            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
                if (slow == fast) {
                    ListNode slow1 = head;
                    while (slow != slow1) {
                        slow = slow.next;
                        slow1 = slow1.next;
                    }
                    return slow;
                }
            }
            return null;
        }
    }
}
