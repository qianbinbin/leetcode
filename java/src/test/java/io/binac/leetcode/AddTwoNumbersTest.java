package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class AddTwoNumbersTest {
    private final AddTwoNumbers.Solution1 solution1 = new AddTwoNumbers.Solution1();

    private final ListNode l1 = LinkedLists.asLinkedList(2, 4, 3);
    private final ListNode l2 = LinkedLists.asLinkedList(5, 6, 4);
    private final ListNode EXPECTED = LinkedLists.asLinkedList(7, 0, 8);

    private final ListNode l1Carry = LinkedLists.asLinkedList(5);
    private final ListNode l2Carry = LinkedLists.asLinkedList(5);
    private final ListNode EXPECTEDCARRY = LinkedLists.asLinkedList(0, 1);

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED, solution1.addTwoNumbers(l1, l2)));
    }

    @Test
    void test1Carry() {
        assertTrue(LinkedLists.equals(EXPECTEDCARRY, solution1.addTwoNumbers(l1Carry, l2Carry)));
    }
}