package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class SubsetsTest {
    private final Subsets.Solution1 solution1 = new Subsets.Solution1();

    @Test
    void test1() {
        int nums[] = {1, 2, 3};
        List<List<Integer>> expected = Arrays.asList(
                Collections.emptyList(),
                Collections.singletonList(1),
                Arrays.asList(1, 2),
                Arrays.asList(1, 2, 3),
                Arrays.asList(1, 3),
                Collections.singletonList(2),
                Arrays.asList(2, 3),
                Collections.singletonList(3)
        );
        assertEquals(expected, solution1.subsets(nums));
    }
}