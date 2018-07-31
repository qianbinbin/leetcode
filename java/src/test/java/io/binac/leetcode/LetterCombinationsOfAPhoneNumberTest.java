package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class LetterCombinationsOfAPhoneNumberTest {
    private final LetterCombinationsOfAPhoneNumber.Solution1 solution1 = new LetterCombinationsOfAPhoneNumber.Solution1();

    @Test
    void test1() {
        List<String> expected = Arrays.asList("ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf");
        assertEquals(expected, solution1.letterCombinations("23"));
    }
}