package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SimplifyPathTest {
    private final SimplifyPath.Solution1 solution1 = new SimplifyPath.Solution1();

    @Test
    void test1() {
        assertEquals("/home", solution1.simplifyPath("/home/"));
        assertEquals("/c", solution1.simplifyPath("/a/./b/../../c/"));
        assertEquals("/", solution1.simplifyPath("/../"));
        assertEquals("/home/foo", solution1.simplifyPath("/home//foo/"));
    }
}