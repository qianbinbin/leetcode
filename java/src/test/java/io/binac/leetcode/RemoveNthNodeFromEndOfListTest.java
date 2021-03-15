package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RemoveNthNodeFromEndOfListTest {
    private static final RemoveNthNodeFromEndOfList.Solution1 SOLUTION1 = new RemoveNthNodeFromEndOfList.Solution1();

    private final ListNode HEAD1 = LinkedLists.asLinkedList(1, 2, 3, 4, 5);
    private final int N1 = 2;
    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(1, 2, 3, 5);

    private final ListNode HEAD2 = LinkedLists.asLinkedList(1);
    private final int N2 = 1;
    private final ListNode EXPECTED2 = null;

    private final ListNode HEAD3 = LinkedLists.asLinkedList(1, 2);
    private final int N3 = 1;
    private final ListNode EXPECTED3 = LinkedLists.asLinkedList(1);

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.removeNthFromEnd(HEAD1, N1)));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.removeNthFromEnd(HEAD2, N2)));
        assertTrue(LinkedLists.equals(EXPECTED3, SOLUTION1.removeNthFromEnd(HEAD3, N3)));
    }
}