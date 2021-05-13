package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class WildcardMatchingTest {
    private static final WildcardMatching.Solution1 SOLUTION1 = new WildcardMatching.Solution1();
    private static final WildcardMatching.Solution2 SOLUTION2 = new WildcardMatching.Solution2();

    private final String S1 = "aa", P1 = "a";
    private final boolean EXPECTED1 = false;

    private final String S2 = "aa", P2 = "*";
    private final boolean EXPECTED2 = true;

    private final String S3 = "cb", P3 = "?a";
    private final boolean EXPECTED3 = false;

    private final String S4 = "adceb", P4 = "*a*b";
    private final boolean EXPECTED4 = true;

    private final String S5 = "acdcb", P5 = "a*c?b";
    private final boolean EXPECTED5 = false;

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.isMatch(S1, P1));
        assertEquals(EXPECTED2, SOLUTION1.isMatch(S2, P2));
        assertEquals(EXPECTED3, SOLUTION1.isMatch(S3, P3));
        assertEquals(EXPECTED4, SOLUTION1.isMatch(S4, P4));
        assertEquals(EXPECTED5, SOLUTION1.isMatch(S5, P5));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.isMatch(S1, P1));
        assertEquals(EXPECTED2, SOLUTION2.isMatch(S2, P2));
        assertEquals(EXPECTED3, SOLUTION2.isMatch(S3, P3));
        assertEquals(EXPECTED4, SOLUTION2.isMatch(S4, P4));
        assertEquals(EXPECTED5, SOLUTION2.isMatch(S5, P5));
    }
}