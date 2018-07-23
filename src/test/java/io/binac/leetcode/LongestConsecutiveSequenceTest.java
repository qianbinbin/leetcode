package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class LongestConsecutiveSequenceTest {
    private final LongestConsecutiveSequence.Solution1 solution1 = new LongestConsecutiveSequence.Solution1();

    @Test
    void test1() {
        int nums[] = {100, 4, 200, 1, 3, 2};
        assertEquals(4, solution1.longestConsecutive(nums));
    }
}