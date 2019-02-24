#include "MinStack.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(MinStack, Solution155_1) {
  MinStack MStack;
  MStack.push(-2);
  MStack.push(0);
  MStack.push(-3);
  EXPECT_EQ(-3, MStack.getMin());
  MStack.pop();
  EXPECT_EQ(0, MStack.top());
  EXPECT_EQ(-2, MStack.getMin());
}