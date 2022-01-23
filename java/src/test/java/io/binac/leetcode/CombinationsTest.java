package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class CombinationsTest {
    private static final Combinations.Solution1 SOLUTION1 = new Combinations.Solution1();

    private final int N1 = 4, K1 = 2;
    private final List<List<Integer>> EXPECTED1 = Arrays.asList(
            Arrays.asList(1, 2),
            Arrays.asList(1, 3),
            Arrays.asList(1, 4),
            Arrays.asList(2, 3),
            Arrays.asList(2, 4),
            Arrays.asList(3, 4)
    );

    private final int N2 = 1, K2 = 1;
    private final List<List<Integer>> EXPECTED2 = Collections.singletonList(Collections.singletonList(1));

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.combine(N1, K1));
        assertEquals(EXPECTED2, SOLUTION1.combine(N2, K2));
    }
}