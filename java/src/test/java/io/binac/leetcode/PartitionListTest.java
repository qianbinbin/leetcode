package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PartitionListTest {
    private final PartitionList.Solution1 solution1 = new PartitionList.Solution1();

    @Test
    void test1() {
        ListNode head = LinkedLists.asLinkedList(1, 4, 3, 2, 5, 2);
        ListNode actual = solution1.partition(head, 3);
        ListNode expected = LinkedLists.asLinkedList(1, 2, 2, 4, 3, 5);
        assertTrue(LinkedLists.equals(expected, actual));
    }
}