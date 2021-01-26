package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class RegularExpressionMatchingTest {
    private static final RegularExpressionMatching.Solution1 SOLUTION1 = new RegularExpressionMatching.Solution1();
    private static final RegularExpressionMatching.Solution2 SOLUTION2 = new RegularExpressionMatching.Solution2();

    private final String S1 = "aa", P1 = "a";
    private final boolean EXPECTED1 = false;

    private final String S2 = "aa", P2 = "a*";
    private final boolean EXPECTED2 = true;

    private final String S3 = "ab", P3 = ".*";
    private final boolean EXPECTED3 = true;

    private final String S4 = "aab", P4 = "c*a*b";
    private final boolean EXPECTED4 = true;

    private final String S5 = "mississippi", P5 = "mis*is*p*.";
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