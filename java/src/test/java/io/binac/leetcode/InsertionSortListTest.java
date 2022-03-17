package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class InsertionSortListTest {
    private static final InsertionSortList.Solution1 SOLUTION1 = new InsertionSortList.Solution1();

    private final int[] LIST1 = {4, 2, 1, 3};
    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(1, 2, 3, 4);

    private final int[] LIST2 = {-1, 5, 3, 4, 0};
    private final ListNode EXPECTED2 = LinkedLists.asLinkedList(-1, 0, 3, 4, 5);

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.insertionSortList(LinkedLists.asLinkedList(LIST1))));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.insertionSortList(LinkedLists.asLinkedList(LIST2))));
    }
}