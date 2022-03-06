package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class PalindromePartitioningTest {
    private static final PalindromePartitioning.Solution1 SOLUTION1 = new PalindromePartitioning.Solution1();

    private final String S1 = "aab";
    private final List<List<String>> EXPECTED1 = Arrays.asList(
            Arrays.asList("a", "a", "b"),
            Arrays.asList("aa", "b")
    );

    private final String S2 = "a";
    private final List<List<String>> EXPECTED2 = Collections.singletonList(Collections.singletonList("a"));


    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.partition(S1));
        assertEquals(EXPECTED2, SOLUTION1.partition(S2));
    }
}