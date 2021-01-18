"""
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
"""


class LRUCache:
    class Entry:
        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.next = None
            self.node = None

    class Node:
        def __init__(self, key):
            self.key = key
            self.prev = None
            self.next = None

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        if capacity <= 0 or capacity > 0x7fffffff:
            raise ValueError
        self.__size = 0
        self.__CAPACITY = capacity
        capacity -= 1
        capacity |= capacity >> 1
        capacity |= capacity >> 2
        capacity |= capacity >> 4
        capacity |= capacity >> 8
        capacity |= capacity >> 16
        capacity += 1
        self.__table = [None] * capacity
        head, tail = self.Node(0), self.Node(0)
        head.next = tail
        tail.prev = head
        self.__head, self.__tail = head, tail

    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        entry = self.__table[key & (len(self.__table) - 1)]
        while entry is not None:
            if entry.key == key:
                self.__reorder_node(entry.node)
                return entry.value
            entry = entry.next
        # raise KeyError
        return -1

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        table = self.__table
        i = key & (len(table) - 1)
        entry = table[i]
        while entry is not None:
            if entry.key == key:
                entry.value = value
                self.__reorder_node(entry.node)
                return
            entry = entry.next
        if self.__size >= self.__CAPACITY:
            self.remove(self.__tail.prev.key)
        entry = self.Entry(key, value)
        entry.node = self.__add_first_node(key)
        if table[i] is None:
            table[i] = entry
        else:
            entry.next = table[i].next
            table[i].next = entry
        self.__size += 1

    def remove(self, key):
        table = self.__table
        i = key & (len(table) - 1)
        if table[i] is None:
            return
        if table[i].key == key:
            self.__remove_last_node()
            table[i] = table[i].next
            self.__size -= 1
            return
        pre, entry = table[i], table[i].next
        while entry is not None:
            if entry.key == key:
                pre.next = entry.next
                self.__remove_last_node()
                self.__size -= 1
                return
            pre = entry
            entry = entry.next

    def __add_first_node(self, key):
        head, nex = self.__head, self.__head.next
        node = self.Node(key)
        node.prev = head
        node.next = nex
        head.next = node
        nex.prev = node
        return node

    def __reorder_node(self, node):
        pre, nex, head = node.prev, node.next, self.__head
        pre.next = nex
        nex.prev = pre
        node.next = head.next
        node.prev = head
        node.next.prev = node
        head.next = node

    def __remove_last_node(self):
        node = self.__tail.prev
        pre, nex = node.prev, node.next
        pre.next = nex
        nex.prev = pre

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
