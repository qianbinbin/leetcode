package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class TextJustificationTest {
    private final TextJustification.Solution1 solution1 = new TextJustification.Solution1();

    @Test
    void test1() {
        String words1[] = {"This", "is", "an", "example", "of", "text", "justification."};
        List<String> expected1 = Arrays.asList(
                "This    is    an",
                "example  of text",
                "justification.  "
        );
        assertEquals(expected1, solution1.fullJustify(words1, 16));

        String words2[] = {"What", "must", "be", "acknowledgment", "shall", "be"};
        List<String> expected2 = Arrays.asList(
                "What   must   be",
                "acknowledgment  ",
                "shall be        "
        );
        assertEquals(expected2, solution1.fullJustify(words2, 16));

        String words3[] = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
                "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
        List<String> expected3 = Arrays.asList(
                "Science  is  what we",
                "understand      well",
                "enough to explain to",
                "a  computer.  Art is",
                "everything  else  we",
                "do                  "
        );
        assertEquals(expected3, solution1.fullJustify(words3, 20));
    }
}