package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReverseNodesInKGroupTest {
    private static final ReverseNodesInKGroup.Solution1 SOLUTION1 = new ReverseNodesInKGroup.Solution1();

    private final ListNode HEAD1 = LinkedLists.asLinkedList(1, 2, 3, 4, 5);
    private final int K1 = 2;
    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(2, 1, 4, 3, 5);

    private final ListNode HEAD2 = LinkedLists.asLinkedList(1, 2, 3, 4, 5);
    private final int K2 = 3;
    private final ListNode EXPECTED2 = LinkedLists.asLinkedList(3, 2, 1, 4, 5);

    private final ListNode HEAD3 = LinkedLists.asLinkedList(1, 2, 3, 4, 5);
    private final int K3 = 1;
    private final ListNode EXPECTED3 = LinkedLists.asLinkedList(1, 2, 3, 4, 5);

    private final ListNode HEAD4 = LinkedLists.asLinkedList(1);
    private final int K4 = 1;
    private final ListNode EXPECTED4 = LinkedLists.asLinkedList(1);

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.reverseKGroup(HEAD1, K1)));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.reverseKGroup(HEAD2, K2)));
        assertTrue(LinkedLists.equals(EXPECTED3, SOLUTION1.reverseKGroup(HEAD3, K3)));
        assertTrue(LinkedLists.equals(EXPECTED4, SOLUTION1.reverseKGroup(HEAD4, K4)));
    }
}