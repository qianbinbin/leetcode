package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class CombinationSumTest {
    private final CombinationSum.Solution1 solution1 = new CombinationSum.Solution1();

    @Test
    void test1() {
        int candidates1[] = {2, 3, 6, 7};
        List<List<Integer>> result1 = solution1.combinationSum(candidates1, 7);
        List<List<Integer>> expected1 = Arrays.asList(
                Arrays.asList(2, 2, 3),
                Collections.singletonList(7));
        assertEquals(expected1, result1);

        int candidates2[] = {2, 3, 5};
        List<List<Integer>> result2 = solution1.combinationSum(candidates2, 8);
        List<List<Integer>> expected2 = Arrays.asList(
                Arrays.asList(2, 2, 2, 2),
                Arrays.asList(2, 3, 3),
                Arrays.asList(3, 5));
        assertEquals(expected2, result2);
    }
}