package io.binac.leetcode;

/**
 * <p>A <a href="https://en.wikipedia.org/wiki/Trie" target="_blank"><strong>trie</strong></a> (pronounced as "try") or <strong>prefix tree</strong> is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.</p>
 *
 * <p>Implement the Trie class:</p>
 *
 * <ul>
 * 	<li><code>Trie()</code> Initializes the trie object.</li>
 * 	<li><code>void insert(String word)</code> Inserts the string <code>word</code> into the trie.</li>
 * 	<li><code>boolean search(String word)</code> Returns <code>true</code> if the string <code>word</code> is in the trie (i.e., was inserted before), and <code>false</code> otherwise.</li>
 * 	<li><code>boolean startsWith(String prefix)</code> Returns <code>true</code> if there is a previously inserted string <code>word</code> that has the prefix <code>prefix</code>, and <code>false</code> otherwise.</li>
 * </ul>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input</strong>
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * <strong>Output</strong>
 * [null, null, true, false, true, null, true]
 *
 * <strong>Explanation</strong>
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= word.length, prefix.length &lt;= 2000</code></li>
 * 	<li><code>word</code> and <code>prefix</code> consist only of lowercase English letters.</li>
 * 	<li>At most <code>3 * 10<sup>4</sup></code> calls <strong>in total</strong> will be made to <code>insert</code>, <code>search</code>, and <code>startsWith</code>.</li>
 * </ul>
 */
public class ImplementTriePrefixTree {
    public static class Trie {
        private static class Node {
            boolean terminal;
            final Node[] children = new Node[26];
        }

        private final Node root = new Node();

        public Trie() {
        }

        public void insert(String word) {
            Node node = root;
            for (int i = 0, e = word.length(), j; i < e; ++i) {
                j = word.charAt(i) - 'a';
                if (node.children[j] == null)
                    node.children[j] = new Node();
                node = node.children[j];
            }
            node.terminal = true;
        }

        public boolean search(String word) {
            Node node = root;
            for (int i = 0, e = word.length(), j; i < e; ++i) {
                j = word.charAt(i) - 'a';
                if (node.children[j] == null)
                    return false;
                node = node.children[j];
            }
            return node.terminal;
        }

        public boolean startsWith(String prefix) {
            Node node = root;
            for (int i = 0, e = prefix.length(), j; i < e; ++i) {
                j = prefix.charAt(i) - 'a';
                if (node.children[j] == null)
                    return false;
                node = node.children[j];
            }
            return true;
        }
    }
}
