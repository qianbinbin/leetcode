package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RotateListTest {
    private final RotateList.Solution1 solution1 = new RotateList.Solution1();

    @Test
    void test1() {
        ListNode list1 = LinkedLists.asLinkedList(1, 2, 3, 4, 5);
        ListNode result1 = solution1.rotateRight(list1, 2);
        ListNode expected1 = LinkedLists.asLinkedList(4, 5, 1, 2, 3);
        assertTrue(LinkedLists.equals(expected1, result1));

        ListNode list2 = LinkedLists.asLinkedList(0, 1, 2);
        ListNode result2 = solution1.rotateRight(list2, 4);
        ListNode expected2 = LinkedLists.asLinkedList(2, 0, 1);
        assertTrue(LinkedLists.equals(expected2, result2));
    }
}