package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class LetterCombinationsOfAPhoneNumberTest {
    private static final LetterCombinationsOfAPhoneNumber.Solution1 SOLUTION1 = new LetterCombinationsOfAPhoneNumber.Solution1();

    private final String DIGITS1 = "23";
    private final List<String> EXPECTED1 = Arrays.asList("ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf");

    private final String DIGITS2 = "";
    private final List<String> EXPECTED2 = Collections.emptyList();

    private final String DIGITS3 = "2";
    private final List<String> EXPECTED3 = Arrays.asList("a", "b", "c");

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.letterCombinations(DIGITS1));
        assertEquals(EXPECTED2, SOLUTION1.letterCombinations(DIGITS2));
        assertEquals(EXPECTED3, SOLUTION1.letterCombinations(DIGITS3));
    }
}