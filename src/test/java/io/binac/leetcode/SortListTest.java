package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SortListTest {

    private final SortList.Solution1 solution1 = new SortList.Solution1();

    private final int list1[] = {4, 2, 1, 3};

    private final ListNode expected1 = LinkedLists.asLinkedList(1, 2, 3, 4);

    private final int list2[] = {-1, 5, 3, 4, 0};

    private final ListNode expected2 = LinkedLists.asLinkedList(-1, 0, 3, 4, 5);

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(expected1, solution1.sortList(LinkedLists.asLinkedList(list1))));
        assertTrue(LinkedLists.equals(expected2, solution1.sortList(LinkedLists.asLinkedList(list2))));
    }
}