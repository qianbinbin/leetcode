package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MergeKSortedListsTest {
    private final MergeKSortedLists.Solution1 solution1 = new MergeKSortedLists.Solution1();

    @Test
    void test1() {
        ListNode lists[] = {
                LinkedLists.asLinkedList(1, 4, 5),
                LinkedLists.asLinkedList(1, 3, 4),
                LinkedLists.asLinkedList(2, 6)
        };
        ListNode result = solution1.mergeKLists(lists);
        ListNode expected = LinkedLists.asLinkedList(1, 1, 2, 3, 4, 4, 5, 6);
        assertTrue(LinkedLists.equals(expected, result));
    }
}