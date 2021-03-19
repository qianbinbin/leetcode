package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ImplementStrStrTest {
    private static final ImplementStrStr.Solution1 SOLUTION1 = new ImplementStrStr.Solution1();
    private static final ImplementStrStr.Solution2 SOLUTION2 = new ImplementStrStr.Solution2();

    private final String HAYSTACK1 = "hello";
    private final String NEEDLE1 = "ll";
    private final int EXPECTED1 = 2;

    private final String HAYSTACK2 = "aaaaa";
    private final String NEEDLE2 = "bba";
    private final int EXPECTED2 = -1;

    private final String HAYSTACK3 = "";
    private final String NEEDLE3 = "";
    private final int EXPECTED3 = 0;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.strStr(HAYSTACK1, NEEDLE1));
        assertEquals(EXPECTED2, SOLUTION1.strStr(HAYSTACK2, NEEDLE2));
        assertEquals(EXPECTED3, SOLUTION1.strStr(HAYSTACK3, NEEDLE3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.strStr(HAYSTACK1, NEEDLE1));
        assertEquals(EXPECTED2, SOLUTION2.strStr(HAYSTACK2, NEEDLE2));
        assertEquals(EXPECTED3, SOLUTION2.strStr(HAYSTACK3, NEEDLE3));
    }
}