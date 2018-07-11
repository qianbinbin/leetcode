package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReverseLinkedListIITest {
    private final ReverseLinkedListII.Solution1 solution1 = new ReverseLinkedListII.Solution1();

    @Test
    void test1() {
        ListNode head = LinkedLists.asLinkedList(1, 2, 3, 4, 5);
        ListNode actual = solution1.reverseBetween(head, 2, 4);
        ListNode expected = LinkedLists.asLinkedList(1, 4, 3, 2, 5);
        assertTrue(LinkedLists.equals(expected, actual));
    }
}