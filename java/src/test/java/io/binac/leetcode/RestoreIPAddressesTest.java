package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class RestoreIPAddressesTest {
    private final RestoreIPAddresses.Solution1 solution1 = new RestoreIPAddresses.Solution1();

    private final RestoreIPAddresses.Solution2 solution2 = new RestoreIPAddresses.Solution2();

    @Test
    void test1() {
        List<String> expected = Arrays.asList("255.255.11.135", "255.255.111.35");
        assertEquals(expected, solution1.restoreIpAddresses("25525511135"));
    }

    @Test
    void test2() {
        List<String> expected = Arrays.asList("255.255.11.135", "255.255.111.35");
        assertEquals(expected, solution2.restoreIpAddresses("25525511135"));
    }
}