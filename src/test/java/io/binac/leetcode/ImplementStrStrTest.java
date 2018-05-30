package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ImplementStrStrTest {
    private final ImplementStrStr.Solution1 solution1 = new ImplementStrStr.Solution1();

    @Test
    void test1() {
        assertEquals(2, solution1.strStr("hello", "ll"));
        assertEquals(-1, solution1.strStr("aaaaa", "bba"));
    }
}