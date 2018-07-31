package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
 * <p>
 * <p>You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
 * <p>
 * <p>Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 * <p>
 * <p>For the last line of text, it should be left justified and no extra space is inserted between words.
 * <p>
 * <p>Note:
 * <p>
 * <p>A word is defined as a character sequence consisting of non-space characters only.
 * <p>Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
 * <p>The input array words contains at least one word.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:
 *     words = ["This", "is", "an", "example", "of", "text", "justification."]
 *     maxWidth = 16
 *     Output:
 *     [
 *        "This    is    an",
 *        "example  of text",
 *        "justification.  "
 *     ]
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input:
 *     words = ["What","must","be","acknowledgment","shall","be"]
 *     maxWidth = 16
 *     Output:
 *     [
 *       "What   must   be",
 *       "acknowledgment  ",
 *       "shall be        "
 *     ]
 *     Explanation: Note that the last line is "shall be    " instead of "shall     be",
 *                  because the last line must be left-justified instead of fully-justified.
 *                  Note that the second line is also left-justified becase it contains only one word.
 * </blockquote></pre>
 * Example 3:
 * <blockquote><pre>
 *     Input:
 *     words = ["Science","is","what","we","understand","well","enough","to","explain",
 *              "to","a","computer.","Art","is","everything","else","we","do"]
 *     maxWidth = 20
 *     Output:
 *     [
 *       "Science  is  what we",
 *       "understand      well",
 *       "enough to explain to",
 *       "a  computer.  Art is",
 *       "everything  else  we",
 *       "do                  "
 *     ]
 * </blockquote></pre>
 */
public class TextJustification {
    public static class Solution1 {
        private void appendSpace(StringBuilder sb, int count) {
            for (; count > 0; --count)
                sb.append(' ');
        }

        public List<String> fullJustify(String[] words, int maxWidth) {
            if (maxWidth <= 0)
                throw new IllegalArgumentException("maxWidth must be positive");
            if (words.length == 0)
                throw new IllegalArgumentException("words must contain at least one word");
            List<String> result = new ArrayList<>();
            int i = 0;
            while (i < words.length) {
                int start = i, len = words[i].length(), count = 1;
                while (i + 1 < words.length && len + words[i + 1].length() + count <= maxWidth) {
                    len += words[++i].length();
                    ++count;
                }
                StringBuilder sb = new StringBuilder();
                if (i < words.length - 1) {
                    int space = maxWidth - len;
                    final int quotient = count == 1 ? space : space / (count - 1);
                    int remainder = count == 1 ? 0 : space % (count - 1);
                    sb.append(words[start]);
                    for (int j = start + 1; j <= i; ++j) {
                        appendSpace(sb, quotient);
                        if (remainder > 0) {
                            sb.append(' ');
                            --remainder;
                        }
                        sb.append(words[j]);
                    }
                } else {
                    sb.append(words[start]);
                    for (int j = start + 1; j <= i; ++j) {
                        sb.append(' ');
                        sb.append(words[j]);
                    }
                }
                appendSpace(sb, maxWidth - sb.length());
                result.add(sb.toString());
                ++i;
            }
            return result;
        }
    }
}
