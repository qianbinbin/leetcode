package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class TextJustificationTest {
    private static final TextJustification.Solution1 SOLUTION1 = new TextJustification.Solution1();

    private final String[] WORDS1 = {"This", "is", "an", "example", "of", "text", "justification."};
    private final int MAXWIDTH1 = 16;
    private final List<String> EXPECTED1 = Arrays.asList(
            "This    is    an",
            "example  of text",
            "justification.  "
    );

    private final String[] WORDS2 = {"What", "must", "be", "acknowledgment", "shall", "be"};
    private final int MAXWIDTH2 = 16;
    private final List<String> EXPECTED2 = Arrays.asList(
            "What   must   be",
            "acknowledgment  ",
            "shall be        "
    );

    private final String[] WORDS3 = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
            "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    private final int MAXWIDTH3 = 20;
    private final List<String> EXPECTED3 = Arrays.asList(
            "Science  is  what we",
            "understand      well",
            "enough to explain to",
            "a  computer.  Art is",
            "everything  else  we",
            "do                  "
    );

    @Test
    void test1() {
        assertEquals(EXPECTED1, SOLUTION1.fullJustify(WORDS1, MAXWIDTH1));
        assertEquals(EXPECTED2, SOLUTION1.fullJustify(WORDS2, MAXWIDTH2));
        assertEquals(EXPECTED3, SOLUTION1.fullJustify(WORDS3, MAXWIDTH3));
    }
}