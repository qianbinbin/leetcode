package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PascalsTriangleTest {
    private static final PascalsTriangle.Solution1 SOLUTION1 = new PascalsTriangle.Solution1();

    private final int NUMROWS1 = 5;
    private final List<List<Integer>> EXPECTED1 = Arrays.asList(
            Collections.singletonList(1),
            Arrays.asList(1, 1),
            Arrays.asList(1, 2, 1),
            Arrays.asList(1, 3, 3, 1),
            Arrays.asList(1, 4, 6, 4, 1)
    );

    private final int NUMROWS2 = 1;
    private final List<List<Integer>> EXPECTED2 = Collections.singletonList(
            Collections.singletonList(1)
    );

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.generate(NUMROWS1));
        assertEquals(EXPECTED2, SOLUTION1.generate(NUMROWS2));
    }
}