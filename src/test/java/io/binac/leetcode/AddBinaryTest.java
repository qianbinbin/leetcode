package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class AddBinaryTest {
    private final AddBinary.Solution1 solution1 = new AddBinary.Solution1();

    @Test
    void test1() {
        assertEquals("100", solution1.addBinary("11", "1"));
        assertEquals("10101", solution1.addBinary("1010", "1011"));
    }
}