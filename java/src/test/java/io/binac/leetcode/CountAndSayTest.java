package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CountAndSayTest {
    private final CountAndSay.Solution1 solution1 = new CountAndSay.Solution1();

    @Test
    void test1() {
        assertEquals("1", solution1.countAndSay(1));
        assertEquals("1211", solution1.countAndSay(4));
    }
}