package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class CombinationSumTest {
    private static final CombinationSum.Solution1 SOLUTION1 = new CombinationSum.Solution1();

    private final int[] CANDIDATES1 = {2, 3, 6, 7};
    private final int TARGET1 = 7;
    private final List<List<Integer>> EXPECTED1 = Arrays.asList(
            Arrays.asList(2, 2, 3),
            Collections.singletonList(7));

    private final int[] CANDIDATES2 = {2, 3, 5};
    private final int TARGET2 = 8;
    private final List<List<Integer>> EXPECTED2 = Arrays.asList(
            Arrays.asList(2, 2, 2, 2),
            Arrays.asList(2, 3, 3),
            Arrays.asList(3, 5));

    private final int[] CANDIDATES3 = {2};
    private final int TARGET3 = 1;
    private final List<List<Integer>> EXPECTED3 = Collections.emptyList();

    private final int[] CANDIDATES4 = {1};
    private final int TARGET4 = 1;
    private final List<List<Integer>> EXPECTED4 = Collections.singletonList(Collections.singletonList(1));

    private final int[] CANDIDATES5 = {1};
    private final int TARGET5 = 2;
    private final List<List<Integer>> EXPECTED5 = Collections.singletonList(Arrays.asList(1, 1));

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.combinationSum(CANDIDATES1, TARGET1));
        assertEquals(EXPECTED2, SOLUTION1.combinationSum(CANDIDATES2, TARGET2));
        assertEquals(EXPECTED3, SOLUTION1.combinationSum(CANDIDATES3, TARGET3));
        assertEquals(EXPECTED4, SOLUTION1.combinationSum(CANDIDATES4, TARGET4));
        assertEquals(EXPECTED5, SOLUTION1.combinationSum(CANDIDATES5, TARGET5));
    }
}