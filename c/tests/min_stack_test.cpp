#include <gtest/gtest.h>

extern "C" {
#include "min_stack.h"
}

TEST(min_stack_test, min_stack) {
    MinStack *stack = minStackCreate(16);
    minStackPush(stack, -2);
    minStackPush(stack, 0);
    minStackPush(stack, -3);
    EXPECT_EQ(minStackGetMin(stack), -3);
    minStackPop(stack);
    EXPECT_EQ(minStackTop(stack), 0);
    EXPECT_EQ(minStackGetMin(stack), -2);
    minStackFree(stack);
}
