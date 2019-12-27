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

void MedianFinder2::addNum(int num) {
  Small.push(num);
  Big.push(Small.top());
  Small.pop();
  if (Big.size() > Small.size()) {
    Small.push(Big.top());
    Big.pop();
  }
}

double MedianFinder2::findMedian() {
  if (Small.size() > Big.size())
    return Small.top();
  return (static_cast<double>(Small.top()) + Big.top()) / 2;
}
