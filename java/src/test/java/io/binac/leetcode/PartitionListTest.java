package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PartitionListTest {
    private static final PartitionList.Solution1 SOLUTION1 = new PartitionList.Solution1();

    private final ListNode HEAD1 = LinkedLists.asLinkedList(1, 4, 3, 2, 5, 2);
    private final int X1 = 3;
    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(1, 2, 2, 4, 3, 5);

    private final ListNode HEAD2 = LinkedLists.asLinkedList(2, 1);
    private final int X2 = 2;
    private final ListNode EXPECTED2 = LinkedLists.asLinkedList(1, 2);

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.partition(HEAD1, X1)));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.partition(HEAD2, X2)));
    }
}