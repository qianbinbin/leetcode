#include "LRUCache.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(LRUCache, Solution146_1) {
  LRUCache Cache(2);
  Cache.put(1, 1);
  Cache.put(2, 2);
  EXPECT_EQ(1, Cache.get(1));
  Cache.put(3, 3);
  EXPECT_EQ(-1, Cache.get(2));
  Cache.put(4, 4);
  EXPECT_EQ(-1, Cache.get(1));
  EXPECT_EQ(3, Cache.get(3));
  EXPECT_EQ(4, Cache.get(4));
}