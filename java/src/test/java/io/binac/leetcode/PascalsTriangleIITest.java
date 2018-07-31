package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PascalsTriangleIITest {
    private final PascalsTriangleII.Solution1 solution1 = new PascalsTriangleII.Solution1();

    @Test
    void test1() {
        assertEquals(Arrays.asList(1, 3, 3, 1), solution1.getRow(3));
    }
}