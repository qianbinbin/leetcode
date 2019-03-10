#include "AddBinary.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(AddBinary, Solution67_1) {
  std::string A1 = "11", B1 = "1";
  const std::string Expected1 = "100";
  EXPECT_EQ(Expected1, Solution67_1().addBinary(A1, B1));

  std::string A2 = "1010", B2 = "1011";
  const std::string Expected2 = "10101";
  EXPECT_EQ(Expected2, Solution67_1().addBinary(A2, B2));
}