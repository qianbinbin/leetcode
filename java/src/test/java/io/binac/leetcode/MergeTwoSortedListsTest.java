package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MergeTwoSortedListsTest {
    private static final MergeTwoSortedLists.Solution1 SOLUTION1 = new MergeTwoSortedLists.Solution1();

    private final ListNode L11 = LinkedLists.asLinkedList(1, 2, 4);
    private final ListNode L12 = LinkedLists.asLinkedList(1, 3, 4);
    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(1, 1, 2, 3, 4, 4);

    private final ListNode L21 = null;
    private final ListNode L22 = null;
    private final ListNode EXPECTED2 = null;

    private final ListNode L31 = null;
    private final ListNode L32 = LinkedLists.asLinkedList(0);
    private final ListNode EXPECTED3 = LinkedLists.asLinkedList(0);

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.mergeTwoLists(L11, L12)));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.mergeTwoLists(L21, L22)));
        assertTrue(LinkedLists.equals(EXPECTED3, SOLUTION1.mergeTwoLists(L31, L32)));
    }
}