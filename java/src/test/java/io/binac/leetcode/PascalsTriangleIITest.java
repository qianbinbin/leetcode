package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PascalsTriangleIITest {
    private static final PascalsTriangleII.Solution1 SOLUTION1 = new PascalsTriangleII.Solution1();

    private final int ROWINDEX1 = 3;
    private final List<Integer> EXPECTED1 = Arrays.asList(1, 3, 3, 1);

    private final int ROWINDEX2 = 0;
    private final List<Integer> EXPECTED2 = Collections.singletonList(1);

    private final int ROWINDEX3 = 1;
    private final List<Integer> EXPECTED3 = Arrays.asList(1, 1);

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.getRow(ROWINDEX1));
        assertEquals(EXPECTED2, SOLUTION1.getRow(ROWINDEX2));
        assertEquals(EXPECTED3, SOLUTION1.getRow(ROWINDEX3));
    }
}