package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.*;

import static org.junit.jupiter.api.Assertions.*;

class FourSumTest {
    private static final FourSum.Solution1 SOLUTION1 = new FourSum.Solution1();
    private static final FourSum.Solution2 SOLUTION2 = new FourSum.Solution2();

    private final int[] NUMS1 = {1, 0, -1, 0, -2, 2};
    private final int TARGET1 = 0;
    private final List<List<Integer>> EXPECTED1 = Arrays.asList(
            Arrays.asList(-2, -1, 1, 2),
            Arrays.asList(-2, 0, 0, 2),
            Arrays.asList(-1, 0, 0, 1)
    );

    private final int[] NUMS2 = {};
    private final int TARGET2 = 0;
    private final List<List<Integer>> EXPECTED2 = Collections.emptyList();

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.fourSum(NUMS1, TARGET1));
        assertEquals(EXPECTED2, SOLUTION1.fourSum(NUMS2, TARGET2));
    }

    @Test
    void test2() {
        assertEquals(new HashSet<>(EXPECTED1), new HashSet<>(SOLUTION2.fourSum(NUMS1, TARGET1)));
        assertEquals(EXPECTED2, SOLUTION2.fourSum(NUMS2, TARGET2));
    }
}