package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class GrayCodeTest {
    private final GrayCode.Solution1 solution1 = new GrayCode.Solution1();

    private final GrayCode.Solution2 solution2 = new GrayCode.Solution2();

    @Test
    void test1() {
        List<Integer> expected = Arrays.asList(0, 1, 3, 2);
        assertEquals(expected, solution1.grayCode(2));
    }

    @Test
    void test2() {
        List<Integer> expected = Arrays.asList(0, 1, 3, 2);
        assertEquals(expected, solution2.grayCode(2));
    }
}