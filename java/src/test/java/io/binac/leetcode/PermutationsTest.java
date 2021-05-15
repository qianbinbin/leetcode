package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PermutationsTest {
    private static final Permutations.Solution1 SOLUTION1 = new Permutations.Solution1();

    private final int[] NUMS1 = {1, 2, 3};
    private final List<List<Integer>> EXPECTED1 = Arrays.asList(
            Arrays.asList(1, 2, 3),
            Arrays.asList(1, 3, 2),
            Arrays.asList(2, 1, 3),
            Arrays.asList(2, 3, 1),
            Arrays.asList(3, 1, 2),
            Arrays.asList(3, 2, 1)
    );

    private final int[] NUMS2 = {0, 1};
    private final List<List<Integer>> EXPECTED2 = Arrays.asList(
            Arrays.asList(0, 1),
            Arrays.asList(1, 0)
    );

    private final int[] NUMS3 = {1};
    private final List<List<Integer>> EXPECTED3 = Collections.singletonList(
            Collections.singletonList(1)
    );

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.permute(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.permute(NUMS2));
        assertEquals(EXPECTED3, SOLUTION1.permute(NUMS3));
    }
}