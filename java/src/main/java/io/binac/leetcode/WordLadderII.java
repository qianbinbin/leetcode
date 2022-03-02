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
 * <p>Given two words, <code>beginWord</code> and <code>endWord</code>, and a dictionary <code>wordList</code>, return <em>all the <strong>shortest transformation sequences</strong> from</em> <code>beginWord</code> <em>to</em> <code>endWord</code><em>, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words </em><code>[beginWord, s<sub>1</sub>, s<sub>2</sub>, ..., s<sub>k</sub>]</code>.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input:</strong> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
 * <strong>Output:</strong> [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
 * <strong>Explanation:</strong>&nbsp;There are 2 shortest transformation sequences:
 * "hit" -&gt; "hot" -&gt; "dot" -&gt; "dog" -&gt; "cog"
 * "hit" -&gt; "hot" -&gt; "lot" -&gt; "log" -&gt; "cog"
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 *
 * <pre><strong>Input:</strong> beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
 * <strong>Output:</strong> []
 * <strong>Explanation:</strong> The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= beginWord.length &lt;= 5</code></li>
 * 	<li><code>endWord.length == beginWord.length</code></li>
 * 	<li><code>1 &lt;= wordList.length &lt;= 1000</code></li>
 * 	<li><code>wordList[i].length == beginWord.length</code></li>
 * 	<li><code>beginWord</code>, <code>endWord</code>, and <code>wordList[i]</code> consist of lowercase English letters.</li>
 * 	<li><code>beginWord != endWord</code></li>
 * 	<li>All the words in <code>wordList</code> are <strong>unique</strong>.</li>
 * </ul>
 */
public class WordLadderII {
    public static class Solution1 {
        private void addToGraph(Map<String, Set<String>> graph, String parent, String child, boolean reverse) {
            if (reverse) {
                String t = parent;
                parent = child;
                child = t;
            }
            Set<String> children = graph.computeIfAbsent(parent, k -> new HashSet<>());
            children.add(child);
        }

        private void findLadders(Map<String, Set<String>> tree, String begin, String end,
                                 List<List<String>> result, List<String> path) {
            if (begin.equals(end)) {
                result.add(new ArrayList<>(path));
                return;
            }
            Set<String> children = tree.get(begin);
            if (children == null)
                return;
            for (String child : children) {
                path.add(child);
                findLadders(tree, child, end, result, path);
                path.remove(path.size() - 1);
            }
        }

        public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
            List<List<String>> result = new ArrayList<>();

            Set<String> dict = new HashSet<>(wordList);
            dict.remove(beginWord);
            if (!dict.remove(endWord)) return result;
            dict.remove(beginWord);

            Set<String> set1 = new HashSet<>();
            set1.add(beginWord);
            Set<String> set2 = new HashSet<>();
            set2.add(endWord);
            Set<String> next = new HashSet<>();

            Map<String, Set<String>> graph = new HashMap<>();
            boolean reverse = false;

            final int width = beginWord.length();

            boolean found = false;
            while (!found && !set1.isEmpty() && !set2.isEmpty()) {
                if (set1.size() > set2.size()) {
                    Set<String> s = set1;
                    set1 = set2;
                    set2 = s;
                    reverse = !reverse;
                }

                for (String str : set1) {
                    char[] chars = str.toCharArray();
                    for (int j = 0; j < width; ++j) {
                        char origin = chars[j];
                        for (char ch = 'a'; ch <= 'z'; ++ch) {
                            if (ch == origin) continue;
                            chars[j] = ch;
                            String s = String.valueOf(chars);
                            if (set2.contains(s)) {
                                found = true;
                                addToGraph(graph, str, s, reverse);
                            } else if (!found && dict.contains(s)) {
                                next.add(s);
                                addToGraph(graph, str, s, reverse);
                            }
                        }
                        chars[j] = origin;
                    }
                }
                dict.removeAll(next);
                {
                    Set<String> s = set1;
                    set1 = next;
                    next = s;
                    next.clear();
                }
            }

            if (!found)
                return result;
            List<String> path = new ArrayList<>();
            path.add(beginWord);
            findLadders(graph, beginWord, endWord, result, path);
            return result;
        }
    }
}
