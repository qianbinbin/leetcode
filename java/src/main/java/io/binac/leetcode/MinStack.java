package io.binac.leetcode;

import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.List;

/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * <p>
 * <p>push(x) -- Push element x onto stack.
 * <p>pop() -- Removes the element on top of the stack.
 * <p>top() -- Get the top element.
 * <p>getMin() -- Retrieve the minimum element in the stack.
 * <p>
 * <p>Example:
 * <blockquote><pre>
 *     MinStack minStack = new MinStack();
 *     minStack.push(-2);
 *     minStack.push(0);
 *     minStack.push(-3);
 *     minStack.getMin();   --> Returns -3.
 *     minStack.pop();
 *     minStack.top();      --> Returns 0.
 *     minStack.getMin();   --> Returns -2.
 * </blockquote></pre>
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
public class MinStack {

    private final List<Integer> data = new ArrayList<>();

    private final List<Integer> min = new ArrayList<>();

    /**
     * initialize your data structure here.
     */
    public MinStack() {

    }

    public void push(int x) {
        data.add(x);
        int size = min.size();
        if (size == 0 || min.get(size - 1) >= x)
            min.add(x);
        else
            min.add(min.get(size - 1));
    }

    public void pop() {
        int size = data.size();
        if (size == 0)
            throw new EmptyStackException();
        data.remove(size - 1);
        min.remove(size - 1);
    }

    public int top() {
        int size = data.size();
        if (size == 0)
            throw new EmptyStackException();
        return data.get(size - 1);
    }

    public int getMin() {
        int size = min.size();
        if (size == 0)
            throw new EmptyStackException();
        return min.get(size - 1);
    }
}
