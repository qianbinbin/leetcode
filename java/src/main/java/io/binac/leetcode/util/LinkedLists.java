package io.binac.leetcode.util;

public class LinkedLists {
    private LinkedLists() {
    }

    public static ListNode asLinkedList(int... a) {
        if (a == null || a.length == 0) return null;

        ListNode head = new ListNode(a[0]);
        ListNode tail = head;
        for (int i = 1; i < a.length; ++i) {
            tail.next = new ListNode(a[i]);
            tail = tail.next;
        }
        return head;
    }

    public static boolean equals(ListNode l1, ListNode l2) {
        if (l1 == l2)
            return true;
        if (l1 == null || l2 == null)
            return false;

        while (l1 != null && l2 != null) {
            if (l1.val != l2.val)
                return false;
            l1 = l1.next;
            l2 = l2.next;
        }
        return l1 == null && l2 == null;
    }

    public static int hashCode(ListNode list) {
        if (list == null)
            return 0;

        int result = 1;
        while (list != null) {
            result = result * 31 + list.val;
            list = list.next;
        }
        return result;
    }

    public static String toString(ListNode list) {
        if (list == null)
            return "null";

        StringBuilder sb = new StringBuilder(Integer.toString(list.val));
        list = list.next;
        while (list != null) {
            sb.append("->").append(list.val);
            list = list.next;
        }
        return sb.toString();
    }
}
