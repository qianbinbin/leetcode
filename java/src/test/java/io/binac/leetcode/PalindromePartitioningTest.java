package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PalindromePartitioningTest {
    private final PalindromePartitioning.Solution1 solution1 = new PalindromePartitioning.Solution1();

    @Test
    void test1() {
        List<List<String>> expected = Arrays.asList(
                Arrays.asList("a", "a", "b"),
                Arrays.asList("aa", "b")
        );
        assertEquals(expected, solution1.partition("aab"));
    }
}