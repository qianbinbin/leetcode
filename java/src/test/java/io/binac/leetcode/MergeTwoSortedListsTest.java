package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MergeTwoSortedListsTest {
    private final MergeTwoSortedLists.Solution1 solution1 = new MergeTwoSortedLists.Solution1();

    @Test
    void test1() {
        ListNode l1 = LinkedLists.asLinkedList(1, 2, 4);
        ListNode l2 = LinkedLists.asLinkedList(1, 3, 4);
        ListNode result = solution1.mergeTwoLists(l1, l2);
        ListNode expected = LinkedLists.asLinkedList(1, 1, 2, 3, 4, 4);
        assertTrue(LinkedLists.equals(expected, result));
    }
}