package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class GroupAnagramsTest {
    private final GroupAnagrams.Solution1 solution1 = new GroupAnagrams.Solution1();

    @Test
    void test1() {
        String strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
        List<List<String>> expected = Arrays.asList(
                Arrays.asList("tan", "nat"),
                Collections.singletonList("bat"),
                Arrays.asList("eat", "tea", "ate")
        );
        assertEquals(expected, solution1.groupAnagrams(strs));
    }
}