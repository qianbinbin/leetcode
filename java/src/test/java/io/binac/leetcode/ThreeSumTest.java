package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class ThreeSumTest {
    private static final ThreeSum.Solution1 SOLUTION1 = new ThreeSum.Solution1();

    private final int[] NUMS1 = {-1, 0, 1, 2, -1, -4};
    private final List<List<Integer>> EXPECTED1 = Arrays.asList(Arrays.asList(-1, -1, 2), Arrays.asList(-1, 0, 1));

    private final int[] NUMS2 = {};
    private final List<List<Integer>> EXPECTED2 = Collections.emptyList();

    private final int[] NUMS3 = {0};
    private final List<List<Integer>> EXPECTED3 = Collections.emptyList();

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.threeSum(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.threeSum(NUMS2));
        assertEquals(EXPECTED3, SOLUTION1.threeSum(NUMS3));
    }
}