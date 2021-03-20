package io.binac.leetcode;

import java.util.*;

/**
 * <p>You are given a string <code>s</code> and an array of strings <code>words</code> of <strong>the same length</strong>. Return&nbsp;all starting indices of substring(s) in <code>s</code>&nbsp;that is a concatenation of each word in <code>words</code> <strong>exactly once</strong>, <strong>in any order</strong>,&nbsp;and <strong>without any intervening characters</strong>.</p>
 *
 * <p>You can return the answer in <strong>any order</strong>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "barfoothefoobarman", words = ["foo","bar"]
 * <strong>Output:</strong> [0,9]
 * <strong>Explanation:</strong> Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p><strong>Example 3:</strong></p>
 *
 * <pre><strong>Input:</strong> s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
 * <strong>Output:</strong> [6,9,12]
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
 * 	<li><code>s</code> consists of lower-case English letters.</li>
 * 	<li><code>1 &lt;= words.length &lt;= 5000</code></li>
 * 	<li><code>1 &lt;= words[i].length &lt;= 30</code></li>
 * 	<li><code>words[i]</code>&nbsp;consists of lower-case English letters.</li>
 * </ul>
 */
public class SubstringWithConcatenationOfAllWords {
    public static class Solution1 {
        public List<Integer> findSubstring(String s, String[] words) {
            List<Integer> result = new ArrayList<>();
            final int sl = s.length(), width = words[0].length(), len = width * words.length;
            if (sl < len)
                return result;

            Map<String, Integer> expected = new HashMap<>(), actual = new HashMap<>();
            for (String str : words)
                expected.merge(str, 1, Integer::sum);
            int i = 0, end = sl - width + 1, count = 0;
            while (i < end) {
                String word = s.substring(i, i + width);
                if (expected.getOrDefault(word, 0) >= actual.merge(word, 1, Integer::sum)) {
                    if (++count == words.length) {
                        i -= (count - 1) * width;
                        result.add(i);
                        count = 0;
                        actual.clear();
                        ++i;
                    } else {
                        i += width;
                    }
                } else {
                    actual.clear();
                    i -= count * width - 1;
                    count = 0;
                }
            }
            return result;
        }
    }
}
