package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class CombinationSumIITest {
    private final CombinationSumII.Solution1 solution1 = new CombinationSumII.Solution1();

    @Test
    void test1() {
        int candidates1[] = {10, 1, 2, 7, 6, 1, 5};
        List<List<Integer>> result1 = solution1.combinationSum2(candidates1, 8);
        List<List<Integer>> expected1 = Arrays.asList(
                Arrays.asList(1, 1, 6),
                Arrays.asList(1, 2, 5),
                Arrays.asList(1, 7),
                Arrays.asList(2, 6)
        );
        assertEquals(expected1, result1);

        int candidates2[] = {2, 5, 2, 1, 2};
        List<List<Integer>> result2 = solution1.combinationSum2(candidates2, 5);
        List<List<Integer>> expected2 = Arrays.asList(
                Arrays.asList(1, 2, 2),
                Collections.singletonList(5)
        );
        assertEquals(expected2, result2);
    }
}