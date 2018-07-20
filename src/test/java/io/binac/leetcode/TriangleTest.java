package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class TriangleTest {
    private final Triangle.Solution1 solution1 = new Triangle.Solution1();

    @Test
    void test1() {
        List<List<Integer>> triangle = Arrays.asList(
                Collections.singletonList(2),
                Arrays.asList(3, 4),
                Arrays.asList(6, 5, 7),
                Arrays.asList(4, 1, 8, 3)
        );
        assertEquals(11, solution1.minimumTotal(triangle));
    }
}