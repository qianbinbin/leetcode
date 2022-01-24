package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RemoveDuplicatesFromSortedListTest {
    private static final RemoveDuplicatesFromSortedList.Solution1 SOLUTION1 = new RemoveDuplicatesFromSortedList.Solution1();

    private ListNode getHEAD1() {
        return LinkedLists.asLinkedList(1, 1, 2);
    }

    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(1, 2);

    private ListNode getHEAD2() {
        return LinkedLists.asLinkedList(1, 1, 2, 3, 3);
    }

    private final ListNode EXPECTED2 = LinkedLists.asLinkedList(1, 2, 3);

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.deleteDuplicates(getHEAD1())));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.deleteDuplicates(getHEAD2())));
    }
}