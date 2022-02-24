package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class TriangleTest {
    private static final Triangle.Solution1 SOLUTION1 = new Triangle.Solution1();

    private final List<List<Integer>> TRIANGLE1 = Arrays.asList(
            Collections.singletonList(2),
            Arrays.asList(3, 4),
            Arrays.asList(6, 5, 7),
            Arrays.asList(4, 1, 8, 3)
    );
    private final int EXPECTED1 = 11;

    private final List<List<Integer>> TRIANGLE2 = Collections.singletonList(
            Collections.singletonList(-10)
    );
    private final int EXPECTED2 = -10;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.minimumTotal(TRIANGLE1));
        assertEquals(EXPECTED2, SOLUTION1.minimumTotal(TRIANGLE2));
    }
}