package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class HappyNumberTest {
    private static final HappyNumber.Solution1 SOLUTION1 = new HappyNumber.Solution1();
    private static final HappyNumber.Solution2 SOLUTION2 = new HappyNumber.Solution2();
    private static final HappyNumber.Solution3 SOLUTION3 = new HappyNumber.Solution3();

    private final int N1 = 19;
    private final boolean EXPECTED1 = true;

    private final int N2 = 2;
    private final boolean EXPECTED2 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isHappy(N1));
        assertEquals(EXPECTED2, SOLUTION1.isHappy(N2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.isHappy(N1));
        assertEquals(EXPECTED2, SOLUTION2.isHappy(N2));
    }

    @Test
    void test3() {
        assertEquals(EXPECTED1, SOLUTION3.isHappy(N1));
        assertEquals(EXPECTED2, SOLUTION3.isHappy(N2));
    }
}