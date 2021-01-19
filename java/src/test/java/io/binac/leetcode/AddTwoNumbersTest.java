package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class AddTwoNumbersTest {
    private static final AddTwoNumbers.Solution1 SOLUTION1 = new AddTwoNumbers.Solution1();

    private final ListNode L11 = LinkedLists.asLinkedList(2, 4, 3);
    private final ListNode L12 = LinkedLists.asLinkedList(5, 6, 4);
    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(7, 0, 8);

    private final ListNode L21 = LinkedLists.asLinkedList(0);
    private final ListNode L22 = LinkedLists.asLinkedList(0);
    private final ListNode EXPECTED2 = LinkedLists.asLinkedList(0);

    private final ListNode L31 = LinkedLists.asLinkedList(9, 9, 9, 9, 9, 9, 9);
    private final ListNode L32 = LinkedLists.asLinkedList(9, 9, 9, 9);
    private final ListNode EXPECTED3 = LinkedLists.asLinkedList(8, 9, 9, 9, 0, 0, 0, 1);

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.addTwoNumbers(L11, L12)));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.addTwoNumbers(L21, L22)));
        assertTrue(LinkedLists.equals(EXPECTED3, SOLUTION1.addTwoNumbers(L31, L32)));
    }
}