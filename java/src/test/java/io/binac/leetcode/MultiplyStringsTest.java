package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MultiplyStringsTest {
    private final MultiplyStrings.Solution1 solution1 = new MultiplyStrings.Solution1();

    @Test
    void test1() {
        assertEquals("6", solution1.multiply("2", "3"));
        assertEquals("56088", solution1.multiply("123", "456"));
    }
}