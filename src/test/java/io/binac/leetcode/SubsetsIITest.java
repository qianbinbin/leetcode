package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class SubsetsIITest {
    private final SubsetsII.Solution1 solution1 = new SubsetsII.Solution1();

    @Test
    void test1() {
        int nums[] = {1, 2, 2};
        List<List<Integer>> expected = Arrays.asList(
                Collections.emptyList(),
                Collections.singletonList(1),
                Arrays.asList(1, 2),
                Arrays.asList(1, 2, 2),
                Collections.singletonList(2),
                Arrays.asList(2, 2)
        );
        assertEquals(expected, solution1.subsetsWithDup(nums));
    }
}