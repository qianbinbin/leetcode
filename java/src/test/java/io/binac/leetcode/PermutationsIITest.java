package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PermutationsIITest {
    private static final PermutationsII.Solution1 SOLUTION1 = new PermutationsII.Solution1();

    private final int[] NUMS1 = {1, 1, 2};
    private final List<List<Integer>> EXPECTED1 = Arrays.asList(
            Arrays.asList(1, 1, 2),
            Arrays.asList(1, 2, 1),
            Arrays.asList(2, 1, 1)
    );

    private final int[] NUMS2 = {1, 2, 3};
    private final List<List<Integer>> EXPECTED2 = Arrays.asList(
            Arrays.asList(1, 2, 3),
            Arrays.asList(1, 3, 2),
            Arrays.asList(2, 1, 3),
            Arrays.asList(2, 3, 1),
            Arrays.asList(3, 1, 2),
            Arrays.asList(3, 2, 1)
    );

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.permuteUnique(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.permuteUnique(NUMS2));
    }
}