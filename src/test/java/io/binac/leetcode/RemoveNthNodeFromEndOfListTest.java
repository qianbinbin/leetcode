package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RemoveNthNodeFromEndOfListTest {
    private final RemoveNthNodeFromEndOfList.Solution1 solution1 = new RemoveNthNodeFromEndOfList.Solution1();

    @Test
    void test1() {
        ListNode head = LinkedLists.asLinkedList(1, 2, 3, 4, 5);
        ListNode result = solution1.removeNthFromEnd(head, 2);
        ListNode expected = LinkedLists.asLinkedList(1, 2, 3, 5);
        assertTrue(LinkedLists.equals(expected, result));
    }
}