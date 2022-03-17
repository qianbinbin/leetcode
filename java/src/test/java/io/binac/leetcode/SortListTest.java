package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SortListTest {
    private static final SortList.Solution1 SOLUTION1 = new SortList.Solution1();

    private ListNode getHEAD1() {
        return LinkedLists.asLinkedList(4, 2, 1, 3);
    }

    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(1, 2, 3, 4);

    private ListNode getHEAD2() {
        return LinkedLists.asLinkedList(-1, 5, 3, 4, 0);
    }

    private final ListNode EXPECTED2 = LinkedLists.asLinkedList(-1, 0, 3, 4, 5);

    private ListNode getHEAD3() {
        return LinkedLists.asLinkedList();
    }

    private final ListNode EXPECTED3 = LinkedLists.asLinkedList();

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.sortList(getHEAD1())));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.sortList(getHEAD2())));
        assertTrue(LinkedLists.equals(EXPECTED3, SOLUTION1.sortList(getHEAD3())));
    }
}