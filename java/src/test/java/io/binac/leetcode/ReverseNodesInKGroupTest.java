package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReverseNodesInKGroupTest {
    private final ReverseNodesInKGroup.Solution1 solution1 = new ReverseNodesInKGroup.Solution1();

    @Test
    void test1() {
        ListNode result1 = solution1.reverseKGroup(LinkedLists.asLinkedList(1, 2, 3, 4, 5), 2);
        ListNode expected1 = LinkedLists.asLinkedList(2, 1, 4, 3, 5);
        assertTrue(LinkedLists.equals(result1, expected1));
        ListNode result2 = solution1.reverseKGroup(LinkedLists.asLinkedList(1, 2, 3, 4, 5), 3);
        ListNode expected2 = LinkedLists.asLinkedList(3, 2, 1, 4, 5);
        assertTrue(LinkedLists.equals(result2, expected2));
    }
}