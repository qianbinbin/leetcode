package io.binac.leetcode.util;

public class LinkedLists {
    private LinkedLists() {
    }

    public static ListNode asLinkedList(int... a) {
        ListNode dummy = new ListNode(), tail = dummy;
        for (int v : a) {
            tail.next = new ListNode(v);
            tail = tail.next;
        }
        return dummy.next;
    }

    public static boolean equals(ListNode l1, ListNode l2) {
        if (l1 == l2)
            return true;
        while (l1 != null && l2 != null && l1.val == l2.val) {
            l1 = l1.next;
            l2 = l2.next;
        }
        return l1 == null && l2 == null;
    }
}
