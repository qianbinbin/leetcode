package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class RestoreIPAddressesTest {
    private static final RestoreIPAddresses.Solution1 SOLUTION1 = new RestoreIPAddresses.Solution1();
    private static final RestoreIPAddresses.Solution2 SOLUTION2 = new RestoreIPAddresses.Solution2();

    private final String S1 = "25525511135";
    private final List<String> EXPECTED1 = Arrays.asList("255.255.11.135", "255.255.111.35");

    private final String S2 = "0000";
    private final List<String> EXPECTED2 = Collections.singletonList("0.0.0.0");

    private final String S3 = "101023";
    private final List<String> EXPECTED3 = Arrays.asList("1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3");


    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.restoreIpAddresses(S1));
        assertEquals(EXPECTED2, SOLUTION1.restoreIpAddresses(S2));
        assertEquals(EXPECTED3, SOLUTION1.restoreIpAddresses(S3));
    }

    @Test
    void test2() {
        assertEquals(EXPECTED1, SOLUTION2.restoreIpAddresses(S1));
        assertEquals(EXPECTED2, SOLUTION2.restoreIpAddresses(S2));
        assertEquals(EXPECTED3, SOLUTION2.restoreIpAddresses(S3));
    }
}