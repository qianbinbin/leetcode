#include "SerializeAndDeserializeBinaryTree.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(SerializeAndDeserializeBinaryTree, Solution297_1) {
  const auto Root = newTree({1, 2, 3, NTNode, NTNode, 4, 5}),
             Actual = Codec().deserialize(Codec().serialize(Root));
  EXPECT_EQ(*Root, *Actual);
  deleteTree(Root);
  deleteTree(Actual);
}