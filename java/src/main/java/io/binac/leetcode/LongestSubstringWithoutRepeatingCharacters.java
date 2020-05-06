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
            final int length = s.length();
            if (length < 1)
                return 0;
            Map<Character, Integer> map = new HashMap<>();
            map.put(s.charAt(0), 0);
            int start = 0, longest = 1;
            Integer i;
            for (int j = 1; j < length; ++j) {
                i = map.put(s.charAt(j), j);
                if (i != null && i >= start) {
                    longest = Math.max(longest, j - start);
                    start = i + 1;
                }
            }
            longest = Math.max(longest, length - start);
            return longest;
        }
    }
}
