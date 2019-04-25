#include "ImplementTriePrefixTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ImplementTriePrefixTree, Solution208_1) {
  Trie T;
  T.insert("apple");
  EXPECT_TRUE(T.search("apple"));
  EXPECT_FALSE(T.search("app"));
  EXPECT_TRUE(T.startsWith("app"));
  T.insert("app");
  EXPECT_TRUE(T.search("app"));
}