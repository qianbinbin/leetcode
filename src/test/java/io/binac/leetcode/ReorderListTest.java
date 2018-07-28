package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReorderListTest {
    private final ReorderList.Solution1 solution1 = new ReorderList.Solution1();

    private final int list1[] = {1, 2, 3, 4};
    private final ListNode expected1 = LinkedLists.asLinkedList(1, 4, 2, 3);

    private final int list2[] = {1, 2, 3, 4, 5};
    private final ListNode expected2 = LinkedLists.asLinkedList(1, 5, 2, 4, 3);

    @Test
    void test1() {
        ListNode head1 = LinkedLists.asLinkedList(list1);
        solution1.reorderList(head1);
        assertTrue(LinkedLists.equals(expected1, head1));

        ListNode head2 = LinkedLists.asLinkedList(list2);
        solution1.reorderList(head2);
        assertTrue(LinkedLists.equals(expected2, head2));
    }
}