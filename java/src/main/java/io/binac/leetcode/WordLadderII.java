package io.binac.leetcode;

import java.util.*;

/**
 * Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
 * <p>
 * <p>Only one letter can be changed at a time
 * <p>Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
 * <p>
 * <p>Note:
 * <p>
 * <p>Return an empty list if there is no such transformation sequence.
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
 *     Output:
 *     [
 *       ["hit","hot","dot","dog","cog"],
 *       ["hit","hot","lot","log","cog"]
 *     ]
 * </blockquote></pre>
 * Example 2:
 * <blockquote><pre>
 *     Input:
 *     beginWord = "hit"
 *     endWord = "cog"
 *     wordList = ["hot","dot","dog","lot","log"]
 *
 *     Output: []
 *
 *     Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 * </blockquote></pre>
 */
public class WordLadderII {
    public static class Solution1 {
        private void addToGraph(Map<String, Set<String>> graph, String parent, String child, boolean flip) {
            if (flip) {
                String p = parent;
                parent = child;
                child = p;
            }
            Set<String> children = graph.computeIfAbsent(parent, k -> new HashSet<>());
            children.add(child);
        }

        private void findLadders(Map<String, Set<String>> tree, String beginWord, String endWord,
                                 List<List<String>> result, List<String> path) {
            if (beginWord.equals(endWord)) {
                result.add(new ArrayList<>(path));
                return;
            }
            Set<String> children = tree.get(beginWord);
            if (children != null) {
                for (String child : children) {
                    path.add(child);
                    findLadders(tree, child, endWord, result, path);
                    path.remove(path.size() - 1);
                }
            }
        }

        public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
            List<List<String>> result = new ArrayList<>();

            Set<String> dict = new HashSet<>(wordList);
            dict.remove(beginWord);
            if (!dict.contains(endWord)) return result;
            dict.remove(endWord);

            Queue<String> queue1 = new LinkedList<>();
            queue1.offer(beginWord);
            Set<String> set1 = new HashSet<>();
            set1.add(beginWord);

            Queue<String> queue2 = new LinkedList<>();
            queue2.offer(endWord);
            Set<String> set2 = new HashSet<>();
            set2.add(endWord);

            Map<String, Set<String>> graph = new HashMap<>();
            boolean flip = false;

            final int width = beginWord.length();

            boolean found = false;
            while (!found && !queue1.isEmpty() && !queue2.isEmpty()) {
                if (queue1.size() > queue2.size()) {
                    Queue<String> q1 = queue1;
                    queue1 = queue2;
                    queue2 = q1;
                    Set<String> s1 = set1;
                    set1 = set2;
                    set2 = s1;
                    flip = !flip;
                }

                dict.removeAll(queue1);
                dict.removeAll(queue2);

                for (int i = queue1.size(); i > 0; --i) {
                    String str = Objects.requireNonNull(queue1.poll());
                    set1.remove(str);
                    char chars[] = str.toCharArray();
                    for (int j = 0; j < width; ++j) {
                        char old = chars[j];
                        for (char ch = 'a'; ch <= 'z'; ++ch) {
                            if (ch == old) continue;
                            chars[j] = ch;
                            String s = new String(chars);
                            if (set2.contains(s)) {
                                if (!found) found = true;
                                addToGraph(graph, str, s, flip);
                            } else if (!found && dict.contains(s)) {
                                if (!set1.contains(s)) {
                                    queue1.offer(s);
                                    set1.add(s);
                                }
                                addToGraph(graph, str, s, flip);
                            }
                        }
                        chars[j] = old;
                    }
                }
            }

            List<String> path = new ArrayList<>();
            path.add(beginWord);
            findLadders(graph, beginWord, endWord, result, path);
            return result;
        }
    }
}
