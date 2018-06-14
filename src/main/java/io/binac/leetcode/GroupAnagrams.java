package io.binac.leetcode;

import java.util.*;

/**
 * Given an array of strings, group anagrams together.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 *     Output:
 *     [
 *       ["ate","eat","tea"],
 *       ["nat","tan"],
 *       ["bat"]
 *     ]
 * </blockquote></pre>
 * Note:
 * <p>
 * <p>All inputs will be in lowercase.
 * <p>The order of your output does not matter.
 */
public class GroupAnagrams {
    public static class Solution1 {
        private static class Anagram {
            private final String str;

            private final int count[] = new int[26];

            private final int hashCode;

            public Anagram(String s) {
                str = s;
                for (int i = 0; i < str.length(); ++i)
                    ++count[str.charAt(i) - 'a'];
                hashCode = Arrays.hashCode(count);
            }

            @Override
            public boolean equals(Object obj) {
                if (this == obj) return true;
                if (obj instanceof Anagram)
                    return Arrays.equals(count, ((Anagram) obj).count);
                return false;
            }

            @Override
            public int hashCode() {
                return hashCode;
            }
        }

        public List<List<String>> groupAnagrams(String[] strs) {
            Map<Anagram, List<String>> map = new HashMap<>();
            for (String str : strs) {
                Anagram key = new Anagram(str);
                List<String> list = map.computeIfAbsent(key, k -> new ArrayList<>());
                list.add(str);
            }
            return new ArrayList<>(map.values());
        }
    }
}
