package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ReverseLinkedListTest {
    private static final ReverseLinkedList.Solution1 SOLUTION1 = new ReverseLinkedList.Solution1();
    private static final ReverseLinkedList.Solution2 SOLUTION2 = new ReverseLinkedList.Solution2();

    private ListNode getHEAD1() {
        return LinkedLists.asLinkedList(1, 2, 3, 4, 5);
    }

    private final ListNode EXPECTED1 = LinkedLists.asLinkedList(5, 4, 3, 2, 1);

    private ListNode getHEAD2() {
        return LinkedLists.asLinkedList(1, 2);
    }

    private final ListNode EXPECTED2 = LinkedLists.asLinkedList(2, 1);

    private ListNode getHEAD3() {
        return LinkedLists.asLinkedList();
    }

    private final ListNode EXPECTED3 = LinkedLists.asLinkedList();

    @Test
    void test1() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION1.reverseList(getHEAD1())));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION1.reverseList(getHEAD2())));
        assertTrue(LinkedLists.equals(EXPECTED3, SOLUTION1.reverseList(getHEAD3())));
    }

    @Test
    void test2() {
        assertTrue(LinkedLists.equals(EXPECTED1, SOLUTION2.reverseList(getHEAD1())));
        assertTrue(LinkedLists.equals(EXPECTED2, SOLUTION2.reverseList(getHEAD2())));
        assertTrue(LinkedLists.equals(EXPECTED3, SOLUTION2.reverseList(getHEAD3())));
    }
}