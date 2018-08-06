package io.binac.leetcode;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MinStackTest {

    private final int x1 = -2, x2 = 0, x3 = -3;

    private final int expected1 = -3, expected2 = 0, expected3 = -2;

    @Test
    void test1() {
        MinStack minStack = new MinStack();
        minStack.push(x1);
        minStack.push(x2);
        minStack.push(x3);
        assertEquals(expected1, minStack.getMin());
        minStack.pop();
        assertEquals(expected2, minStack.top());
        assertEquals(expected3, minStack.getMin());
    }
}