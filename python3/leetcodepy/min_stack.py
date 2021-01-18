"""
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
"""


class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.__data = []
        self.__min = []
        self.__top = -1

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.__data.append(x)
        self.__min.append(x if self.__top == -1 else min(x, self.__min[self.__top]))
        self.__top += 1

    def pop(self):
        """
        :rtype: void
        """
        if self.__top < 0:
            raise IndexError
        self.__data.pop()
        self.__min.pop()
        self.__top -= 1

    def top(self):
        """
        :rtype: int
        """
        if self.__top < 0:
            raise IndexError
        return self.__data[self.__top]

    def getMin(self):
        """
        :rtype: int
        """
        if self.__top < 0:
            raise IndexError
        return self.__min[self.__top]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
