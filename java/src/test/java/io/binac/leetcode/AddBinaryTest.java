package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class AddBinaryTest {
    private static final AddBinary.Solution1 SOLUTION1 = new AddBinary.Solution1();

    private final String A1 = "11", B1 = "1";
    private final String EXPECTED1 = "100";

    private final String A2 = "1010", B2 = "1011";
    private final String EXPECTED2 = "10101";

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.addBinary(A1, B1));
        assertEquals(EXPECTED2, SOLUTION1.addBinary(A2, B2));
    }
}