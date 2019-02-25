#include "ZigZagConversion.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(ZigZagConversion, Solution6_1) {
  std::string S1 = "PAYPALISHIRING";
  const int NumRows1 = 3;
  const std::string Expected1 = "PAHNAPLSIIGYIR";
  EXPECT_EQ(Expected1, Solution6_1().convert(S1, NumRows1));

  std::string S2 = "PAYPALISHIRING";
  const int NumRows2 = 4;
  const std::string Expected2 = "PINALSIGYAHRPI";
  EXPECT_EQ(Expected2, Solution6_1().convert(S2, NumRows2));
}