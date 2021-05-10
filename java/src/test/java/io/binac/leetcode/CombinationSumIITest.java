package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class CombinationSumIITest {
    private static final CombinationSumII.Solution1 SOLUTION1 = new CombinationSumII.Solution1();

    private final int[] CANDIDATES1 = {10, 1, 2, 7, 6, 1, 5};
    private final int TARGET1 = 8;
    private final List<List<Integer>> EXPECTED1 = Arrays.asList(
            Arrays.asList(1, 1, 6),
            Arrays.asList(1, 2, 5),
            Arrays.asList(1, 7),
            Arrays.asList(2, 6)
    );

    private final int[] CANDIDATES2 = {2, 5, 2, 1, 2};
    private final int TARGET2 = 5;
    private final List<List<Integer>> EXPECTED2 = Arrays.asList(
            Arrays.asList(1, 2, 2),
            Collections.singletonList(5)
    );

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.combinationSum2(CANDIDATES1, TARGET1));
        assertEquals(EXPECTED2, SOLUTION1.combinationSum2(CANDIDATES2, TARGET2));
    }
}