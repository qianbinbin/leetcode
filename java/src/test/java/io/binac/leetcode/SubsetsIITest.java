package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class SubsetsIITest {
    private static final SubsetsII.Solution1 SOLUTION1 = new SubsetsII.Solution1();

    private int[] getNUMS1() {
        return new int[]{1, 2, 2};
    }

    private final List<List<Integer>> EXPECTED1 = Arrays.asList(
            Collections.emptyList(),
            Collections.singletonList(1),
            Arrays.asList(1, 2),
            Arrays.asList(1, 2, 2),
            Collections.singletonList(2),
            Arrays.asList(2, 2)
    );

    private int[] getNUMS2() {
        return new int[]{0};
    }

    private final List<List<Integer>> EXPECTED2 = Arrays.asList(
            Collections.emptyList(),
            Collections.singletonList(0)
    );

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.subsetsWithDup(getNUMS1()));
        assertEquals(EXPECTED2, SOLUTION1.subsetsWithDup(getNUMS2()));
    }
}