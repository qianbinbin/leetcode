package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class GrayCodeTest {
    private static final GrayCode.Solution1 SOLUTION1 = new GrayCode.Solution1();
    private static final GrayCode.Solution2 SOLUTION2 = new GrayCode.Solution2();

    private final int N1 = 2;
    private final List<Integer> EXPECTED1 = Arrays.asList(0, 1, 3, 2);

    private final int N2 = 1;
    private final List<Integer> EXPECTED2 = Arrays.asList(0, 1);

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.grayCode(N1));
        assertEquals(EXPECTED2, SOLUTION1.grayCode(N2));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.grayCode(N1));
        assertEquals(EXPECTED2, SOLUTION2.grayCode(N2));
    }
}