package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class AddTwoNumbersTest {
    private final AddTwoNumbers.Solution1 solution1 = new AddTwoNumbers.Solution1();

    @Test
    void test1() {
        ListNode l1 = LinkedLists.asLinkedList(2, 4, 3);
        ListNode l2 = LinkedLists.asLinkedList(5, 6, 4);
        ListNode result = solution1.addTwoNumbers(l1, l2);
        ListNode expected = LinkedLists.asLinkedList(7, 0, 8);
        assertTrue(LinkedLists.equals(expected, result));
    }

    @Test
    void test1Carry() {
        ListNode l1 = LinkedLists.asLinkedList(5);
        ListNode l2 = LinkedLists.asLinkedList(5);
        ListNode result = solution1.addTwoNumbers(l1, l2);
        ListNode expected = LinkedLists.asLinkedList(0, 1);
        assertTrue(LinkedLists.equals(expected, result));
    }
}