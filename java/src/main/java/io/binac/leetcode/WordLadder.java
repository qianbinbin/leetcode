package io.binac.leetcode;

import java.util.*;

/**
 * Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
 * <p>
 * <p>Only one letter can be changed at a time.
 * <p>Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 * <p>
 * <p>Note:
 * <p>
 * <p>Return 0 if there is no such transformation sequence.
 * <p>All words have the same length.
 * <p>All words contain only lowercase alphabetic characters.
 * <p>You may assume no duplicates in the word list.
 * <p>You may assume beginWord and endWord are non-empty and are not the same.
 * <p>
 * <p>Example 1:
 * <blockquote><pre>
 *     Input:
 *     beginWord = "hit",
 *     endWord = "cog",
 *     wordList = ["hot","dot","dog","lot","log","cog"]
 *
 *     Output: 5
 *
 *     Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 *     return its length 5.
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input:
 *     beginWord = "hit"
 *     endWord = "cog"
 *     wordList = ["hot","dot","dog","lot","log"]
 *
 *     Output: 0
 *
 *     Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 * </blockquote></pre>
 */
public class WordLadder {
    public static class Solution1 {
        public int ladderLength(String beginWord, String endWord, List<String> wordList) {
            Set<String> dict = new HashSet<>(wordList);
            if (!dict.contains(endWord)) return 0;

            Queue<String> queue1 = new LinkedList<>();
            queue1.offer(beginWord);
            Set<String> set1 = new HashSet<>();
            set1.add(beginWord);

            Queue<String> queue2 = new LinkedList<>();
            queue2.offer(endWord);
            Set<String> set2 = new HashSet<>();
            set2.add(endWord);

            final int width = beginWord.length();

            int depth = 0;
            while (!queue1.isEmpty() && !queue2.isEmpty()) {
                if (queue1.size() > queue2.size()) {
                    Queue<String> q1 = queue1;
                    queue1 = queue2;
                    queue2 = q1;
                    Set<String> s1 = set1;
                    set1 = set2;
                    set2 = s1;
                }
                dict.removeAll(queue1);
                dict.removeAll(queue2);

                ++depth;
                for (int i = queue1.size(); i > 0; --i) {
                    String str = Objects.requireNonNull(queue1.poll());
                    set1.remove(str);
                    char chars[] = str.toCharArray();
                    for (int j = 0; j < width; ++j) {
                        char origin = chars[j];
                        for (char ch = 'a'; ch <= 'z'; ++ch) {
                            if (ch == origin) continue;
                            chars[j] = ch;
                            String s = new String(chars);
                            if (set2.contains(s)) {
                                return depth + 1;
                            } else if (dict.contains(s) && !set1.contains(s)) {
                                queue1.offer(s);
                                set1.add(s);
                            }
                        }
                        chars[j] = origin;
                    }
                }
            }
            return 0;
        }
    }
}
