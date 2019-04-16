#include "ImplementQueueUsingStacks.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ImplementQueueUsingStacks, Solution232_1) {
  MyQueue Q;
  Q.push(1);
  Q.push(2);
  EXPECT_EQ(1, Q.peek());
  EXPECT_EQ(1, Q.pop());
  EXPECT_FALSE(Q.empty());
}