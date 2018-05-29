package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SwapNodesInPairsTest {
    private final SwapNodesInPairs.Solution1 solution1 = new SwapNodesInPairs.Solution1();

    @Test
    void test1() {
        ListNode result = solution1.swapPairs(LinkedLists.asLinkedList(1, 2, 3, 4));
        ListNode expected = LinkedLists.asLinkedList(2, 1, 4, 3);
        assertTrue(LinkedLists.equals(expected, result));
    }
}