"""
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.



Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Constraints:

1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put.
"""
from typing import List


class LRUCache:
    class Entry:
        def __init__(self, key, value, _next=None, node=None):
            self.key = key
            self.value = value
            self.next = _next
            self.node = node

    class Node:
        def __init__(self, key: int = 0, prev=None, _next=None):
            self.key = key
            self.prev = prev
            self.next = _next

    def __init__(self, capacity: int):
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
        head, tail = self.Node(), self.Node()
        head.next = tail
        tail.prev = head
        self.__head, self.__tail = head, tail
        self.__dummy = self.Entry(0, 0)

    def get(self, key: int) -> int:
        entry = self.__table[key & (len(self.__table) - 1)]
        while entry is not None:
            if entry.key == key:
                self.__reorder_node(entry.node)
                return entry.value
            entry = entry.next
        return -1

    def put(self, key: int, value: int) -> None:
        i = key & (len(self.__table) - 1)
        entry = self.__table[i]
        while entry is not None:
            if entry.key == key:
                entry.value = value
                self.__reorder_node(entry.node)
                return
            entry = entry.next

        node = self.Node(key, self.__head, self.__head.next)
        self.__head.next.prev = node
        self.__head.next = node
        self.__table[i] = self.Entry(key, value, self.__table[i], node)
        self.__size += 1
        if self.__size > self.__CAPACITY:
            self.__pop()

    def __pop(self):
        node = self.__tail.prev
        node.prev.next = self.__tail
        self.__tail.prev = node.prev
        i = node.key & (len(self.__table) - 1)
        self.__dummy.next = self.__table[i]
        entry = self.__dummy
        while entry.next.key != node.key:
            entry = entry.next
        entry.next = entry.next.next
        self.__table[i] = self.__dummy.next
        self.__size -= 1

    def __reorder_node(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        node.next = self.__head.next
        node.prev = self.__head
        self.__head.next.prev = node
        self.__head.next = node
