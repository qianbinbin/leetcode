#include "FindMedianFromDataStream.h"
#include "gtest/gtest.h"

using namespace lcpp;

TEST(FindMedianFromDataStream, Solution295_1) {
  MedianFinder1 mf;
  mf.addNum(1);
  mf.addNum(2);
  EXPECT_EQ(1.5, mf.findMedian());
  mf.addNum(3);
  EXPECT_EQ(2, mf.findMedian());
}
