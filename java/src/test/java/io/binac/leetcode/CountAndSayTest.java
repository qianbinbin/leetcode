package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class CountAndSayTest {
    private static final CountAndSay.Solution1 SOLUTION1 = new CountAndSay.Solution1();

    private final int N1 = 1;
    private final String EXPECTED1 = "1";

    private final int N2 = 4;
    private final String EXPECTED2 = "1211";

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.countAndSay(N1));
        assertEquals(EXPECTED2, SOLUTION1.countAndSay(N2));
    }
}