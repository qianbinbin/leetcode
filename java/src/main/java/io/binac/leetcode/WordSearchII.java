package io.binac.leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>Given an <code>m x n</code> <code>board</code>&nbsp;of characters and a list of strings <code>words</code>, return <em>all words on the board</em>.</p>
 *
 * <p>Each word must be constructed from letters of sequentially adjacent cells, where <strong>adjacent cells</strong> are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/07/search1.jpg" style="width: 322px; height: 322px;">
 * <pre><strong>Input:</strong> board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
 * <strong>Output:</strong> ["eat","oath"]
 * </pre>
 *
 * <p><strong>Example 2:</strong></p>
 * <img alt="" src="https://assets.leetcode.com/uploads/2020/11/07/search2.jpg" style="width: 162px; height: 162px;">
 * <pre><strong>Input:</strong> board = [["a","b"],["c","d"]], words = ["abcb"]
 * <strong>Output:</strong> []
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>m == board.length</code></li>
 * 	<li><code>n == board[i].length</code></li>
 * 	<li><code>1 &lt;= m, n &lt;= 12</code></li>
 * 	<li><code>board[i][j]</code> is a lowercase English letter.</li>
 * 	<li><code>1 &lt;= words.length &lt;= 3 * 10<sup>4</sup></code></li>
 * 	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
 * 	<li><code>words[i]</code> consists of lowercase English letters.</li>
 * 	<li>All the strings of <code>words</code> are unique.</li>
 * </ul>
 */
public class WordSearchII {
    public static class Solution1 {
        private static class TrieNode {
            boolean terminal;
            TrieNode[] children = new TrieNode[26];
        }

        private void insertTrie(TrieNode root, String word) {
            TrieNode node = root;
            for (int i = 0, e = word.length(), j; i < e; ++i) {
                j = word.charAt(i) - 'a';
                if (node.children[j] == null)
                    node.children[j] = new TrieNode();
                node = node.children[j];
            }
            node.terminal = true;
        }

        private void findWords(char[][] board, int m, int n, int i, int j,
                               TrieNode node, StringBuilder path, List<String> result) {
            if (node.terminal) {
                node.terminal = false;
                result.add(path.toString());
            }
            final char ch;
            if (i < 0 || i >= m || j < 0 || j >= n || (ch = board[i][j]) == '#')
                return;
            if ((node = node.children[ch - 'a']) == null)
                return;
            path.append(ch);
            board[i][j] = '#';
            findWords(board, m, n, i + 1, j, node, path, result);
            findWords(board, m, n, i - 1, j, node, path, result);
            findWords(board, m, n, i, j + 1, node, path, result);
            findWords(board, m, n, i, j - 1, node, path, result);
            path.deleteCharAt(path.length() - 1);
            board[i][j] = ch;
        }

        public List<String> findWords(char[][] board, String[] words) {
            TrieNode root = new TrieNode();
            for (String word : words)
                insertTrie(root, word);
            List<String> result = new ArrayList<>();
            final int m = board.length, n = board[0].length;
            for (int i = 0, j; i < m; ++i) {
                for (j = 0; j < n; ++j)
                    findWords(board, m, n, i, j, root, new StringBuilder(), result);
            }
            return result;
        }
    }
}
