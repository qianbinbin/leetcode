package io.binac.leetcode;

import java.util.*;

/**
 * <p>A <strong>transformation sequence</strong> from word <code>beginWord</code> to word <code>endWord</code> using a dictionary <code>wordList</code> is a sequence of words <code>beginWord -&gt; s<sub>1</sub> -&gt; s<sub>2</sub> -&gt; ... -&gt; s<sub>k</sub></code> such that:</p>
 *
 * <ul>
 * 	<li>Every adjacent pair of words differs by a single letter.</li>
 * 	<li>Every <code>s<sub>i</sub></code> for <code>1 &lt;= i &lt;= k</code> is in <code>wordList</code>. Note that <code>beginWord</code> does not need to be in <code>wordList</code>.</li>
 * 	<li><code>s<sub>k</sub> == endWord</code></li>
 * </ul>
 *
 * <p>Given two words, <code>beginWord</code> and <code>endWord</code>, and a dictionary <code>wordList</code>, return <em>the <strong>number of words</strong> in the <strong>shortest transformation sequence</strong> from</em> <code>beginWord</code> <em>to</em> <code>endWord</code><em>, or </em><code>0</code><em> if no such sequence exists.</em></p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
 * <strong>Output:</strong> 5
 * <strong>Explanation:</strong> One shortest transformation sequence is "hit" -&gt; "hot" -&gt; "dot" -&gt; "dog" -&gt; cog", which is 5 words long.
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
 * <strong>Output:</strong> 0
 * <strong>Explanation:</strong> The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= beginWord.length &lt;= 10</code></li>
 * 	<li><code>endWord.length == beginWord.length</code></li>
 * 	<li><code>1 &lt;= wordList.length &lt;= 5000</code></li>
 * 	<li><code>wordList[i].length == beginWord.length</code></li>
 * 	<li><code>beginWord</code>, <code>endWord</code>, and <code>wordList[i]</code> consist of lowercase English letters.</li>
 * 	<li><code>beginWord != endWord</code></li>
 * 	<li>All the words in <code>wordList</code> are <strong>unique</strong>.</li>
 * </ul>
 */
public class WordLadder {
    public static class Solution1 {
        public int ladderLength(String beginWord, String endWord, List<String> wordList) {
            Set<String> dict = new HashSet<>(wordList);
            if (!dict.remove(endWord))
                return 0;
            dict.remove(beginWord);
            final int width = beginWord.length();

            Set<String> set1 = new HashSet<>();
            set1.add(beginWord);
            Set<String> set2 = new HashSet<>();
            set2.add(endWord);
            Set<String> next = new HashSet<>();

            int depth = 1;
            while (!set1.isEmpty() && !set2.isEmpty()) {
                if (set1.size() > set2.size()) {
                    Set<String> t = set1;
                    set1 = set2;
                    set2 = t;
                }
                ++depth;
                for (String str : set1) {
                    char[] chars = str.toCharArray();
                    for (int j = 0; j < width; ++j) {
                        char origin = chars[j];
                        for (char ch = 'a'; ch <= 'z'; ++ch) {
                            if (ch == origin) continue;
                            chars[j] = ch;
                            String s = String.valueOf(chars);
                            if (set2.contains(s))
                                return depth;
                            if (dict.remove(s))
                                next.add(s);
                        }
                        chars[j] = origin;
                    }
                }
                {
                    Set<String> t = set1;
                    set1 = next;
                    next = t;
                    next.clear();
                }
            }
            return 0;
        }
    }
}
