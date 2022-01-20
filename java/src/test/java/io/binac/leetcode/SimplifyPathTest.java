package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SimplifyPathTest {
    private static final SimplifyPath.Solution1 SOLUTION1 = new SimplifyPath.Solution1();

    private final String PATH1 = "/home/", EXPECTED1 = "/home";

    private final String PATH2 = "/../", EXPECTED2 = "/";

    private final String PATH3 = "/home//foo/", EXPECTED3 = "/home/foo";

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.simplifyPath(PATH1));
        assertEquals(EXPECTED2, SOLUTION1.simplifyPath(PATH2));
        assertEquals(EXPECTED3, SOLUTION1.simplifyPath(PATH3));
    }
}