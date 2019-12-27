// Median is the middle value in an ordered integer list. If the size of the
// list is even, there is no middle value. So the median is the mean of the two
// middle value.
//
// For example,
// [2,3,4], the median is 3
//
// [2,3], the median is (2 + 3) / 2 = 2.5
//
// Design a data structure that supports the following two operations:
//
// void addNum(int num) - Add a integer number from the data stream to the data
// structure. double findMedian() - Return the median of all elements so far.
//
//
// Example:
//
// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3)
// findMedian() -> 2
//
// Follow up:
//
// 1. If all integer numbers from the stream are between 0 and 100, how would
// you optimize it?
// 2. If 99% of all integer numbers from the stream are between 0 and 100, how
// would you optimize it?

#ifndef LEETCODECPP_FINDMEDIANFROMDATASTREAM_H
#define LEETCODECPP_FINDMEDIANFROMDATASTREAM_H

#include <vector>

namespace lcpp {

class MedianFinder1 {
  std::vector<int> Data;

public:
  /** initialize your data structure here. */
  MedianFinder1() = default;

  void addNum(int num);

  double findMedian();
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

} // namespace lcpp

#endif // LEETCODECPP_FINDMEDIANFROMDATASTREAM_H
