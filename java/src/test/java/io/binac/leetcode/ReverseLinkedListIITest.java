package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReverseLinkedListIITest {
    private static final ReverseLinkedListII.Solution1 SOLUTION1 = new ReverseLinkedListII.Solution1();

    private final ListNode HEAD1 = LinkedLists.asLinkedList(1, 2, 3, 4, 5);
    private final int LEFT1 = 2, RIGHT1 = 4;
    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(1, 4, 3, 2, 5);

    private final ListNode HEAD2 = LinkedLists.asLinkedList(5);
    private final int LEFT2 = 1, RIGHT2 = 1;
    private final ListNode EXPECTED2 = LinkedLists.asLinkedList(5);

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.reverseBetween(HEAD1, LEFT1, RIGHT1)));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.reverseBetween(HEAD2, LEFT2, RIGHT2)));
    }
}