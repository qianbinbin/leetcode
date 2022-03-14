package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReorderListTest {
    private static final ReorderList.Solution1 SOLUTION1 = new ReorderList.Solution1();

    private ListNode getHEAD1() {
        return LinkedLists.asLinkedList(1, 2, 3, 4);
    }

    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(1, 4, 2, 3);

    private ListNode getHEAD2() {
        return LinkedLists.asLinkedList(1, 2, 3, 4, 5);
    }

    private final ListNode EXPECTED2 = LinkedLists.asLinkedList(1, 5, 2, 4, 3);

    @Test
    void test1() {
        ListNode head1 = getHEAD1();
        SOLUTION1.reorderList(head1);
        assertTrue(LinkedLists.equals(EXPECTED1, head1));

        ListNode head2 = getHEAD2();
        SOLUTION1.reorderList(head2);
        assertTrue(LinkedLists.equals(EXPECTED2, head2));
    }
}