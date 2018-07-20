package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PascalsTriangleTest {
    private final PascalsTriangle.Solution1 solution1 = new PascalsTriangle.Solution1();

    @Test
    void test1() {
        List<List<Integer>> expected = Arrays.asList(
                Collections.singletonList(1),
                Arrays.asList(1, 1),
                Arrays.asList(1, 2, 1),
                Arrays.asList(1, 3, 3, 1),
                Arrays.asList(1, 4, 6, 4, 1)
        );
        assertEquals(expected, solution1.generate(5));
    }
}