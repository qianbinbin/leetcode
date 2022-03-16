package io.binac.leetcode;

/**
 * <p>Design a data structure that follows the constraints of a <strong><a href="https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU" target="_blank">Least Recently Used (LRU) cache</a></strong>.</p>
 *
 * <p>Implement the <code>LRUCache</code> class:</p>
 *
 * <ul>
 * 	<li><code>LRUCache(int capacity)</code> Initialize the LRU cache with <strong>positive</strong> size <code>capacity</code>.</li>
 * 	<li><code>int get(int key)</code> Return the value of the <code>key</code> if the key exists, otherwise return <code>-1</code>.</li>
 * 	<li><code>void put(int key, int value)</code>&nbsp;Update the value of the <code>key</code> if the <code>key</code> exists. Otherwise, add the <code>key-value</code> pair to the cache. If the number of keys exceeds the <code>capacity</code> from this operation, <strong>evict</strong> the least recently used key.</li>
 * </ul>
 *
 * <p>The functions&nbsp;<code data-stringify-type="code">get</code>&nbsp;and&nbsp;<code data-stringify-type="code">put</code>&nbsp;must each run in <code>O(1)</code> average time complexity.</p>
 *
 * <p>&nbsp;</p>
 * <p><strong>Example 1:</strong></p>
 *
 * <pre><strong>Input</strong>
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * <strong>Output</strong>
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * <strong>Explanation</strong>
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 * </pre>
 *
 * <p>&nbsp;</p>
 * <p><strong>Constraints:</strong></p>
 *
 * <ul>
 * 	<li><code>1 &lt;= capacity &lt;= 3000</code></li>
 * 	<li><code>0 &lt;= key &lt;= 10<sup>4</sup></code></li>
 * 	<li><code>0 &lt;= value &lt;= 10<sup>5</sup></code></li>
 * 	<li>At most 2<code>&nbsp;* 10<sup>5</sup></code>&nbsp;calls will be made to <code>get</code> and <code>put</code>.</li>
 * </ul>
 */
public class LRUCache {
    private static class Entry {
        int key;
        int value;
        Entry next;
        Node node;

        Entry() {
        }

        Entry(int key, int value, Entry next, Node node) {
            this.key = key;
            this.value = value;
            this.next = next;
            this.node = node;
        }
    }

    private static class Node {
        int key;
        Node prev;
        Node next;

        Node() {
        }

        Node(int key, Node prev, Node next) {
            this.key = key;
            this.prev = prev;
            this.next = next;
        }
    }

    private final int capacity;

    private int size;

    private final Entry[] table;

    private final Entry dummy = new Entry();

    private final Node head;

    private final Node tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        table = new Entry[tableSize(capacity)];
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.prev = head;
    }

    private int tableSize(int cap) {
        int n = cap - 1;
        n |= n >>> 1;
        n |= n >>> 2;
        n |= n >>> 4;
        n |= n >>> 8;
        n |= n >>> 16;
        return n + 1;
    }

    public int get(int key) {
        int i = key & (table.length - 1);
        for (Entry e = table[i]; e != null; e = e.next) {
            if (e.key != key)
                continue;
            reorderNode(e.node);
            return e.value;
        }
        return -1;
    }

    public void put(int key, int value) {
        int i = key & (table.length - 1);
        for (Entry e = table[i]; e != null; e = e.next) {
            if (e.key != key)
                continue;
            e.value = value;
            reorderNode(e.node);
            return;
        }

        Node node = new Node(key, head, head.next);
        head.next.prev = node;
        head.next = node;
        table[i] = new Entry(key, value, table[i], node);
        if (++size > capacity)
            pop();
    }

    private void pop() {
        Node node = tail.prev;
        node.prev.next = tail;
        tail.prev = node.prev;
        int i = node.key & (table.length - 1);
        dummy.next = table[i];
        Entry e = dummy;
        while (e.next.key != node.key)
            e = e.next;
        e.next = e.next.next;
        table[i] = dummy.next;
        --size;
    }

    private void reorderNode(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
    }
}
