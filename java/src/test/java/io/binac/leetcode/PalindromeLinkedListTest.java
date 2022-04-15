package io.binac.leetcode;

import io.binac.leetcode.util.LinkedLists;
import io.binac.leetcode.util.ListNode;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class PalindromeLinkedListTest {
    private static final PalindromeLinkedList.Solution1 SOLUTION1 = new PalindromeLinkedList.Solution1();

    private final ListNode HEAD1 = LinkedLists.asLinkedList(1, 2, 2, 1);
    private final boolean EXPECTED1 = true;

    private final ListNode HEAD2 = LinkedLists.asLinkedList(1, 2);
    private final boolean EXPECTED2 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isPalindrome(HEAD1));
        assertEquals(EXPECTED2, SOLUTION1.isPalindrome(HEAD2));
    }
}