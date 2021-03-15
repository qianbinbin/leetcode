package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MergeKSortedListsTest {
    private static final MergeKSortedLists.Solution1 SOLUTION1 = new MergeKSortedLists.Solution1();
    private static final MergeKSortedLists.Solution2 SOLUTION2 = new MergeKSortedLists.Solution2();

    private final ListNode[] LISTS1 = {
            LinkedLists.asLinkedList(1, 4, 5),
            LinkedLists.asLinkedList(1, 3, 4),
            LinkedLists.asLinkedList(2, 6)
    };
    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(1, 1, 2, 3, 4, 4, 5, 6);

    private final ListNode[] LISTS2 = {};
    private final ListNode EXPECTED2 = null;

    private final ListNode[] LISTS3 = {LinkedLists.asLinkedList()};
    private final ListNode EXPECTED3 = null;


    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.mergeKLists(LISTS1)));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.mergeKLists(LISTS2)));
        assertTrue(LinkedLists.equals(EXPECTED3, SOLUTION1.mergeKLists(LISTS3)));
    }

    @Test
    void test2() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION2.mergeKLists(LISTS1)));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION2.mergeKLists(LISTS2)));
        assertTrue(LinkedLists.equals(EXPECTED3, SOLUTION2.mergeKLists(LISTS3)));
    }
}