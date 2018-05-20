package io.binac.leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * <p>Given a string, find the length of the longest substring without repeating characters.
 * <p>
 * <p>Examples:
 * <p>
 * <p>Given "abcabcbb", the answer is "abc", which the length is 3.
 * <p>
 * <p>Given "bbbbb", the answer is "b", with the length of 1.
 * <p>
 * <p>Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
public class LongestSubstringWithoutRepeatingCharacters {
    public static class Solution1 {
        public int lengthOfLongestSubstring(String s) {
            if (s == null || s.isEmpty()) return 0;

            Map<Character, Integer> map = new HashMap<>();
            map.put(s.charAt(0), 0);
            int longest = 1;
            int start = 0;
            for (int i = 1; i < s.length(); ++i) {
                if (map.containsKey(s.charAt(i)) && (int) map.get(s.charAt(i)) >= start) {
                    longest = Math.max(longest, i - start);
                    start = (int) map.get(s.charAt(i)) + 1;
                }
                map.put(s.charAt(i), i);
            }
            longest = Math.max(longest, s.length() - start);
            return longest;
        }
    }
}
