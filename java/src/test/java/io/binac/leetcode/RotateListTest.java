package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RotateListTest {
    private static final RotateList.Solution1 SOLUTION1 = new RotateList.Solution1();

    private final ListNode LIST1 = LinkedLists.asLinkedList(1, 2, 3, 4, 5);
    private final int K1 = 2;
    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(4, 5, 1, 2, 3);

    private final ListNode LIST2 = LinkedLists.asLinkedList(0, 1, 2);
    private final int K2 = 4;
    private final ListNode EXPECTED2 = LinkedLists.asLinkedList(2, 0, 1);

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.rotateRight(LIST1, K1)));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.rotateRight(LIST2, K2)));
    }
}