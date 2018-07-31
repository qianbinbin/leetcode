package io.binac.leetcode;

import java.util.*;

/**
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:
 *       s = "barfoothefoobarman",
 *       words = ["foo","bar"]
 *     Output: [0,9]
 *     Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
 *     The output order does not matter, returning [9,0] is fine too.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input:
 *       s = "wordgoodstudentgoodword",
 *       words = ["word","student"]
 *     Output: []
 * </blockquote></pre>
 */
public class SubstringWithConcatenationOfAllWords {
    public static class Solution1 {
        private static class Counter<K> {
            private static class Int {
                int value;

                public Int(int val) {
                    this.value = val;
                }
            }

            private final Map<K, Int> map;

            public Counter() {
                map = new HashMap<>();
            }

            public Counter(int initialCapacity) {
                map = new HashMap<>(initialCapacity);
            }

            public int increase(K key) {
                Int count = new Int(1);
                Int old = map.put(key, count);
                if (old != null) {
                    count.value = old.value + 1;
                    return old.value;
                }
                return 0;
            }

            public int decrease(K key) {
                Int count = new Int(-1);
                Int old = map.put(key, count);
                if (old != null) {
                    count.value = old.value - 1;
                    return old.value;
                }
                return 0;
            }

            public int get(Object key) {
                Int count = map.get(key);
                return (count == null) ? 0 : count.value;
            }

            public int set(K key, int count) {
                Int old = map.put(key, new Int(count));
                if (old != null)
                    return old.value;
                return 0;
            }
        }

        public List<Integer> findSubstring(String s, String[] words) {
            final int len = s.length();
            if (len == 0 || words.length == 0)
                return Collections.emptyList();
            final int width = words[0].length();
            if (width == 0)
                return Collections.emptyList();

            Counter<String> counter = new Counter<>(words.length);
            for (String word : words)
                counter.increase(word);

            List<Integer> result = new ArrayList<>();
            final int end = len - width * words.length;
            for (int i = 0; i <= end; ++i) {
                Counter<String> exist = new Counter<>(words.length);
                int count = 0;
                final int jEnd = i + width * words.length;
                for (int j = i; j < jEnd; j += width) {
                    String word = s.substring(j, j + width);
                    int max = counter.get(word);
                    if (max == 0) break;
                    int old = exist.increase(word);
                    if (old >= max) break;
                    ++count;
                }
                if (count == words.length)
                    result.add(i);
            }
            return result;
        }
    }
}
