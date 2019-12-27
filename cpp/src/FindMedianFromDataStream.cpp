#include "FindMedianFromDataStream.h"
#include <algorithm>

using namespace lcpp;

void MedianFinder1::addNum(int num) {
  Data.insert(std::lower_bound(Data.begin(), Data.end(), num), num);
}

double MedianFinder1::findMedian() {
  const auto &Size = Data.size();
  if (Size % 2 != 0)
    return Data[Size / 2];
  else
    return (static_cast<double>(Data[(Size / 2) - 1]) + Data[Size / 2]) / 2;
}
