package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SwapNodesInPairsTest {
    private static final SwapNodesInPairs.Solution1 SOLUTION1 = new SwapNodesInPairs.Solution1();

    private final ListNode HEAD1 = LinkedLists.asLinkedList(1, 2, 3, 4);
    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(2, 1, 4, 3);

    private final ListNode HEAD2 = null;
    private final ListNode EXPECTED2 = null;

    private final ListNode HEAD3 = LinkedLists.asLinkedList(1);
    private final ListNode EXPECTED3 = LinkedLists.asLinkedList(1);

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.swapPairs(HEAD1)));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.swapPairs(HEAD2)));
        assertTrue(LinkedLists.equals(EXPECTED3, SOLUTION1.swapPairs(HEAD3)));
    }
}