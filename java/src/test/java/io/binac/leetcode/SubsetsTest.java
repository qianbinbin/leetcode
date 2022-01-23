package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class SubsetsTest {
    private final Subsets.Solution1 SOLUTION1 = new Subsets.Solution1();

    private final int[] NUMS1 = {1, 2, 3};
    private final List<List<Integer>> EXPECTED1 = Arrays.asList(
            Collections.emptyList(),
            Collections.singletonList(1),
            Arrays.asList(1, 2),
            Arrays.asList(1, 2, 3),
            Arrays.asList(1, 3),
            Collections.singletonList(2),
            Arrays.asList(2, 3),
            Collections.singletonList(3)
    );

    private final int[] NUMS2 = {0};
    private final List<List<Integer>> EXPECTED2 = Arrays.asList(
            Collections.emptyList(),
            Collections.singletonList(0)
    );

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.subsets(NUMS1));
        assertEquals(EXPECTED2, SOLUTION1.subsets(NUMS2));
    }
}