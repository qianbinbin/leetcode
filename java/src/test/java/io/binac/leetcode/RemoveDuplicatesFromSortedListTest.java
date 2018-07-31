package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RemoveDuplicatesFromSortedListTest {
    private RemoveDuplicatesFromSortedList.Solution1 solution1 = new RemoveDuplicatesFromSortedList.Solution1();

    @Test
    void test1() {
        ListNode head1 = LinkedLists.asLinkedList(1, 1, 2);
        ListNode actual1 = solution1.deleteDuplicates(head1);
        ListNode expected1 = LinkedLists.asLinkedList(1, 2);
        assertTrue(LinkedLists.equals(expected1, actual1));

        ListNode head2 = LinkedLists.asLinkedList(1, 1, 2, 3, 3);
        ListNode actual2 = solution1.deleteDuplicates(head2);
        ListNode expected2 = LinkedLists.asLinkedList(1, 2, 3);
        assertTrue(LinkedLists.equals(expected2, actual2));
    }
}