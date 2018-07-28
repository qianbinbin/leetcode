package io.binac.leetcode;

/**
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
 * <p>
 * <p>get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * <p>put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 * <p>
 * <p>Follow up:
 * <p>Could you do both operations in O(1) time complexity?
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     LRUCache cache = new LRUCache( 2 capacity );
 *
 *     cache.put(1,1);
 *     cache.put(2,2);
 *     cache.get(1);       // returns 1
 *     cache.put(3,3);    // evicts key 2
 *     cache.get(2);       // returns -1 (not found)
 *     cache.put(4,4);    // evicts key 1
 *     cache.get(1);       // returns -1 (not found)
 *     cache.get(3);       // returns 3
 *     cache.get(4);       // returns 4
 * </blockquote></pre>
 * Your LRUCache object will be instantiated and called as such:
 * <blockquote><pre>
 *     LRUCache obj = new LRUCache(capacity);
 *     int param_1 = obj.get(key);
 *     obj.put(key,value);
 * </blockquote></pre>
 */
public class LRUCache {

    private static class Entry {
        int key;
        int value;
        Entry next;
        Node node;

        Entry(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    private static class Node {
        int key;
        Node prev;
        Node next;

        Node(int key) {
            this.key = key;
        }
    }

    private final int capacity;

    private int size;

    private final Entry table[];

    private Node head;

    private Node tail;

    public LRUCache(int capacity) {
        if (capacity <= 0)
            throw new IllegalArgumentException("capacity must be positive: " + capacity);
        this.capacity = capacity;
        table = new Entry[tableSize(capacity)];
        head = new Node(0);
        tail = new Node(0);
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
        Entry e = table[i];
        while (e != null) {
            if (e.key == key) {
                reorderNode(e.node);
                return e.value;
            }
            e = e.next;
        }
        return -1;
    }

    public void put(int key, int value) {
        if (value <= 0)
            throw new IllegalArgumentException("value must be positive: " + value);
        int i = key & (table.length - 1);
        Entry e = table[i];
        while (e != null) {
            if (e.key == key) {
                e.value = value;
                reorderNode(e.node);
                return;
            }
            e = e.next;
        }

        e = new Entry(key, value);
        e.node = addFirstNode(key);
        if (table[i] == null) {
            table[i] = e;
        } else {
            e.next = table[i].next;
            table[i].next = e;
        }
        if (++size > capacity) {
            remove(tail.prev.key);
            removeLastNode();
        }
    }

    private void remove(int key) {
        int i = key & (table.length - 1);
        Entry e = table[i];
        if (e == null)
            return;
        if (e.key == key) {
            table[i] = e.next;
            --size;
            return;
        }
        Entry pre = table[i];
        e = pre.next;
        while (e != null) {
            if (e.key == key) {
                pre.next = e.next;
                --size;
                return;
            }
            pre = e;
            e = e.next;
        }
    }

    private Node addFirstNode(int key) {
        Node node = new Node(key), nx = head.next;
        node.next = nx;
        node.prev = head;
        nx.prev = node;
        head.next = node;
        return node;
    }

    private void reorderNode(Node node) {
        if (node.prev == head) return;

        node.prev.next = node.next;
        node.next.prev = node.prev;
        Node nx = head.next;
        node.next = nx;
        node.prev = head;
        nx.prev = node;
        head.next = node;
    }

    private void removeLastNode() {
        Node pre = tail.prev.prev;
        pre.next = tail;
        tail.prev = pre;
    }
}
