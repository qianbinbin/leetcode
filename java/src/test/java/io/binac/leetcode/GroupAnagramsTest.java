package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class GroupAnagramsTest {
    private static final GroupAnagrams.Solution1 SOLUTION1 = new GroupAnagrams.Solution1();

    private final String[] STRS1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    private final List<List<String>> EXPECTED1 = Arrays.asList(
            Arrays.asList("eat", "tea", "ate"),
            Collections.singletonList("bat"),
            Arrays.asList("tan", "nat")
    );

    private final String[] STRS2 = {""};
    private final List<List<String>> EXPECTED2 = Collections.singletonList(Collections.singletonList(""));

    private final String[] STRS3 = {"a"};
    private final List<List<String>> EXPECTED3 = Collections.singletonList(Collections.singletonList("a"));

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.groupAnagrams(STRS1));
        assertEquals(EXPECTED2, SOLUTION1.groupAnagrams(STRS2));
        assertEquals(EXPECTED3, SOLUTION1.groupAnagrams(STRS3));
    }
}